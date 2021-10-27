#include "Data.h"

/**
 * @brief Construct a new Data object
 * 
 */
Data::Data() {
    m_classifiedData = nullptr;
    m_oldClassifiedData = nullptr;
}

/**
 * @brief Set the Is Proccesing object
 * 
 * @param b the new value
 */
void Data::setIsProccesing(bool b) {
    m_isProccesing = b;
}

/**
 * @brief Get the Is Proccesing object
 * 
 * @return the value of isProccesing
 */
bool Data::getIsProccesing() {
    return m_isProccesing;
}

/**
 * @brief add an object to the test data.
 * 
 * @param coordinateAndType the description of the new object coordinates,type.
 */
void Data::addTestData(std::string coordinateAndType) {
    m_testFile.addObject(coordinateAndType);
}

    /**
 * @brief add an object to the train data.
 * 
 * @param coordinateAndType the description of the new object coordinates,type.
 */
void Data::addTrainData(std::string coordinateAndType) {
    m_trainFile.addObject(coordinateAndType);
}

/**
 * @brief add an object to the classified data data.
 * 
 * @param type the description of the new classified type.
 */
void Data::addclassifiedData(std::string type) {
    m_classifiedData->addObject(type);
}

/**
 * @brief Get the Test File object
 * 
 * @return DataFile 
 */
DataFile* Data::getTestFile() {
    return &m_testFile;
}

/**
 * @brief Get the Train File object
 * 
 * @return DataFile 
 */
DataFile* Data::getTrainFile() {
    return &m_trainFile;
}

/**
 * @brief Get the Classified Data object
 * 
 * @return ClassifiedData 
 */
ClassifiedData* Data::getClassifiedData() {
    return m_classifiedData;
}

/**
 * @brief Get the Old Classified Data object
 * 
 * @return ClassifiedData 
 */
ClassifiedData* Data::getOldClassifiedData() {
    return m_oldClassifiedData;
}

/**
 * @brief delete the test file data.
 * 
 */
void Data::deleteTestFile() {
    m_testFile.deleteData();
}

    /**
 * @brief delete the train file data.
 * 
 */
void Data::deleteTrainFile() {
    m_trainFile.deleteData();
}

/**
 * @brief Destroy the Data object
 * 
 */
Data::~Data() {
    
    if (m_classifiedData != nullptr) {
        delete m_classifiedData;
        if (m_classifiedData == m_oldClassifiedData){
            m_oldClassifiedData = nullptr;
        }
        m_classifiedData = nullptr;
    }

    if (m_oldClassifiedData != nullptr) {
        delete m_oldClassifiedData;
        m_oldClassifiedData = nullptr;
    }

    this->deleteTestFile();
    this->deleteTrainFile();
}

/**
 * @brief Set the Classified Data object
 * 
 * @param cl the new Classified Data object
 */
void Data::setClassifiedData(ClassifiedData* cl) {
    m_classifiedData = cl;
}

/**
 * @brief Set the old Classified Data object
 * 
 * @param cl the new old Classified data
 */
void Data::setOLdClassifiedData(ClassifiedData* cl) {
    m_oldClassifiedData = cl;
}