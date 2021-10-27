#ifndef ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_COMMANDS_CLIENT_CONFUSION_MATRIX_COMMAND_H
#define ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_COMMANDS_CLIENT_CONFUSION_MATRIX_COMMAND_H


#include <string>
#include <iostream>
#include "../ClientCommand.h"

class ClientConfusionMatrixCommand : public ClientCommand{
public:

    /**
     * @brief Construct a new Client Command object
     *
     * @param io the input output object
     * @param description the command description
     */
    ClientConfusionMatrixCommand(DefaultIO* io, std::string description = "display algorithm confusion matrix");

    /**
     * @brief execute the command
     * 
     */
    void exectute() override;
};

#endif //ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_COMMANDS_CLIENT_CONFUSION_MATRIX_COMMAND_H