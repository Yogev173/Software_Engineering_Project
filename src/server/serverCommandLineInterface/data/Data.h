#ifndef DATA_DATA__H
#define DATA_DATA__H

#include <string>
#include "DataFile.h"
#include "ClassifiedData.h"

/**
 * @brief storege data about test, train and classifide objects.
 * (whene changing the test, train or classified to a new file, you should delete the old one first)
 * 
 */
class Data{
    DataFile m_testFile;
    DataFile m_trainFile;
    ClassifiedData* m_classifiedData;
    ClassifiedData* m_oldClassifiedData;
    bool m_isProccesing = false;

public: 

    /**
     * @brief Set the Is Proccesing object
     * 
     * @param b the new value
     */
    void setIsProccesing(bool b);

    /**
     * @brief Get the Is Proccesing object
     * 
     * @return the value of isProccesing
     */
    bool getIsProccesing();

    /**
     * @brief Construct a new Data object
     * 
     */
    Data();

    /**
     * @brief add an object to the test data.
     * 
     * @param coordinateAndType the description of the new object coordinates,type.
     */
    void addTestData(std::string coordinateAndType);

    /**
     * @brief add an object to the train data.
     * 
     * @param coordinateAndType the description of the new object coordinates,type.
     */
    void addTrainData(std::string coordinateAndType);

    /**
     * @brief add an object to the classified data data.
     * 
     * @param type the description of the new classified type.
     */
    void addclassifiedData(std::string type);

    /**
     * @brief Get the Test File object
     * 
     * @return DataFile 
     */
    DataFile* getTestFile();

    /**
     * @brief Get the Train File object
     * 
     * @return DataFile 
     */
    DataFile* getTrainFile();

    /**
     * @brief Get the Classified Data object
     * 
     * @return ClassifiedData* 
     */
    ClassifiedData* getClassifiedData();

    /**
     * @brief Get the Old Classified Data object
     * 
     * @return ClassifiedData* 
     */
    ClassifiedData* getOldClassifiedData();

    /**
     * @brief delete the test file data.
     * 
     */
    void deleteTestFile();

        /**
     * @brief delete the train file data.
     * 
     */
    void deleteTrainFile();

    /**
     * @brief delete the classified data.
     * 
     */
    void deleteClassifiedData();

    /**
     * @brief Set the Classified Data object
     * 
     * @param cl the new Classified Data object
     */
    void setClassifiedData(ClassifiedData* cl);

    /**
     * @brief Set the old Classified Data object
     * 
     * @param cl the new old Classified data
     */
    void setOLdClassifiedData(ClassifiedData* cl);

    /**
     * @brief Destroy the Data object
     * 
     */
    virtual ~Data();
};

#endif //DATA_DATA__H