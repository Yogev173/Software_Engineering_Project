#ifndef CLIENT_CLASSIFIED_DATA_COMMAND_H
#define CLIENT_CLASSIFIED_DATA_COMMAND_H

#include "../ClientCommand.h"

class ClientClassifiedDataCommand : public ClientCommand{
    private:

    DefaultIO* m_writeIn;

    public:
    ClientClassifiedDataCommand(DefaultIO* reciveIO,DefaultIO* writeIO, std::string descreption);

    virtual void exectute();
};






#endif