#ifndef CLIENT_SETTINGS_COMMAND_H
#define CLIENT_SETTINGS_COMMAND_H

#include "../ClientCommand.h"
#include <iostream>

class ClientSettingsCommand : public ClientCommand{
    private:

    public:
    ClientSettingsCommand(DefaultIO* io, std::string description = "algorithm settings");

    virtual void exectute();

};

#endif //CLIENT_SETTINGS_COMMAND_H