#ifndef SERVER_SERVER_COMMANDS_CONFUSION_MATRIX_COMAND_CONFUSION_MATRIX__H
#define SERVER_SERVER_COMMANDS_CONFUSION_MATRIX_COMAND_CONFUSION_MATRIX__H

#include <string>
#include <vector>
#include <map>

class ConfusionMatrix {
    std::map<std::string, std::map<std::string, int>> m_confusionMatrix;
    std::vector<std::string> m_types;
public:
    /**
     * @brief Construct a new Confusion Matrix object
     * 
     * @param types the types in the matrix
     */
    ConfusionMatrix(std::vector<std::string> types);

    /**
     * @brief add to the confusion matrix an occur.
     * 
     * @param realType the actual type
     * @param resultType the type from the classifier
     */
    void addOccur(std::string realType, std::string resultType);

    /**
     * @brief make a string reprsenting the object.
     * 
     * @param k the k nearest to chek
     * @param metric the metric typ
     * @return std::string string represnting the object
     */
    std::string toString(int k, std::string metric);

private:
    /**
     * @brief calculate the precent of the realType that classified has the resultType
     * 
     * @param realType the actual type
     * @param resultType the type from the classifier
     * @return double the precent (0-100)
     */
    double precent(std::string realType, std::string resultType);

};

#endif //SERVER_SERVER_COMMANDS_CONFUSION_MATRIX_COMAND_CONFUSION_MATRIX__H