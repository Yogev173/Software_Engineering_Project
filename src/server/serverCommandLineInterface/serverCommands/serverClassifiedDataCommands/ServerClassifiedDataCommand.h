#ifndef SERVER_CLASSIFIED_DATA_COMMAND_H
#define SERVER_CLASSIFIED_DATA_COMMAND_H

#include "../Command.h"
#include "../../data/Data.h"

class ServerClassifiedDataCommand : public Command{
    private:
    Data* m_data;
    public:
    ServerClassifiedDataCommand(DefaultIO* io, std::string description, Data* data);

    virtual void exectute();
};




#endif //SERVER_CLASSIFIED_DATA_COMMAND_H