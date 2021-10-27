#include "Metric.h"

Metric::Metric(std::vector<double> *coordinates, std::string type, void(*metricFunc)(double,double,double&)){
    m_metricFunc = metricFunc;
    m_coordinates = coordinates;
    m_type = new std::string(type);
}

Metric* Metric::create(std::string coor, std::string type, void(*metricFunc)(double,double,double&)){
    //creating a new vector for the coordiantes.
    std::vector<double>* coordiantes = new std::vector<double>();
    //putting all the values in the vector
    for (int i = std::count(coor.begin(), coor.end(), ','); i >= 0; i--) {
        double x = std::stod(coor.substr(0,coor.find_first_of(',')));
        coordiantes->push_back(x);
        coor = coor.substr(coor.find_first_of(',') + 1 , coor.length());
    }
    //creating the new metric.
    return new Metric(coordiantes,type,metricFunc);
}

double Metric::distance(const Metric *other) const {
    //checking if the distance can be calculated, returning 0 if not.
    if (other == nullptr || this->m_coordinates->size() != other->m_coordinates->size()) {
        return 0;
    }
    //calculating the sum if we can.
    return Distance::distance(this->m_coordinates,other->m_coordinates,this->m_metricFunc);
}

Metric::Metric(Metric& metric){
    //copping the values.
    m_type = new std::string(*metric.m_type);
    m_coordinates = new std::vector<double>(*metric.m_coordinates);
    m_metricFunc = metric.m_metricFunc;
}

void Metric::operator=(const Metric &metric){
    //deleting old values.
    delete m_coordinates;
    delete m_type;
    //copping new values.
    m_type = new std::string(*metric.m_type);
    m_coordinates = new std::vector<double>(*metric.m_coordinates);
    m_metricFunc = metric.m_metricFunc;
}

Metric::~Metric(){
    delete m_coordinates;
    delete m_type;
}

/**
 * @brief Get the My Type object
 * 
 * @return std::string the type
 */
std::string Metric::getMyType() {
    return *m_type;
}