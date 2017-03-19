#ifndef GERSTNERWAVEMODEL_H
#define GERSTNERWAVEMODEL_H

#include "GerstnerWave.h"
#include "WaveModel.h"

using namespace std;

class GerstnerWaveModel : public WaveModel {

private:
    list<GerstnerWave> listGerWave;

public:
    GerstnerWaveModel(double dirV, double alignV, double inten,double lambda, double ajustV);
    GerstnerWaveModel(double dirV, double alignV, double inten,double lambda, double ajustV, list<GerstnerWave> listGerWave);

    void addGerstnerWave(const GerstnerWave & W);
    ~GerstnerWaveModel();
    double operator()(double x, double y, double t);
    void display(std::ostream& str);
};

#endif
