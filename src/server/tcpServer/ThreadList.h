#ifndef SERVER_TCP_SERVER_TCP_THREAD_LIST_H
#define SERVER_TCP_SERVER_TCP_THREAD_LIST_H

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
#include <vector>
#include <algorithm>

/**
 * @brief an interface to a socket of a server.
 * 
 */
class ThreadList {
private:
    std::vector<pthread_t> m_threadID;
    
public:
    /**
     * @brief add a socket
     * 
     * @param threadID the id
     */
    void add(pthread_t threadID);

    /**
     * @brief remove a socket
     * 
     * @param threadID the id
     */
    void remove(pthread_t threadID);

    /**
     * @brief Get the thread object
     * 
     * @return std::vector<int> the vector
     */
    std::vector<pthread_t> getThreads();
};

#endif //SERVER_TCP_SERVER_TCP_THREAD_LIST_H