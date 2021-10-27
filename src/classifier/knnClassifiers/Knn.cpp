#include "Knn.h"
#include <vector>
#include "../Select_k.h"
#include "../Comparable.h"
#include "../Metric.h"

template<typename T>
Knn<T>::Knn(const int knn, const std::vector<T *> &data, std::vector<std::string> types) : Classifier<T>(data,
                                                                                                         types) {
    m_knn = knn;
}

template<typename T>
std::string Knn<T>::knn(T *t) {
    std::vector<Comparable<T> *> vector;
    for (T *obj : this->getData()) {
        vector.push_back(new Comparable<T>(obj->distance(t), obj));
    }

    double k_key = Select_k<T>::selectK(vector, m_knn);
    std::vector<std::string> types = this->getTypes();
    int size = types.size();
    std::vector<int> countVector(size);
    for (int i = 0; i < size; i++) {
        countVector[i] = 0;
    }

    int counter = 0;
    for (Comparable<T> *element : vector) {
        if (element->getKey() < k_key) {
            for (int index = 0; index < size; index++) {
                if (types[index] == element->getObject()->getMyType()) {
                    countVector[index]++;
                }
            }

            counter++;
        }
    }

    for (Comparable<T> *element : vector) {
        if (counter < m_knn && element->getKey() == k_key) {
            for (int index = 0; index < size; index++) {
                if (types[index] == element->getObject()->getMyType()) {
                    countVector[index]++;
                }
            }

            counter++;
        }
    }
    
    std::string type = types[0];
    int maxApperense = countVector[0];
    for (int i = 0; i < size; i++) {
        if (countVector[i] > maxApperense) {
            type = types[i];
            maxApperense = countVector[i];
        }
    }

    for (Comparable<T> *element : vector) {
        delete element;
    }
    return type;
}

/**
 * @brief classified a T.
 *
 * @param t the thing to classified.
 * @return std::string the type of t.
 */
template<typename T>
std::string Knn<T>::typeOfElement(T *t) {
    return knn(t);
}

template class Knn<Metric>;