#ifndef SERVER_SERVER_COMMANDS_CONFUSION_MATRIX_COMAND_CONFUSION_MATRIX_COMMAND__H
#define SERVER_SERVER_COMMANDS_CONFUSION_MATRIX_COMAND_CONFUSION_MATRIX_COMMAND__H

#include <string>
#include "../Command.h"
#include "../../../../classifier/knnClassifiers/KnnDataClassifier.h"
#include "../../data/Data.h"
#include "../../data/DataFile.h"
#include "../../settings/Settings.h"
#include "ConfusionMatrix.h"
class ConfusionMatrixCommand : public Command{
    Data* m_data;
    Settings* m_settings;
public:
    /**
     * @brief Construct a new Confusion Matrix Command object
     * 
     * @param data the classified and unclassified data
     * @param settings the distance settings
     * @param io the input output object
     * @param description the command description
     */
    ConfusionMatrixCommand(Data* data, Settings* settings ,DefaultIO* io, std::string description = "display algorithm confusion matrix");

    /**
     * @brief execute the command
     * 
     */
    void exectute() override;

};

#endif //SERVER_SERVER_COMMANDS_CONFUSION_MATRIX_COMAND_CONFUSION_MATRIX_COMMAND__H