#include "ClientIO.h"
#include "../IOS/SocketIO.h"

/**
 * @brief Construct a new Tcp Client:: Tcp Client object
 * 
 * @param ip_address ip address to connect to.
 * @param port port to connect to.
 */
ClientIO::ClientIO(const char* ip_address, int port) {
    //getting a socket and checking if an error accurred.
    m_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (m_sock < 0) {
        perror("error creating socket");
    }

    //conecting to the server.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);
    //checking if the connection failed.
    if (connect(m_sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
}

/**
 * @brief send the massage in the buffer.
 * 
 * @param buffer massage to send.
 * @param bytes num of bytes to send
 */
void ClientIO::send(char* buffer, int bytes) {
    //sending the data
    int sent_bytes = ::send(m_sock, buffer, bytes, 0);
    //checking if the send worked
    if (sent_bytes < 0) {
        perror("error sending to server");
    }
}

/**
 * @brief receive a massage from a client.
 * 
 * @param buffer hold the massage.
 * @param expectedDatdLength length of the string it expect to recv.
 * @return int num of bytes recv.
 */
int ClientIO::receive(char* buffer, int expectedDatdLength) {
    //receiving thr data
    int read_bytes = recv(m_sock, buffer, expectedDatdLength, 0);
    if (read_bytes == 0) {
        // connection is closed
        this->~ClientIO();
    } // checking if an error accurred.
    else if (read_bytes < 0) {
        perror("error reading from socket-TCP");
    }
    return read_bytes;
}
/**
 * @brief Destroy the Client I O object
 * 
 */
ClientIO::~ClientIO() {
    ::close(m_sock);
}

/**
 * @brief recive a massage from a client.
 * 
 * @return std::string the massage.
 */
std::string ClientIO::receive() {
    //recv themassage.
    char buffer[SocketIO::BUFFER_SIZE];
    this->receive(buffer, SocketIO::BUFFER_SIZE);
    std::string stringBuffer = buffer;
    
    return stringBuffer;
}

/**
 * @brief send the massage.
 * 
 * @param massage the massge to send.
 */
void ClientIO::send(std::string massage) {
       int n = massage.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    std::strcpy(char_array, massage.c_str());
    this->send(char_array, sizeof(char_array));
}

void ClientIO::close() {
    
}