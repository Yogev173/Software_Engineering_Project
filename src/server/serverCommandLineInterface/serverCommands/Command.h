#ifndef ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SERVER_COMMANDS_COMMAND_H
#define ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SERVER_COMMANDS_COMMAND_H

#include <string>
#include "../../IOS/DefaultIO.h"
class Command {
private:
    std::string m_description;
    
protected:
    DefaultIO* m_io;

public:
    /**
     * @brief Construct a new Command object
     *
     * @param io the input output object
     * @param description the command description
     */
    Command(DefaultIO* io, std::string description);

    /**
     * @brief execute the command
     * 
     */
    virtual void exectute() = 0;

    /**
     * @brief print the description of the command
     * 
     */
    void printDisc();

    /**
     * @brief Get the Disc object
     * 
     * @return std::string 
     */
    std::string getDisc();

    /**
     * @brief Destroy the Command object
     * 
     */
    virtual ~Command();
};

#endif //ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SERVER_COMMANDS_COMMAND_H