#ifndef DATA_CLASSIFIED_DATA__H
#define DATA_CLASSIFIED_DATA__H

#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "../../IOS/DefaultIO.h"

/**
 * @brief storege data about classified objects file.
 * (whene changing the file to a new file, you should delete the old one first)
 * 
 */
class ClassifiedData{
    std::vector<std::string*> m_types;

public:
    /**
     * @brief add an type to the data vectors,
     * !it allocate it on the heap!
     * 
     * @param type the description of the new type.
     */
    void addObject(std::string type);

    /**
     * @brief free all allocated memory in the vector and initialize them.
     * 
     */
    void deleteData();
        
    /**
     * @brief Get the Types object
     * 
     * @return std::vector<std::string*> 
     */
    std::vector<std::string*> getTypes();
    
    /**
     * @brief Get the Types Options
     * 
     * @return std::vector<std::string> the types
     */
    std::vector<std::string> getTypesOptions();

    /**
     * @brief Destroy the Classified Data object
     * 
     */
    virtual ~ClassifiedData();

    /**
     * @brief send the classified data, one byone throw the io, at the end send a "end"
     * 
     * @param io the DefaultIO to send with.
     */
    void sendData(DefaultIO* io);
};

#endif //DATA_CLASSIFIED_DATA__H