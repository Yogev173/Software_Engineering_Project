#include "ClientClassifiedPrintCommand.h"

ClientClassifiedPrintCommand::ClientClassifiedPrintCommand(DefaultIO* io, std::string description) : ClientCommand(io,description) {
    m_userIo = new StandardIO();
    m_command = new ClientClassifiedDataCommand(io, m_userIo, description);
}


void ClientClassifiedPrintCommand::exectute() {  
    std::string status = m_io->receive();
    if (status.compare("continue") != 0) {
        std::cout << status << std::endl;
        return;
    }

    m_command->exectute();
}

ClientClassifiedPrintCommand::~ClientClassifiedPrintCommand(){
    delete m_command;
    delete m_userIo;
}