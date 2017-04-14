//
// Created by skip on 31/03/17.
//

#ifndef PHILIPSWAVEMODEL_H
#define PHILIPSWAVEMODEL_H

#include "WaveModel.h"
#include "Height.h"
#include <complex>

class PhilipsWaveModel : public WaveModel{

private:
    Height height;
public:
    PhilipsWaveModel(double dirV, double alignV, double inten,double lambda, double ajustV);
    PhilipsWaveModel(double dirV, double alignV, double inten,double lambda, double ajustV, Height h);
    ~PhilipsWaveModel();

    std::complex<double> operator()(int n, int m, double t);


};


#endif //CALCULSCIENTIFIQUE_PHILIPSWAVEMODEL_H
