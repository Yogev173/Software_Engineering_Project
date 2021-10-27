#ifndef SERVER_IOS_SOCKET_IO__H
#define SERVER_IOS_SOCKET_IO__H

#include "DefaultIO.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
class SocketIO: public DefaultIO{
public:
    static const int BUFFER_SIZE = 4096;
    static constexpr char const THIS_COMPUTER_IP[] = {'1','2','7','.','0','.','0','.','1'};
private:
    int m_sock;

    /**
     * @brief send the massage in the buffer.
     * 
     * @param buffer massage to send.
     * @param bytes num of bytes to send
     */
    void send(char* buffer, int bytes);

    /**
     * @brief recive a massage from a client.
     * 
     * @param buffer hold the massage.
     * @param expectedDatdLength length of the string it expect to recv.
     * @return int num of bytes recv.
     */
    int receive(char* buffer, int expectedDatdLength);

public:

    /**
     * @brief Construct a new TCPSocket object
     * 
     * @param port port number for the socket
     */
    SocketIO(int sock);

    /**
     * @brief send the massage.
     * 
     * @param massage the massge to send.
     */
    void send(std::string massage) override;

    /**
     * @brief recive a massage from a client.
     * 
     * @return std::string the massage.
     */
    std::string receive() override;

    /**
     * @brief close the socket.
     * 
     */
    void close() override;
};

#endif //SERVER_IOS_SOCKET_IO__H