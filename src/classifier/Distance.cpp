#include "Distance.h"
#include <math.h>
#include <iterator>
#include <functional>

void Distance::CHE(double x1, double x2, double& dist){
       if(dist < abs(x1 - x2)){
       dist =  abs(x1 - x2);
       }
   }
void Distance::EUC(double x1, double x2, double& dist){
    dist += sqrt(pow(x1-x2,2));

    }
void Distance::MAN(double x1, double x2, double& dist){
        dist += abs(x1 - x2);

    }
double Distance::distance(std::vector<double>* o1 ,std::vector<double>* o2, void(*func)(double,double,double&)) {
    if (o1->size() != o2->size()){
        return 0;
    }
    double dist = 0;
    auto it1 = o1->begin();
    auto it2 = o2->begin();
    while (it1 != o1->end()) {
        func(it1[0],it2[0],dist);
        it1++;
        it2++;
    }
    return dist;
    }