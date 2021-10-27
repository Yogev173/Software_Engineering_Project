#ifndef CLIENT_UPLOAD_COMMAND_H
#define CLIENT_UPLOAD_COMMAND_H
#include "../ClientCommand.h"
#include <iostream>
#include <fstream>

class ClientUploadCommand: public ClientCommand{
    private:

    public:
    /**
 * @brief sending file with the io of the objecr=t
 *
 * @param path the local path of a csv file
 */
    void sendFile(std::string path);

    /**
 * @brief Construct a new Command object
 *
 * @param io the input output object
 * @param description the description
 */
    ClientUploadCommand(DefaultIO* io, std::string description = "upload unclassified csv data file");


/**
 * @brief exectuting the command - sending 2 files(train and test) to the server
 */
    virtual void exectute() override;





};

#endif