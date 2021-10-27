#ifndef ADVANCED_PROGRAMMINIG_1_CLASSIFIER_DISTANCE_H
#define ADVANCED_PROGRAMMINIG_1_CLASSIFIER_DISTANCE_H

#include <vector>
class Distance{
    public:
    static void CHE(double x1, double x2, double& dist);
    static void EUC(double x1, double x2, double& dist);
    static void MAN(double x1, double x2, double& dist);
    static double distance(std::vector<double>* o1 ,std::vector<double>* o2, void(*func)(double,double,double&));
};

#endif //ADVANCED_PROGRAMMINIG_1_CLASSIFIER_DISTANCE_H