#include "ClientCommand.h"

/**
 * @brief Construct a new Command object
 *
 * @param io the input output object
 * @param description the command description
 */
ClientCommand::ClientCommand(DefaultIO* io, std::string description) {
    m_io = io;
    m_description = description;
}

/**
 * @brief Get the description object
 * 
 * @return std::string 
 */
std::string ClientCommand::getDisc() {
    return m_description;
}

/**
 * @brief Destroy the Client Command object
 * 
 */
ClientCommand::~ClientCommand() {

}