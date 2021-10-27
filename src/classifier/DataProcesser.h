#ifndef ADVANCED_PROGRAMMINIG_1_CSVObjectReader_H
#define ADVANCED_PROGRAMMINIG_1_CSVObjectReader_H

#include <string>
#include <vector>
#include "../server/serverCommandLineInterface/data/DataFile.h"

/**
 * @brief proces data to a vector.
 * 
 * @tparam T inheritense from Metric.
 */
template<typename T>
class DataProcesser {
public:
    /**
     * 
     * @brief initialize the vector, with pointers to the Object in the string.
     * 
     * @param data the vector to initialize.
     * @param dataFile the data to proces.
     * @param metricFunc the distance calculation setting.
     */
    static void initializeVector(std::vector<T*>& data, DataFile* dataFile, void(*metricFunc)(double,double,double&));

    /**
     * @brief delete the vector's elements from the heap.
     * 
     * @param data the vector to delete his values.
     */
    static void deleteVectorvalues(std::vector<T*>& data);
};

#endif //ADVANCED_PROGRAMMINIG_1_CSVObjectReader_H