#include "ConfusionMatrixCommand.h"

/**
 * @brief Construct a new Classifie Command object
 * 
 * @param data the classified and unclassified data
 * @param settings the distance settings
 * @param io the input output 
 * @param description the command description
 */
ConfusionMatrixCommand::ConfusionMatrixCommand(Data* data, Settings* settings ,DefaultIO* io, std::string description)
  : Command( io,  description) {
    m_data = data;
    m_settings = settings;
}

/**
 * @brief execute the command
 * 
 */
void ConfusionMatrixCommand::exectute() {
    ConfusionMatrix confusionMatrix(m_data->getTrainFile()->getTypesOptions());
    //insert to the confusion matrix the classifier result
    std::vector<std::string*> realTypes = m_data->getTestFile()->getTypes();
    std::vector<std::string*> resultTypes;
    if (m_data->getClassifiedData() == nullptr) {
        m_io->send("before displaying the confusion matrix, a classifie is required. \n\n");
        return;
    }
    else if (!m_data->getIsProccesing()) {
        resultTypes = m_data->getClassifiedData()->getTypes();
        if(m_data->getClassifiedData() != m_data->getOldClassifiedData()) {
            delete m_data->getOldClassifiedData();
            m_data->setOLdClassifiedData(m_data->getClassifiedData());
        }
    } else {
        resultTypes = m_data->getOldClassifiedData()->getTypes();
    }
     
    auto real = realTypes.begin();
    auto result = resultTypes.begin();

    for (;real != realTypes.end() && result != resultTypes.end(); real++, result++) {
        confusionMatrix.addOccur(**real, **result);
    }

    //sending the matrix to the client
    m_io->send(confusionMatrix.toString(m_settings->getK(), m_settings->getMetricType()));
}