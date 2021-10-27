#include "../../src/server/client/ClientIO.h"
#include "../../src/server/tcpServer/TCPServer.h"
#include "../../src/server/client/ClientCLI.h"

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