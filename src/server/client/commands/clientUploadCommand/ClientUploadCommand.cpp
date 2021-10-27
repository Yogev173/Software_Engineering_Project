#include "ClientUploadCommand.h"

ClientUploadCommand::ClientUploadCommand(DefaultIO* io, std::string description) : ClientCommand(io, description) {}

void ClientUploadCommand::exectute(){
    std::string status = m_io->receive();
    if (status.compare("continue") != 0) {
        std::cout << status << std::endl;
        return;
    }

    //printing the server message.
    std::cout << m_io->receive();
    //sending train file
    std::string path;
    std::cin >> path;
    sendFile(path);
    //sending test file
    std::cout << m_io->receive();
    std::cout << m_io->receive();
    std::cin >> path;
    sendFile(path);
    std::cout << m_io->receive()  << std::endl  << std::endl;
}

void ClientUploadCommand::sendFile(std::string path){
    //sending the file line by line.
    std::string line;
    std::ifstream fileRead(path);
    while ((fileRead >> line)) {
        m_io->send(line);
        m_io->receive();
    }
    fileRead.close();
    m_io->send("send all data");
}