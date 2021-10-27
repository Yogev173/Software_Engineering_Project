#include "ClientClassifiedDataCommand.h"
#include <iostream>

ClientClassifiedDataCommand::ClientClassifiedDataCommand(DefaultIO* receiceIO,DefaultIO* writeIO,
std::string descreption): ClientCommand(receiceIO, descreption){
    m_writeIn = writeIO;
}

void ClientClassifiedDataCommand::exectute() {
    std::string line = m_io->receive();
    m_writeIn->send(line);
}