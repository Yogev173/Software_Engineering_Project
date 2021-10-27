#include "DataProcesser.h"
#include "Metric.h"
#include <iostream>

/**
 * 
 * @brief initialize the vector, with pointers to the Object in the string.
 * 
 * @param data the vector to initialize.
 * @param dataFile the data to proces.
 * @param metricFunc the distance calculation setting.
 */
template<typename T>
void DataProcesser<T>::initializeVector(std::vector<T*>& data, DataFile* dataFile, void(*metricFunc)(double,double,double&)) {
    std::vector<std::string*> coorVec = dataFile->getCoordinates();
    auto coor = coorVec.begin();
    std::vector<std::string*> typeVec = dataFile->getTypes();
    auto type = typeVec.begin();
    for (;coor != coorVec.end() && type != typeVec.end(); coor++, type++) {
        data.push_back(T::create((**coor), (**type), metricFunc));
    }
}


/**
 * @brief delete the vector's elements from the heap.
 * 
 * @param data the vector to delete his values.
 */
template<typename T>
void DataProcesser<T>::deleteVectorvalues(std::vector<T *> &data) {
    for (T *element : data) {
        delete element;
    }
}

template class DataProcesser<Metric>;