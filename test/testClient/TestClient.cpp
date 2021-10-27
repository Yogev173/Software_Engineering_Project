#include "TestClient.h"
#include "../../src/server/IOS/SocketIO.h"
#include "../../src/server/serverCommandLineInterface/ServerCLI.h"

/**
 * @brief Construct a new TCP server object
 * 
 * @param port port number for the server
 */
TestClient::TestClient(const int port) {
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
void TestClient::listen() {
    //waiting fo r client
    if (::listen(m_listeningSock, TestClient::BACK_LOG) < 0) {
        perror("error listening to a socket");
    }
}

/**
 * @brief creating a new tcp socket to contact with the client.
 * 
 * @return int the new socket number.
 */
int TestClient::accept() {
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

/**
 * @brief close the server's socket.
 * 
 */
void TestClient::closeServer() {
    ::close(m_listeningSock);
}