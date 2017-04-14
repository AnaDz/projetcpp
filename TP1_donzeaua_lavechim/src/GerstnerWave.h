#ifndef GERSTNERWAVE_H
#define GERSTNERWAVE_H

#include "Vector.h"
#include <algorithm>
#include <iostream>
#include <list>

class GerstnerWave{
private:
    Vector<double> X0; // condition initiale  z=0
    Vector<double> k; // vecteur d'onde
    double w; // fréquence
    double phi; //phase
    double A; //amplitude
    const double g = 9.81; //gravité
public:
    GerstnerWave(Vector<double> X_0 = Vector<double>(2,0), Vector<double> vectOnde = Vector<double>(2,0), double phase=0, double ampli =0);

    double operator()(double x, double y, double t);

    bool operator==(const GerstnerWave &GW);
    GerstnerWave& operator=(const GerstnerWave &GW);

    void display(std::ostream& str);
    //~GerstnerWave();
};

#endif //GERSTNERWAVE_H
