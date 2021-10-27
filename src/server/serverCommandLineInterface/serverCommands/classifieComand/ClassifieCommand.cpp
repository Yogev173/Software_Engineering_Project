#include "ClassifieCommand.h"

/**
 * @brief Construct a new Classifie Command object
 * 
 * @param data the classified and unclassified data
 * @param settings the distance settings
 * @param io the input output 
 * @param description the command description
 */
ClassifieCommand::ClassifieCommand(Data* data, Settings* settings ,DefaultIO* io, std::string description)  : Command( io, description) {
    m_data = data;
    m_settings = settings;
}

/**
 * @brief execute the command
 * 
 */
void ClassifieCommand::exectute() {
    m_data->setIsProccesing(true);
    if (m_data->getClassifiedData() != m_data->getOldClassifiedData()) {
        delete m_data->getOldClassifiedData();
        m_data->setOLdClassifiedData(m_data->getClassifiedData());
    }
    m_data->setClassifiedData(new ClassifiedData());

    std::vector<void*>* param = new std::vector<void*>();
    param->push_back(m_data);
    param->push_back(m_settings);

    
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, ClassifieCommand::classifie, param);

    //sending classifying in procces
    m_io->send(std::string("classifying data in procces"));
}

    /**
     * @brief classifie the data.
     * 
     * @param param nullptr
     */
    void* ClassifieCommand::classifie(void* param) {
        std::vector<void*>* vec = static_cast<std::vector<void*>*>(param);
        Data* data = static_cast<Data*>((*vec)[0]);
        Settings* settings = static_cast<Settings*>((*vec)[1]);;


        DataFile* classified = data->getTrainFile();
        DataFile* unclassified = data->getTestFile();
        

        ClassifiedData* outputData = data->getClassifiedData();
        KnnDataClassifier knnDataClassifier(classified, unclassified, outputData, settings);
        knnDataClassifier.classifie();

        data->setIsProccesing(false);

        pthread_detach(pthread_self());
        return nullptr;
    }