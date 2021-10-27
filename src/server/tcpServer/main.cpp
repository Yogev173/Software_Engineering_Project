#include "TCPServer.h"

int main() {
    //creating the TCP server
    TCPServer tcpServer(TCPServer::DEFAULT_PORT);
    tcpServer.start();

    return 0;
}