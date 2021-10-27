#ifndef ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SETTINGS_SETTINGS_H
#define ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SETTINGS_SETTINGS_H

#include "../../../classifier/Distance.h"
#include "../../IOS/DefaultIO.h"

class Settings {
private:
int m_k;
std::string m_metricType;
void(*m_metric)(double,double,double&);

typedef void(*fptr)(double,double,double&);

public:
    /**
     * @brief Construct a new Settings object
     * 
     */
    Settings();

    /**
     * @brief Set the Values object
     * 
     * @param k the k nearest neighber to check
     * @param type the type of the distance function
     */
    void setValues(int k, std::string* type);

    /**
     * @brief get the value of k.
     * 
     * @return int the value of k.
     */
    int getK();

    /**
     * @brief Get the Metric Type object
     * 
     * @return std::string the type
     */
    std::string getMetricType();

    /**
     * @brief Get the Metric Type object
     * 
     * @return void(*fptr)(double,double,double&) pointer to the metric function
     */
    fptr getMetricFunc();
};

#endif //ADVANCED_PROGRAMMINIG_1_SERVER_SERVERCLI_SETTINGS_SETTINGS_H