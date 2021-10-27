#ifndef ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SERVER_CLI_H
#define ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SERVER_CLI_H

#include "../IOS/DefaultIO.h"
#include "data/Data.h"
#include "settings/Settings.h"
#include <vector>
#include "serverCommands/Command.h"

#include "serverCommands/uploadDataCommand/UploadCommand.h"
#include "serverCommands/settingsCommand/SettingCommand.h"
#include "serverCommands/classifieComand/ClassifieCommand.h"
#include "serverCommands/serverClassifiedDataCommands/ServerClassifiedDataCommand.h"
#include "serverCommands/confusionMatrixCommand/ConfusionMatrixCommand.h"
#include "serverCommands/exitCommand/ExitCommand.h"

class ServerCLI {
    DefaultIO* m_io;
    Data m_data;
    Settings m_settings;
    std::vector<Command*> m_commands;
public:

    /**
     * @brief Construct a new Server CLI object
     * 
     * @param io the input output object
     */
    ServerCLI(DefaultIO* io);

    /**
     * @brief start comuniceting with a client.
     * 
     */
    void start();

    /**
     * @brief Destroy the Server CLI object
     * 
     */
    ~ServerCLI();
};

#endif //ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SERVER_CLI_H