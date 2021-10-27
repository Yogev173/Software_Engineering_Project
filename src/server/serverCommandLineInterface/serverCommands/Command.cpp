#include "Command.h"

/**
 * @brief Construct a new Command object
 *
 * @param io the input output object
 * @param description the command description
 */
Command::Command(DefaultIO* io, std::string str) {
    m_description = str;
    m_io = io;
}

/**
 * @brief print the description of the command
 * 
 */
void Command::printDisc(){
    m_io->send(m_description);
}

/**
 * @brief Get the Disc object
 * 
 * @return std::string 
 */
std::string Command::getDisc() {
    return m_description;
}


/**
 * @brief Destroy the Command object
 * 
 */
Command::~Command() {
    
}