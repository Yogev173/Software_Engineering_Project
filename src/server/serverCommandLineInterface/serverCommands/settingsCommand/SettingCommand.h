#ifndef ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SERVER_COMMANDS_SETTINGS_COMMAND_H
#define ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SERVER_COMMANDS_SETTINGS_COMMAND_H

#include <string>
#include <cstring>
#include "../../../IOS/DefaultIO.h"
#include "../Command.h"
#include "../../settings/Settings.h"
#include "../../data/Data.h"

class SettingCommand : public Command {
private:
    Settings* m_settings;
    Data* m_data;

    bool isInputValid(std::string input);

    void perseInput(std::string& type, int& k, std::string input);

    void scanInput(std:: string& type, int& k);
public:

    SettingCommand(Settings* settings, Data* data, DefaultIO* io, std::string description = "algorithm settings");

    void exectute() override;
};

#endif //ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SERVER_COMMANDS_SETTINGS_COMMAND_H