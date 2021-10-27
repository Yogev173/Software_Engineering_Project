#ifndef ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_COMMANDS_CLIENT_CLASSIFIE_COMMAND_H
#define ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_COMMANDS_CLIENT_CLASSIFIE_COMMAND_H


#include <string>
#include <iostream>
#include "../ClientCommand.h"


class ClientClassifieCommand : public ClientCommand{
public:
    /**
     * @brief Construct a new Client Command object
     *
     * @param io the input output object
     * @param description the command description
     */
    ClientClassifieCommand(DefaultIO* io, std::string description = "classify data");

    /**
     * @brief execute the command
     * 
     */
    void exectute() override;
};

#endif //ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_COMMANDS_CLIENT_CLASSIFIE_COMMAND_H