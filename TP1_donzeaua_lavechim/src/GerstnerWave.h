#ifndef GERSTNERWAVE_H
#define GERSTNERWAVE_H

#include "Dvector.h"
#include <algorithm>
#include <iostream>
#include <list>

class GerstnerWave{
private:
    Dvector X0; // condition initiale  z=0
    Dvector k; // vecteur d'onde
    double w; // fréquence
    double phi; //phase
    double A; //amplitude
    const double g = 9.81; //gravité
public:
    GerstnerWave(Dvector X_0=Dvector(2,0),Dvector vectOnde=Dvector(2,0), double phase=0, double ampli =0);

    double operator()(double x, double y, double t);

    bool operator==(const GerstnerWave &GW);
    GerstnerWave& operator=(const GerstnerWave &GW);

    void display(std::ostream& str);
    //~GerstnerWave();
};

#endif //GERSTNERWAVE_H
