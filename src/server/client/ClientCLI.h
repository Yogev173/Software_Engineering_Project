#ifndef ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_CLIENT_CLI_H
#define ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_CLIENT_CLI_H

#include <vector>
#include "../IOS/DefaultIO.h"
#include "commands/ClientCommand.h"
#include <iostream>
#include <string>


#include "commands/clientUploadCommand/ClientUploadCommand.h"
#include "commands/clientSettingsCommand/ClientSettingsCommand.h"
#include "commands/clientClassifieCommand/ClientClassifieCommand.h"
#include "commands/clientClassifiedDataCommands/clientClassifiedDataPrintCommand/ClientClassifiedPrintCommand.h"
#include "commands/clientClassifiedDataCommands/clientClassifiedDataFileCommand/ClientClassifiedFileCommand.h"
#include "commands/clientConfusionMatrixCommand/ClientConfusionMatrixCommand.h"
#include "commands/clientExitCommand/ClientExitCommand.h"

class ClientCLI {
    DefaultIO* m_io;
    std::vector<ClientCommand*> m_commands;

    /**
     * @brief print the menu options
     * 
     */
    void printMenu();
public:

    /**
     * @brief Construct a new Client CLI object
     * 
     * @param io the input output object
     */
    ClientCLI(DefaultIO* io);

    /**
     * @brief start comuniceting with a server.
     * 
     */
    void start();

    /**
     * @brief Destroy the Client CLI object
     * 
     */
    ~ClientCLI();
};

#endif //ADVANCED_PROGRAMMINIG_1_SERVER_CLIENT_CLIENT_CLI_H