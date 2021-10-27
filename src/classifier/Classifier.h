#ifndef ADVANCED_PROGRAMMINIG_1_CLASSIFIER_H
#define ADVANCED_PROGRAMMINIG_1_CLASSIFIER_H

#include <string>
#include <vector>

/**
 * @brief classifie an object, according to previos data.
 * 
 * @tparam T inheritens from Metric.
 */
template<typename T>
class Classifier {
private:
    std::vector<T *> m_data;
    std::vector<std::string> m_types;
protected:
    /**
     *
     * @return the data of the classifier.
     */
    std::vector<T *> getData();
/**
 *
 * @return the types we classify with.
 */
    std::vector<std::string> getTypes();

    /**
     *
     * @return the number of types the class have.
     */
    int getNumOfTypes();

public:
    /**
 * @brief Construct a new Classifier object
 *
 * @param data alredy classsified T.
 * @param types the options for the classified thing.
 */
    Classifier(const std::vector<T *> &data, std::vector<std::string> &types);

    /**
     * @brief classified a T.
     *
     * @param t the thing to classified.
     * @return std::string the type of t.
     */
    virtual std::string typeOfElement(T *t) = 0;
};

#endif //ADVANCED_PROGRAMMINIG_1_CLASSIFIER_H