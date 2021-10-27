//
// Created by yoavo on 31/07/2021.
//

#ifndef ADVANCED_PROGRAMMINIG_1_KNN_H
#define ADVANCED_PROGRAMMINIG_1_KNN_H

#include "../Classifier.h"
#include <vector>

/**
 * @brief classifie an object, according to previos data, using knn algorithem.
 *
 * @tparam T inheritens from Metric.
 */
template <typename T>
class Knn : public Classifier<T> {
    int m_knn;
public:
    /**
     * @brief Construct a new Knn object
     * 
     * @param knn amount of nearest neighbored to chek.
     */
    Knn(int knn,const std::vector<T*>& data, std::vector<std::string> types);

    /**
     * @brief classified a T.
     *
     * @param t the thing to classified.
     * @return std::string the type of t.
     */
    std::string typeOfElement(T *t) override;
private:
    /**
     * @brief 
     * 
     * @param t th thing to classifier.
     * @return std::string the type of the thing.
     */
    std::string knn(T* t);
};

#endif //ADVANCED_PROGRAMMINIG_1_KNN_H
