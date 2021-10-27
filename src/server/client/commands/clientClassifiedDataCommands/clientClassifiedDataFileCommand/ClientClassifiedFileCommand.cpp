#include "ClientClassifiedFileCommand.h"

ClientClassifiedFileCommand::ClientClassifiedFileCommand(DefaultIO* io,
 std::string description) : ClientCommand(io,description) {}

void ClientClassifiedFileCommand::exectute(){
    std::string status = m_io->receive();
    if (status.compare("continue") != 0) {
        std::cout << status << std::endl;
        return;
    }

    //getting the file path.
    std::cout << "pls enter a local CSV path" << std::endl;
    std::string path;
    std::cin >> path;
    //creating the command that upload the data
    DefaultIO* fileIO =  new CsvFileIO(path);
    m_command = new ClientClassifiedDataCommand(m_io, fileIO, this->getDisc());
    m_command->exectute();
    fileIO->close();
    delete fileIO;
    delete m_command;
    m_command = nullptr;
 }
