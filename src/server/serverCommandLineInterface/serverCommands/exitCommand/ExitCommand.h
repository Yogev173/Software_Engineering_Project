#ifndef SERVER_SERVER_COMMANDS_EXIT_COMMAND_EXIT_COMMAND__H
#define SERVER_SERVER_COMMANDS_EXIT_COMMAND_EXIT_COMMAND__H

#include <string>
#include "../Command.h"
class ExitCommand : public Command{
public:
    /**
     * @brief Construct a new Exit Command object
     * 
     * @param io the input output object
     * @param description the command description
     */
    ExitCommand(DefaultIO* io, std::string description = "exit");

    /**
     * @brief execute the command
     * 
     */
    void exectute() override;
};

#endif //SERVER_SERVER_COMMANDS_CONFUSION_MATRIX_COMAND_CONFUSION_MATRIX_COMMAND__H