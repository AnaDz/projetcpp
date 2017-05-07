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
    std::complex<double> h_tilde(Vector<std::complex<double> > k, double t);
    std::complex<double> P(Vector<std::complex<double>> k);
    Vector<std::complex<double>> hTilde;
    //bool computed = false;
    double last_time = -10.0;
    void computeH_tilde(double t);
public:
    PhilipsWaveModel(double dirV, double alignV, double inten, double lambda, double ajustV);
    PhilipsWaveModel(double dirV, double alignV, double inten, double lambda, double ajustV, const Height & h);
    ~PhilipsWaveModel();
    Height getH();
    double operator()(double x, double y, double t);
    void display(std::ostream& str);
    void printtype();

};


#endif //CALCULSCIENTIFIQUE_PHILIPSWAVEMODEL_H
