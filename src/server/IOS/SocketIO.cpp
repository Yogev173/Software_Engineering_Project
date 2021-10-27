#include "SocketIO.h"
#include <iostream>

/**
 * @brief Construct a new TCPSocket object
 * 
 * @param port port number for the socket
 */
SocketIO::SocketIO(int sock) {
    m_sock = sock;
}

/**
 * @brief send the massage.
 * 
 * @param massage the massge to send.
 */
void SocketIO::send(std::string massage) {
    int n = massage.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    std::strcpy(char_array, massage.c_str());
    this->send(char_array, sizeof(char_array));
}

/**
 * @brief send the massage in the buffer.
 * 
 * @param buffer massage to send.
 * @param bytes num of bytes to send
 */
void SocketIO::send(char* buffer, int bytes) {
    // sending the data.
    int sent_bytes = ::send(m_sock, buffer, bytes, 0);
    // checking if an error accurred.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}

/**
 * @brief recive a massage from a client.
 * 
 * @return std::string the massage.
 */
std::string SocketIO::receive() {
    //recv themassage.
    char buffer[SocketIO::BUFFER_SIZE];
    this->receive(buffer, SocketIO::BUFFER_SIZE);
    std::string stringBuffer = buffer;
    
    return stringBuffer;
}

/**
 * @brief receive a massage from a client.
 * 
 * @param buffer hold the massage.
 * @param expectedDatdLength length of the string it expect to recv.
 * @return int num of bytes recv.
 */
int SocketIO::receive(char* buffer, int expectedDatdLength) {
    // receving the data.
    int read_bytes = recv(m_sock, buffer, expectedDatdLength, 0);
    // checking if the connection is closed.
    if (read_bytes == 0) {
        return 0;
    }
    // checking if an error accurred.
    else if (read_bytes < 0) {
        perror("error reading from socket-TCP");
    }
    return read_bytes;
}

/**
 * @brief close the socket.
 * 
 */
void SocketIO::close() {
    ::close(m_sock);
}