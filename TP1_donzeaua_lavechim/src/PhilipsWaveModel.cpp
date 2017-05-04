//
// Created by skip on 31/03/17.
//

#include "PhilipsWaveModel.h"
#include "Vector.h"
#include <cmath>
#include <complex>



PhilipsWaveModel::PhilipsWaveModel(double dirV, double alignV, double inten,double lambda, double ajustV){
    init_param(dirV,alignV,inten,lambda,ajustV);
}

PhilipsWaveModel::PhilipsWaveModel(double dirV, double alignV, double inten,double lambda, double ajustV, const Height & h){
    init_param(dirV,alignV,inten,lambda,ajustV);
    this->height = h;
}

PhilipsWaveModel::~PhilipsWaveModel(){

}

double getDouble(double min,double max)//Renvoie un double entre min et max
{
    srand(time(NULL));
    return  (min + (((float) rand() / RAND_MAX) * (max - min)));
}
double getGauss(double m, double e)     //Renvoie un nombre selon une distribution gaussienne centree en m et d'ecart-type e
{
    double a;
    double b;
    double s ;
    do {
        a = getDouble(-1.0, 1.0);
        b = getDouble(-1.0, 1.0);
        s = a*a + b*b;      //s doit etre dans [0;1[
    } while ((s >= 1.0) or (s == 0.0));
    double x(sqrt(-2.0 * log(s) / s));
    if (getDouble(0.0, 1.0) > 0.5){
        x *= a;
    }else{
        x *= b;
    }
    return m + e * x;
}
double w(Vector<std::complex<double>> k){
    double g = 9.8;
    return sqrt(g*k.norm().real());
}
std::complex<double> PhilipsWaveModel::P(Vector<std::complex<double>> k){
    if(k.norm()==std::complex<double>(0,0)){ return  std::complex<double>(0,0);}
    std::complex<double> res = std::complex<double>(0,0);
    double A = 3.0; //????
    // vitesse du vent
    Vector<std::complex<double>> w = Vector<std::complex<double>>(2);
    w(0) = std::complex<double>(std::cos(this->directionVent),0);
    w(1) = std::complex<double>(std::sin(this->directionVent),0);

    double V = this->intensite;
    double g = 9.8;
    double L = V*V/g;

    res = A * (std::exp(-1.0/(k.norm()*L*k.norm()*L))/(k.norm()*k.norm()));
    std::complex<double> prodscal = k*w;
    res = res * std::abs(prodscal.real())* std::abs(prodscal.real());
    return res;
}

std::complex<double> PhilipsWaveModel::h_tilde(Vector<std::complex<double> > k, double t){
    std::complex<double> res = std::complex<double>(0,0);
    double ksi_i=0.0, ksi_r=0.0;
    ksi_i = getGauss(0.0,1.0);
    ksi_r = getGauss(0.0,1.0);
    res = (1/sqrt(2.0))*std::complex<double>(ksi_r,ksi_i)*std::exp(std::complex<double>(0,w(k)*t))*sqrt(P(k));
    res += (1/sqrt(2.0))*std::complex<double>(ksi_r,-ksi_i)*std::exp(std::complex<double>(0,-w(k)*t))*sqrt(P(-k));
    return res;
}

double PhilipsWaveModel::operator()(double x, double y, double t){
    int N = height.getNx();
    int M = height.getNy();
    double Lx = height.getLx();
    double Ly = height.getLy();
    Vector<std::complex<double>> X(2);
    X(0) = floor(x*N/Lx);
    X(1) = floor(y*M/Ly);
    Vector<std::complex<double>> k(2);
    std::complex<double> h(0,0); 

    for (int i=-N/2; i<N/2+1;i++){
        for (int j=-M/2; j<M/2+1;j++){
            k(0) = std::complex<double>((double)2*M_PI*i/Lx,0.0);
            k(1) = std::complex<double>((double)2*M_PI*j/Ly,0.0);
            std::complex<double> prod = k*X;
            h = h + h_tilde(k, t)*std::exp(std::complex<double>(0,1)*prod);
        }
    }

    this->height(X(0).real(), X(1).real()) = h.real();
    return h.real();
}

Height PhilipsWaveModel::getH() {
    return height;
}
