#include "KnnDataClassifier.h"
#include "../Metric.h"


/**
 * @brief Construct a new Knn Data Classifier object
 * 
 * @param m_classified the classified data
 * @param m_UNlassified the data to classified
 * @param m_outputData the var to save the result data
 * @param settings the distance and knn settings.
 */
KnnDataClassifier::KnnDataClassifier(DataFile* classified, DataFile* UNlassified, ClassifiedData* outputData, Settings* settings) {
    m_classified = classified;
    m_UNlassified = UNlassified;
    m_outputData = outputData;
    m_settings = settings;
}

/**
 * @brief UNclassifie the data and save it in outputData.
 * 
 */
void KnnDataClassifier::classifie() {
    //initialize the classified object
    std::vector<Metric *> data;
    DataProcesser<Metric>::initializeVector(data, m_classified, m_settings->getMetricFunc());

    //initialize the unclassified object
    std::vector<Metric *> unClassified;
    DataProcesser<Metric>::initializeVector(unClassified, m_UNlassified, m_settings->getMetricFunc());

    Knn<Metric> knn(m_settings->getK(), data, m_classified->getTypesOptions());

    for (auto element = unClassified.begin(); element != unClassified.end(); element++) {
        std::string type = knn.typeOfElement(*element);
        m_outputData->addObject(type);
    }

    //deleting the T that on the Heap.
    DataProcesser<Metric>::deleteVectorvalues(data);
    DataProcesser<Metric>::deleteVectorvalues(unClassified);
}