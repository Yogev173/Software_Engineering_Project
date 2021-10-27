#ifndef ADVANCED_PROGRAMMINIG_1_METRIC_H
#define ADVANCED_PROGRAMMINIG_1_METRIC_H

#include <string>
#include <vector>
#include "Distance.h"
#include <algorithm>

/**
 * the interface represent classes which we can calculate the object's distance from other objects from the same class.
 */
class Metric {
private:
    std::vector<double> *m_coordinates;
    std::string *m_type;
    void(*m_metricFunc)(double,double,double&);

public:

    /**
     * @brief the method get a string, parse it and create a new object from the data.
     * 
     * @param coor string represetation for the coordinats, each number seperated by a comma. 
     * @param type the type of the objects.
     * @param metricFunc the metric function to calculate distance from other objects
     * @return Metric* pointer to the new object.
     */
    static Metric* create(std::string coor,std::string type, void(*metricFunc)(double,double,double&));


    /**
     * @brief Construct a new Metric object
     * 
     * @param coordinates the object coordinate
     * @param type the object type
     * @param metricFunc - the func to calculate the distance with. 
     */
    Metric(std::vector<double> *coordinates, std::string type, void(*metricFunc)(double,double,double&));

    /**
     * copy constructor.
     * @param Metric - the Metric we want to copy
     */
    Metric(Metric &Metric);

    /**
     * assignment operator
     * @param Metric the Metric we assign
     */
    void operator=(const Metric &Metric);

    /**
     * destructor
     * @brief Destroy the Metric object
     * 
     */
    virtual ~Metric();

    /**
     * @brief Get the My Type object
     * 
     * @return std::string the type
     */
    std::string getMyType();

    /**
     * @brief calculate the distance
     * 
     * @param other the other Metric object to calculate the distance from
     * @return double the distance
     */
    double distance(const Metric *other) const;
};

#endif //ADVANCED_PROGRAMMINIG_1_METRIC_H
