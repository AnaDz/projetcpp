#ifndef WAVEMODEL_H
#define WAVEMODEL_H

#include <iosfwd>

class WaveModel {
private:
    static double directionVent; // entre  et 2*pi
    static double alignementVent;
    static double intensite;
    static double longueurOnde;
    static double ajustVague;
    
public:
    WaveModel(double dirV=0, double alignV=0, double intens=0, double lambda=0,double ajust=0);
    virtual ~WaveModel() = 0;
    virtual double &operator() (double x, double y, double t) =0;
    void display(std::ostream& str);
    double getDirectionVent();
    double getAlignementVent();
    double getIntensite();
    double getLongueurOnde();
    double getAjustementVague();
};

#endif //WAVEMODEL_H
