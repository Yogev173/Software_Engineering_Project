#include "SettingCommand.h"
#include <iostream>

SettingCommand::SettingCommand(Settings* settings, Data* data, DefaultIO* io, std::string description) : Command(io, description) {
    m_settings = settings;
    m_data = data;
}

void SettingCommand::perseInput(std::string& type, int& k, std::string input){
    //the k is the string before the space, the type is the string after.
    k = std::stoi(input.substr(0, input.find_first_of(' ')));
    type = input.substr(input.find_first_of(' ') + 1,std::string::npos);
}

bool SettingCommand::isInputValid(std::string input){
    //checking if there is exactly 1 space.
    if (input.find(' ') == std::string::npos || input.find_first_of(' ') != input.find_last_of(' ')) {
        return false;
    }
    //trying to perse the first part of the string to int.
    int k;
    try {
        k = std::stoi(input.substr(0, input.find_first_of(' ')));
    }
    catch(const std::exception& e){
        m_io->send(std::string("Invalid value for K, pls enter a valid value (a number between 1 to 10)"));
        return false;
    }

    if (k < 1 || k > 10) {
        m_io->send(std::string("Invalid value for K, pls enter a valid value (a number between 1 to 10)"));
        return false;
    }

    //checking if the metric type is valid.
    std::string type = input.substr(input.find_first_of(' ') + 1);
    if(type.compare("CHE") != 0 && type.compare("MAN") != 0 && type.compare("EUC") != 0){
        m_io->send("Invalid value for the metric type, pls enter a valid input");
        return false;
    }
    return true;
}

void SettingCommand::scanInput(std::string& type, int& k){
    //scanning the inpit.
    std::string input = m_io->receive();
    //if the client clicked enter we leave the values as they are
    if (input.compare("save settings") == 0) {
        type = m_settings->getMetricType();
        k = m_settings->getK();
        return;
    }
    //scanning until the values are valid, then persing them.
    while (!isInputValid(input)) {
        input = m_io->receive();
    }
    perseInput(type,k,input);
}


void SettingCommand::exectute(){
    if (m_data->getIsProccesing()) {
        m_io->send("unable to change settings while classifing, please wait and than try again.");
        return;
    } else {
        m_io->send("continue");
    }


    //printing the current values.
    m_io->send("The current KNN setting are: k = " + std::to_string(m_settings->getK()) + " distance metric = " + m_settings->getMetricType() + "\n" + "to sava current settings type 'save settings'\n");
    //the new values.
    int newK;
    std::string type;
    //scanning values from client.
    scanInput(type,newK);
    //updaiting the values.
    m_settings->setValues(newK,&type);
    m_io->send("updated values.");
}