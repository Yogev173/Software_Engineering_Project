#ifndef SERVER_TCP_SERVER_TCP_SERVER_H
#define SERVER_TCP_SERVER_TCP_SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "../IOS/SocketIO.h"
#include "../serverCommandLineInterface/ServerCLI.h"
#include "ThreadList.h"
/**
 * @brief an interface to a socket of a server.
 * 
 */
class TCPServer {
private:
    int m_listeningSock;
    ThreadList m_threads;
protected:
    /**
     * @brief creating a new tcp socket to contact with the client.
     * 
     * @return int the new socket number.
     */
    int accept();
public:
    static const int BACK_LOG = 5;
    static const int DEFAULT_PORT = 50000;
    /**
     * @brief Construct a new TCP server object
     * 
     * @param port port number for the server
     * @param classifiedPath the path to the classefied object.
     */
    TCPServer(const int port);

    /**
     * @brief start the server
     * 
     */
    void start();

    /**
     * @brief start a connection with a client
     * 
     * @param param nullptr
     */
    static void* runner(void* param);

    /**
     * @brief Destroy the TCPServer object
     * 
     */
    ~TCPServer();
};

#endif //SERVER_TCP_SERVER_TCP_SERVER_H