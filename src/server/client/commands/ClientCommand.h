#ifndef ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_COMMANDS_CLIENT_COMMAND_H
#define ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_COMMANDS_CLIENT_COMMAND_H


#include <string>
#include "../../IOS/DefaultIO.h"
class ClientCommand {
private:
    std::string m_description;
    
protected:
    DefaultIO* m_io;

public:
    /**
     * @brief Construct a new Client Command object
     *
     * @param io the input output object
     * @param description the command description
     */
    ClientCommand(DefaultIO* io, std::string description);

    /**
     * @brief execute the command
     * 
     */
    virtual void exectute() = 0;

    /**
     * @brief Get the description object
     * 
     * @return std::string 
     */
    std::string getDisc();

    /**
     * @brief Destroy the Client Command object
     * 
     */
    virtual ~ClientCommand();
};

#endif //ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_COMMANDS_CLIENT_COMMAND_H