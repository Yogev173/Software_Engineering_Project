#ifndef ADVANCED_PROGRAMMINIG_1_TCPCLIENT_H
#define ADVANCED_PROGRAMMINIG_1_TCPCLIENT_H

#include "../IOS/DefaultIO.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h> 
class ClientIO : public DefaultIO {
    int m_sock;

public:
    /**
     * @brief Construct a new Tcp Client:: ClientIO object
     * 
     * @param ip_address ip address to connect to.
     * @param port port to connect to.
     */
    ClientIO(const char* ip_address, int port);

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
     * @brief send the massage in the buffer.
     * 
     * @param buffer massage to send.
     * @param bytes num of bytes to send
     */
    void send(char* buffer, int bytes);

    /**
     * @brief receive a massage from a client.
     * 
     * @param buffer hold the massage.
     * @param expectedDatdLength length of the string it expect to recv.
     * @return int num of bytes recv.
     */
    int receive(char* buffer, int expectedDatdLength);

    /**
     * @brief 
     * 
     */
    void close();
    
    /**
     * @brief Destroy the Client I O object
     * 
     */
    ~ClientIO();
};

#endif //ADVANCED_PROGRAMMINIG_1_TCPCLIENT_H
