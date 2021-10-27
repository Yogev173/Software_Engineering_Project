#include "ClientSettingsCommand.h"

ClientSettingsCommand::ClientSettingsCommand(DefaultIO* io, std::string description) : 
    ClientCommand(io,description) {}


void ClientSettingsCommand::exectute(){
    std::string status = m_io->receive();
    if (status.compare("continue") != 0) {
        std::cout << status << std::endl;
        return;
    }

    std::cout << m_io->receive();
    std::string toSendK, toSendMetric;
    std::cin >> toSendK >> toSendMetric;
    m_io->send(toSendK + std::string(" ") + toSendMetric);

    std::string toPrint(m_io->receive());
    while (toPrint.compare("updated values.") != 0) {
        std::cout << toPrint << std::endl;
        std::cin >> toSendK >> toSendMetric;
        m_io->send(toSendK + std::string(" ") + toSendMetric);
        toPrint = m_io->receive();
    }
}