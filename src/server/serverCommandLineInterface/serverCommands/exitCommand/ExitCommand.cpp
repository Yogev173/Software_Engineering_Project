#include "ExitCommand.h"

/**
 * @brief Construct a new Exit Command object
 * 
 * @param io the input output object
 * @param description the command description
 */
ExitCommand::ExitCommand(DefaultIO* io, std::string description) : Command( io,  description){

}

/**
 * @brief execute the command
 * 
 */
void ExitCommand::exectute() {
    
}