#include "ClientConfusionMatrixCommand.h"

/**
 * @brief Construct a new Client Command object
 *
 * @param io the input output object
 * @param description the command description
 */
ClientConfusionMatrixCommand::ClientConfusionMatrixCommand(DefaultIO* io, std::string description) : ClientCommand(io, description) {

}

/**
 * @brief execute the command
 */
void ClientConfusionMatrixCommand::exectute()  {
    std::cout << m_io->receive() << std::endl;
}