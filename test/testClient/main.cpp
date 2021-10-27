#include "TestClient.h"
#include "../../src/server/IOS/SocketIO.h"
#include "string"
#include "../../src/server/serverCommandLineInterface/ServerCLI.h"


int main() {
    //creating the TCP server
    TestClient tcpServer(TestClient::DEFAULT_PORT);
    tcpServer.listen();
    int clientSock = tcpServer.accept();
    SocketIO socketIO(clientSock);

    socketIO.send(std::string("1"));
    std::cout << socketIO.receive() << std::endl;
    
    socketIO.send(std::string("2"));
    std::cout << socketIO.receive() << std::endl;
    
    socketIO.send(std::string("3"));
    std::cout << socketIO.receive() << std::endl;
    
    socketIO.send(std::string("4"));
    std::cout << socketIO.receive() << std::endl;

    socketIO.send(std::string("5"));
    std::cout << socketIO.receive() << std::endl;
    
    socketIO.send(std::string("6"));
    std::cout << socketIO.receive() << std::endl;
    
    socketIO.send(std::string("7"));
    std::cout << socketIO.receive() << std::endl;

    std::cout << socketIO.receive() << std::endl;
    socketIO.send(std::string("upload"));

    // ServerCLI serverCLI(&socketIO);
    // serverCLI.start();
    //closing the socket
    socketIO.close();
    tcpServer.closeServer();
    return 0;
}