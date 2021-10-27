#ifndef DATA_DATA_FILE__H
#define DATA_DATA_FILE__H

#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

/**
 * @brief storege data about objects file.
 * (whene changing the file to a new file, you should delete the old one first)
 * 
 */
class DataFile {
    private:
    std::vector<std::string*> m_coordinates;
    std::vector<std::string*> m_types;

    public:
    /**
     * @brief add an object to the datas vectors,
     * !it allocate it on the heap!
     * 
     * @param coordinateAndType the description of the new object coordinates,type.
     */
    void addObject(std::string coordinateAndType);

    /**
     * @brief free all allocated memory in the vectors and initialize them.
     * 
     */
    void deleteData();

    /**
     * @brief Get the Coordinates object
     * 
     * @return std::vector<std::string*> 
     */
    std::vector<std::string*> getCoordinates();

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
     * @brief Destroy the Data File object
     * 
     */
    virtual ~DataFile();
};

#endif //DATA_DATA_FILE__H