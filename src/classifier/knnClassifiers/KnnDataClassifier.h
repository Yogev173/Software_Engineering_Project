#ifndef ADVANCED_PROGRAMMINIG_1_KNN_DATA_CLASSIFIER_H
#define ADVANCED_PROGRAMMINIG_1_KNN_DATA_CLASSIFIER_H

#include <string>
#include <vector>
#include "../../server/serverCommandLineInterface/data/DataFile.h"
#include "../../server/serverCommandLineInterface/data/ClassifiedData.h"
#include "../../server/serverCommandLineInterface/settings/Settings.h"
#include "../DataProcesser.h"
#include "../Metric.h"
#include "Knn.h"

/**
 * @brief classifie file of an object, according to previos data.
 * 
 */
class KnnDataClassifier {
    DataFile* m_classified;
    DataFile* m_UNlassified;
    ClassifiedData* m_outputData;
    Settings* m_settings;

public:
    /**
     * @brief Construct a new Knn Data Classifier object
     * 
     * @param m_classified the classified data
     * @param m_UNlassified the data to classified
     * @param m_outputData the var to save the result data
     * @param settings the distance and knn settings.
     */
    KnnDataClassifier(DataFile* classified, DataFile* UNlassified, ClassifiedData* outputData, Settings* settings);

    /**
     * @brief UNclassifie the data and save it in outputData.
     * 
     */
    void classifie();
};

#endif //ADVANCED_PROGRAMMINIG_1_KNN_DATA_CLASSIFIER_H