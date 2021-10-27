#include "UploadCommand.h"
#include <iostream>

UploadCommand::UploadCommand(Data* data, DefaultIO* io, std::string descreption)
 : Command(io, descreption) {
     m_data = data;
}

void UploadCommand::exectute(){
    if (m_data->getIsProccesing()) {
        m_io->send("unable to upload data while classifing, please wait and than try again.");
        return;
    } else {
        m_io->send("continue");
    }

    //deleting previous data.
    this->deleteData();
    std::cout << "" << std::endl;
    //getting train data objects
    m_io->send(std::string("please upload your local train CSV file. \n"));
    
    std::string input = "";
    std::string endString("send all data");
    while ((input = m_io->receive()).compare(endString)) {
        m_data->addTrainData(input);
        m_io->send("gotData");
    }
    m_io->send(std::string("Upload complete."));
    //getting test data objects.
    m_io->send(std::string("please upload your local test CSV file. \n"));
    input = "";
    while ((input = m_io->receive()).compare(endString)) {
        m_data->addTestData(input);
        m_io->send("gotData");
    }
    m_io->send(std::string("Upload complete."));
}


void UploadCommand::deleteData(){
    //deleting the data.
    m_data->deleteTrainFile();
    m_data->deleteTestFile();
}

Data* UploadCommand::getData(){
    return m_data;
}