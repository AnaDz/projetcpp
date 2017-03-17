#ifndef GERSTNERWAVE_H
#define GERSTNERWAVE_H

#include "Dvector.h"

class GerstnerWave{
private:
    Dvector X0; // condition initiale  z=0
    Dvector k; // vecteur d'onde
//    double w; // fréquence
    double phi; //phase
    double A; //amplitude
public:
    GerstnerWave(Dvector X_0=Dvector(2,0),Dvector vectOnde=Dvector(2,0), double phase=0, double ampli =0);
    ~GerstnerWave();
    void display(std::ostream& str);
    double operator()(double x, double y, double t);
};

#endif //GERSTNERWAVE_H
