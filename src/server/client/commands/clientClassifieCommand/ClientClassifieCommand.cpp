#include "ClientClassifieCommand.h"

/**
 * @brief Construct a new Client Command object
 *
 * @param io the input output object
 * @param description the command description
 */
ClientClassifieCommand::ClientClassifieCommand(DefaultIO* io, std::string description) : ClientCommand(io, description) {
    
}

/**
 * @brief execute the command
 * 
 */
void ClientClassifieCommand::exectute() {
    std::cout << m_io->receive() << std::endl;
}