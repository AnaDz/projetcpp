#include "GerstnerWave.h"
#include <cmath>

GerstnerWave::GerstnerWave(Dvector X_0, Dvector vectOnde, double phase, double ampli) {
    if (X_0.size() == 2){
        this->X0 = X_0;
    } else {
        throw std::invalid_argument("Le point x0 n'est pas de taille 2");
    }
    if (vectOnde.size() ==2){
        this->k =vectOnde;
    } else {
        throw std::invalid_argument("Le vecteur d'onde n'est pas de taille 2");
    }
    this->phi=phase;
    this->A = ampli;
}

GerstnerWave::~GerstnerWave() {

}

void GerstnerWave::display(std::ostream& str) {
    str<< "Point X0 : ";
    X0.display(str);
    str<<"\n";
    str<< "Vecteur d'onde :";
    k.display(str);
    str << "\n";
    str<< "Phase : " << phi << "\n";
    str << "Amplitude : " << A << "\n";
}

double GerstnerWave::operator()(double x, double y, double t) {
    double res;
    double prodscal = x*y+k(0)*k(1);
    double normek = k.norm();
    double w = sqrt(9.81*normek);
    res = A*cos(prodscal-w*t);
    return res;
}



