#include "ClassifiedData.h"

/**
 * @brief add an type to the data vectors,
 * !it allocate it on the heap!
 * 
 * @param type the description of the new type.
 */
void ClassifiedData::addObject(std::string type) {
    m_types.push_back(new std::string(type));
}

/**
 * @brief free all allocated memory in the vector and initialize them.
 * 
 */
void ClassifiedData::deleteData() {
    //deleting the types
    for (auto type : m_types) {
        delete type;
    }

    m_types.clear();
}

/**
 * @brief Get the Types object
 * 
 * @return std::vector<std::string*> 
 */
std::vector<std::string*> ClassifiedData::getTypes() {
    return m_types;
}

/**
 * @brief Get the Types Options
 * 
 * @return std::vector<std::string> the types
 */
std::vector<std::string> ClassifiedData::getTypesOptions() {
    std::vector<std::string> typesOptions;
    bool counted;
    for (auto type : m_types) {
        //checking if it already in the vector
        counted = false;
        for (auto knownType : typesOptions) {
            counted = counted || (strcmp(knownType.c_str(), type->c_str()) == 0);
        }

        if (counted == false) {
            typesOptions.push_back(*type);
        }
    }

    return typesOptions;
}


/**
 * @brief Destroy the Classified Data object
 * 
 */
ClassifiedData::~ClassifiedData() {
    this->deleteData();
}

    /**
     * @brief send the classified data, one byone throw the io, at the end send a "end"
     * 
     * @param io the DefaultIO to send with.
     */
void ClassifiedData::sendData(DefaultIO* io) {
    int number = 1;
    std::string output = "";
    for (std::string* str : m_types){
        output += std::string(std::to_string(number) + std::string("\t") + *str + std::string("\n"));
        number++;
    }

    output = output.substr(0, output.length() - 1);
    io->send(output);
}