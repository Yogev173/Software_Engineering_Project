#ifndef TEST_CLIENT_TEST_H
#define TEST_CLIENT_TEST_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

/**
 * @brief an interface to a socket of a server.
 * 
 */
class TestClient {
    int m_listeningSock;

public:
    static const int BACK_LOG = 5;
    static const int DEFAULT_PORT = 50001;//**************************************need to be like tcpServer
    /**
     * @brief Construct a new TCP server object
     * 
     * @param port port number for the server
     * @param classifiedPath the path to the classefied object.
     */
    TestClient(const int port);

    /**
     * @brief wait for a client, and then creating new TCP socket with him.
     * 
     */
    void listen();

    /**
     * @brief creating a new tcp socket to contact with the client.
     * 
     * @return int the new socket number.
     */
    int accept();

    /**
     * @brief close the server's socket.
     * 
     */
    void closeServer();
};

#endif //TEST_CLIENT_TEST_H