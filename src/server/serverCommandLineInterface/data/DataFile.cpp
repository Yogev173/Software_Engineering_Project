#include "DataFile.h"

/**
 * @brief add an object to the datas vectors,
 * !it allocate it on the heap!
 * 
 * @param coordinateAndType the description of the new object.
 */
void DataFile::addObject(std::string coordinateAndType) {
    int lastComma = coordinateAndType.find_last_of(',');
    std::string type = coordinateAndType.substr(lastComma + 1);
    std::string coordinates = coordinateAndType.erase(lastComma);
    
    m_coordinates.push_back(new std::string(coordinates));
    m_types.push_back(new std::string(type));
}

/**
 * @brief free all allocated memory in the vectors and initialize them.
 * 
 */
void DataFile::deleteData() {
    //deleting the coordinates
    for (auto coordinate : m_coordinates) {
        delete coordinate;
    }

    //deleting the types
    for (auto type : m_types) {
        delete type;
    }

    m_coordinates.clear();
    m_types.clear();
}

/**
 * @brief Get the Coordinates object
 * 
 * @return std::vector<std::string*> 
 */
std::vector<std::string*> DataFile::getCoordinates() {
    return m_coordinates;
}

/**
 * @brief Get the Types object
 * 
 * @return std::vector<std::string*> 
 */
std::vector<std::string*> DataFile::getTypes() {
    return m_types;
}


/**
 * @brief Get the Types Options
 * 
 * @return std::vector<std::string> the types
 */
std::vector<std::string> DataFile::getTypesOptions() {
    std::vector<std::string> typesOptions;
    bool counted;
    for (auto type : m_types) {
        //checking if it already in the vector
        counted = false;
        for (std::string knownType : typesOptions) {
            counted = counted || (strcmp(knownType.c_str(), type->c_str()) == 0);
        }

        if (counted == false) {
            typesOptions.push_back(*type);
        }
    }

    return typesOptions;
}

/**
 * @brief Destroy the Data File object
 * 
 */
DataFile::~DataFile() {
    this->deleteData();
}