#include "ClientExitCommand.h"

/**
 * @brief Construct a new Exit Command object
 * 
 * @param io the input output object
 * @param description the command description
 */
ClientExitCommand::ClientExitCommand(DefaultIO* io, std::string description) : ClientCommand(io, description) {

}

/**
 * @brief execute the command
 * 
 */
void ClientExitCommand::exectute() {
    std::cout << "exit" << std::endl;
}