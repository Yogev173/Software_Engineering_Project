#ifndef UPLOAD_COMMAND_H
#define UPLOAD_COMMAND_H
#include "../Command.h"
#include "../../data/Data.h"
#include "../../data/DataFile.h"
#include "../../data/ClassifiedData.h"

class UploadCommand : public Command{
    private:
    Data* m_data;

    public:
    /**
 * @brief Construct a new Command object
 *
 * @param io the input output object
 * @param data the data of the command
 * @param descreption the descreption of the command we print to the menu
 */
    UploadCommand(Data* data, DefaultIO* io, std::string descreption = "upload unclassified csv data file");

    /**
 * @brief getter to the data of the command
 */
    Data* getData();

    /**
 * @brief deleting existing data of the command
 */
    void deleteData();

    /**
 * @brief exectuting the command - uploading 2 files from client and saving the data.
 */
    virtual void exectute() override;
};


#endif