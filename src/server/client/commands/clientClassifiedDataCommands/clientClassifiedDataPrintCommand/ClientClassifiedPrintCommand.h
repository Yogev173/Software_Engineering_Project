#ifndef CLIENT_CLASSIFIED_PRINT_COMMAND_H
#define CLIENT_CLASSIFIED_PRINT_COMMAND_H

#include "../../ClientCommand.h"
#include "../ClientClassifiedDataCommand.h"
#include "../../../../IOS/StandrardIO.h"
#include "../../../../IOS/DefaultIO.h"
#include <iostream>

class ClientClassifiedPrintCommand : public ClientCommand {

    private:
    ClientClassifiedDataCommand* m_command;
    DefaultIO* m_userIo;

    public:

    ClientClassifiedPrintCommand(DefaultIO* io, std::string description = "display results");

    virtual void exectute();

    ~ClientClassifiedPrintCommand();


};



#endif //CLIENT_CLASSIFIED_PRINT_COMMAND_H