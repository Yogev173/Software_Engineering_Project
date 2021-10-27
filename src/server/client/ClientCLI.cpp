#include "ClientCLI.h"

/**
 * @brief print the menu options
 * 
 */
void ClientCLI::printMenu() {    
    std::string menu = "";
    int num = 0;
    for (ClientCommand* command : m_commands) {
        menu += std::to_string(num) + ". " + command->getDisc() + "\n";
        num ++;  
    }
    std::cout << menu;
}

/**
 * @brief Construct a new Client CLI object
 * 
 * @param io the input output object
 */
ClientCLI::ClientCLI(DefaultIO* io) {
    m_io = io;
    m_commands.push_back(new ClientUploadCommand(m_io));
    m_commands.push_back(new ClientSettingsCommand(m_io));
    m_commands.push_back(new ClientClassifieCommand(m_io));
    m_commands.push_back(new ClientClassifiedPrintCommand(m_io));
    m_commands.push_back(new ClientClassifiedFileCommand(m_io));
    m_commands.push_back(new ClientConfusionMatrixCommand(m_io));
    m_commands.push_back(new ClientExitCommand(m_io));
}

/**
 * @brief start comuniceting with a server.
 * 
 */
void ClientCLI::start() {
    std::string exit = "exit";
    std::string command = "";
    int commandIndex = 0;
    int toCuntiue = 1;
    while (toCuntiue != 0) {
        this->printMenu();
        
        //sending to server the command to execute5
        std::cin >> command;
        m_io->send(command);
        
        int commandIndex = atoi(command.c_str());
        m_commands[commandIndex]->exectute();
        toCuntiue = m_commands[commandIndex]->getDisc().compare(exit);
     }
}

/**
 * @brief Destroy the Client CLI object
 * 
 */
ClientCLI::~ClientCLI() {
    for (ClientCommand* command : m_commands) {
        delete command;
    }
}