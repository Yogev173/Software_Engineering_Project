#include "ConfusionMatrix.h"

/**
 * @brief Construct a new Confusion Matrix object
 * 
 * @param types the types in the matrix
 */
ConfusionMatrix::ConfusionMatrix(std::vector<std::string> types) {
    m_types = types;

    //initializing the matrix
    for (auto rowType : types) {
        for (auto colType : types) {
            m_confusionMatrix[rowType][colType] = 0;
        }
    }
}

/**
 * @brief add to the confusion matrix an occur.
 * 
 * @param realType the actual type
 * @param resultType the type from the classifier
 */
void ConfusionMatrix::addOccur(std::string realType, std::string resultType) {
    m_confusionMatrix[realType][resultType]++;
}

/**
 * @brief make a string reprsenting the object.
 * 
 * @param k the k nearest to chek
 * @param metric the metric typ
 * @return std::string string represnting the object
 */
std::string ConfusionMatrix::toString(int k, std::string metric) {
    std::string str = "";
    //iterating the rows
    for (auto rowType : m_types) {
        str += rowType;

        //iterating the columns
        for (auto colType : m_types) {
            str += "\t" + std::to_string(this->precent(rowType, colType)) + "%";
        }

        str +="\n";
    }


    for (auto type : m_types) {
        str += type + "  ";
    }
    str +="\n";
    str += "k: " + std::to_string(k) + ", distance type: " + metric + "\n";
    
    return str;
}


/**
 * @brief calculate the precent of the realType that classified has the resultType
 * 
 * @param realType the actual type
 * @param resultType the type from the classifier
 * @return double the precent (0-100)
 */
double ConfusionMatrix::precent(std::string realType, std::string resultType) {
    double numOfOccur = 0;
    //counting the num of real type
    for (auto colType : m_types) {
        numOfOccur += m_confusionMatrix[realType][colType];
    }

    return (m_confusionMatrix[realType][resultType] / numOfOccur);
}