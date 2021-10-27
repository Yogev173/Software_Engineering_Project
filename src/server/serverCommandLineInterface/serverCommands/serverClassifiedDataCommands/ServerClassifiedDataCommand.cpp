#include "ServerClassifiedDataCommand.h"
#include <iostream>

ServerClassifiedDataCommand::ServerClassifiedDataCommand(DefaultIO* io, std::string description,
 Data* data) : Command(io,description){
     m_data = data;
}


void ServerClassifiedDataCommand::exectute(){
    if (m_data->getClassifiedData() == nullptr) {
        m_io->send("before displaying/downloading the result, a classifie is required. \n\n");
        return;
    } else {
        m_io->send("continue");
    }

    if(!m_data->getIsProccesing() && m_data->getClassifiedData() != m_data->getOldClassifiedData()) {
        delete m_data->getOldClassifiedData();
        m_data->setOLdClassifiedData(m_data->getClassifiedData());
    }

    m_data->getClassifiedData()->sendData(m_io);
}