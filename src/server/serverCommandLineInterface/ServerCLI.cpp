#include "ServerCLI.h"
#include <iostream>

/**
 * @brief Construct a new Server CLI object
 * 
 * @param io the input output object
 */
ServerCLI::ServerCLI(DefaultIO* io) {
    m_io = io;
    m_commands.push_back(new UploadCommand(&m_data, m_io));
    m_commands.push_back(new SettingCommand(&m_settings, &m_data, m_io));
    m_commands.push_back(new ClassifieCommand(&m_data, &m_settings, m_io));
    m_commands.push_back(new ServerClassifiedDataCommand(m_io, "display results", &m_data));
    m_commands.push_back(new ServerClassifiedDataCommand(m_io, "download results", &m_data));
    m_commands.push_back(new ConfusionMatrixCommand(&m_data, &m_settings, m_io));
    m_commands.push_back(new ExitCommand(m_io));
}

/**
 * @brief start comuniceting with a client.
 * 
 */
void ServerCLI::start() {
    int commandIndex = 0;
    std::string exit = "exit";
    std::string command = "";

    while (m_commands[commandIndex]->getDisc().compare(exit)) {
        command = m_io->receive();
        commandIndex = atoi(command.c_str());
        m_commands[commandIndex]->exectute();
    }
}

/**
 * @brief Destroy the Server CLI object
 * 
 */
ServerCLI::~ServerCLI() {
    while (m_data.getIsProccesing());

    for (Command* command : m_commands) {
        delete command;
    }
}