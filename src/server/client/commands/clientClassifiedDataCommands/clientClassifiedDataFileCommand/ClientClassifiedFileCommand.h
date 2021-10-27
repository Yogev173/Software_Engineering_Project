#ifndef CLIENT_CLASSIFIED_FILE_COMMAND_H
#define CLIENT_CLASSIFIED_FILE_COMMAND_H

#include "../../ClientCommand.h"
#include "../ClientClassifiedDataCommand.h"
#include "../../../../IOS/CsvFileIO.h"
#include <thread>
#include <iostream>

class ClientClassifiedFileCommand : public ClientCommand{
    private:

    ClientClassifiedDataCommand* m_command;
    public:

/**
     * @brief a command cunstroctur.
     */
    ClientClassifiedFileCommand(DefaultIO* io, std::string description  = "download results");

/**
     * @brief get the file path from client and create a new thread to upload the file.
     */
    virtual void exectute();



};

#endif //CLIENT_CLASSIFIED_FILE_COMMAND_H
