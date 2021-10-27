#ifndef SERVER_SERVER_COMMANDS_CLASSIFIE_COMAND_CLASSIFIE_COMAND__H
#define SERVER_SERVER_COMMANDS_CLASSIFIE_COMAND_CLASSIFIE_COMAND__H

#include <string>
#include "../Command.h"
#include "../../../../classifier/knnClassifiers/KnnDataClassifier.h"
#include "../../data/Data.h"
#include "../../data/DataFile.h"
#include "../../settings/Settings.h"
class ClassifieCommand : public Command{
    Data* m_data;
    Settings* m_settings;
public:
    /**
     * @brief Construct a new Classifie Command object
     * 
     * @param data the classified and unclassified data
     * @param settings the distance settings
     * @param io the input output object
     * @param description the command description
     */
    ClassifieCommand(Data* data, Settings* settings ,DefaultIO* io, std::string description = "classify data");

    /**
     * @brief execute the command
     * 
     */
    void exectute() override;

    /**
     * @brief classifie the data.
     * 
     * @param param nullptr
     */
    static void* classifie(void* param);
};

#endif //SERVER_SERVER_COMMANDS_CLASSIFIE_COMAND_CLASSIFIE_COMAND__H