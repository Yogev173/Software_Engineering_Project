#include "Settings.h"
#include <iostream>
#include <string.h>

Settings::Settings() {
    //default settings.
    m_metricType = std::string("EUC");
    m_k = 5;
    m_metric = &Distance::EUC;
}

void Settings::setValues(int k, std::string* type){
    m_k = k;
    if (strcmp("CHE" , type->c_str()) == 0) {
        m_metric = &Distance::CHE;
        m_metricType = std::string("CHE");
    }
    else if (strcmp("MAN" , type->c_str()) == 0) {
        m_metric = &Distance::MAN;
        m_metricType = std::string("MAN");
    }
    else if (strcmp("EUC" , type->c_str()) == 0) {
        m_metric = &Distance::EUC;
        m_metricType = std::string("EUC");
    }
}


/**
 * @brief get the value of k.
 * 
 * @return int the value of k.
 */
int Settings::getK() {
    return m_k;
}

/**
 * @brief Get the Metric Type object
 * 
 * @return std::string the type
 */
std::string Settings::getMetricType() {
    return m_metricType;
}

/**
 * @brief Get the Metric Type object
 * 
 * @return void(*fptr)(double,double,double&) pointer to the metric function
 */
Settings::fptr Settings::getMetricFunc() {
    return m_metric;
}