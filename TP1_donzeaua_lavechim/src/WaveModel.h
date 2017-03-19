#ifndef WAVEMODEL_H
#define WAVEMODEL_H

#include <iosfwd>
#include <fstream>
#include <iostream>

class WaveModel {
protected:
    double directionVent; // entre  et 2*pi
    double alignementVent;
    double intensite;       //Si on les mets static, ça provoque une "undefined reference"
    double longueurOnde;
    double ajustVague;

public:
    WaveModel(double dirV=0, double alignV=0, double intens=0, double lambda=0,double ajust=0);
    virtual ~WaveModel();
    virtual double operator()(double x, double y, double t) = 0;
    void display(std::ostream& str);
    double getDirectionVent();
    double getAlignementVent();
    double getIntensite();
    double getLongueurOnde();
    double getAjustementVague();
    void init_param(double dirV, double alignV,double  inten,double  lambda, double ajustV);
};

#endif //WAVEMODEL_H
