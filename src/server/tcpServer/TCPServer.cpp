#include "TCPServer.h"

/**
 * @brief Construct a new TCP server object
 * 
 * @param port port number for the server
 */
TCPServer::TCPServer(const int port) {
    //creating socket
    m_listeningSock = socket(AF_INET, SOCK_STREAM, 0);
    if (m_listeningSock < 0) {
        perror("error creating socket");
    }

    //bindig the socket to a port
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
    // binding and checking if an error accurred.
    if (bind(m_listeningSock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
}

/**
 * @brief wait for a client, and then creating new TCP socket with him.
 * 
 */
void TCPServer::start() {
    //waiting for client
    if (::listen(m_listeningSock, TCPServer::BACK_LOG) < 0) {
        perror("error listening to a socket");
    }

    bool timeout = false;
    while (!timeout) {
        int clientSock = this->accept();
        if (clientSock == -1) {
            //timeout
            timeout = true;
        } else {
            this->openThread(clientSock);
        }
    }
}

/**
 * @brief creating a new tcp socket to contact with the client.
 * 
 * @return int the new socket number.
 */
int TCPServer::accept() {
    struct timeval tv;
    struct sockaddr_in client_sin;
    memset(&tv, 0, sizeof(tv));
    //Time out setting (in second)
    tv.tv_sec = 30;

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(m_listeningSock, &readfds);

    if (select(m_listeningSock + 1, &readfds, NULL, NULL, &tv) < 0) {
        perror("select error");
    }

    if (FD_ISSET(m_listeningSock, &readfds)) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        //creating a new tcp socket to contact with the client 
        int client_sock = ::accept(m_listeningSock, (struct sockaddr *) &client_sin, &addr_len);
        // checking if an error accurred.
        if (client_sock < 0) {
            perror("error accepting client");
        }

        return client_sock;
    }

    //in case of timeout
    return -1;
}

/**
 * @brief open thread to handale the client.
 * 
 * @param clientSock the socket id to comunicet with the client.
 */
void TCPServer::openThread(int clientSock) {
    std::vector<void*>* param = new std::vector<void*>();
    param->push_back(new int(clientSock));
    param->push_back(&m_threads);

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, TCPServer::runner, param);
    m_threads.add(tid);
}

/**
 * @brief close the server's socket.
 * 
 */
TCPServer::~TCPServer() {
    ::close(m_listeningSock);
    for (auto threadID : m_threads.getThreads()) {
        pthread_join(threadID, NULL);
    }
}


/**
 * @brief start a connection with a client
 * 
 * @param param nullptr
 */
void* TCPServer::runner(void* param) {
    std::vector<void*>* vec = static_cast<std::vector<void*>*>(param);
    int* clientSock = static_cast<int*>((*vec)[0]);
    ThreadList *threads = static_cast<ThreadList*>((*vec)[1]);
    vec->pop_back();

    SocketIO socketIO(*clientSock);
    ServerCLI* serverCLI = new ServerCLI(&socketIO);
    serverCLI->start();
    socketIO.close();
    threads->remove(pthread_self());

    delete serverCLI;
    delete clientSock;
    delete vec;

    pthread_exit(0);
    return nullptr;
}