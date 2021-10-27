//
// Created by yogev_a on 8/1/2021.
//

#include "Classifier.h"
#include "Metric.h"

template<typename T>
Classifier<T>::Classifier(const std::vector<T *> &data, std::vector<std::string> &types) : m_types(types) {
    m_data = data;
}

template<typename T>
std::vector<std::string> Classifier<T>::getTypes() {
    return m_types;
}

template<typename T>
std::vector<T*> Classifier<T>::getData() {
    return m_data;
}

template<typename T>
int Classifier<T>::getNumOfTypes() {
    return m_types.size();
}

template class Classifier<Metric>;