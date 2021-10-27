#include "ClientIO.h"
#include "../tcpServer/TCPServer.h"
#include "ClientCLI.h"

int main() {
    //the IP we work on in this ex
    const char* ip_address = "127.0.0.1";

    //connecting to the server
    ClientIO io(ip_address, TCPServer::DEFAULT_PORT);

    //start the CLI
    ClientCLI clientCLI(&io);
    clientCLI.start();
    return 0;
}