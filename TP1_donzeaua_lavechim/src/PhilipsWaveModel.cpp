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

PhilipsWaveModel::PhilipsWaveModel(double dirV, double alignV, double inten,double lambda, double ajustV, Height h){
    init_param(dirV,alignV,inten,lambda,ajustV);
    height = h;
    // TODO !! Le = de height
}

PhilipsWaveModel::~PhilipsWaveModel(){

}

double getDouble(double min,double max)//Renvoie un double entre min et max
{
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
std::complex<double> P(Vector<std::complex<double>> k){
    //TODO : voir un peu mieux comment trouver ces valeurs
    std::complex<double> res =0.0;
 /*   double A = 3.0;
    // vitesse du vent
    double V = 3.0;
    double g = 9.8;
    double L = V*V/g;

    res = A * (std::exp(-1.0/(k.norm()*L*k.norm()*L))/(k.norm()*k.norm()));
    Vector<std::complex<double>> w(1);
    w(0) = std::complex<double> (w(k),0.0));
    FFT(w);
    FFT(k);
    std::complex<double> dot = w*k;
    res += (dot*dot).real();

    iFFT(k);*/
    return res;
}


std::complex<double> PhilipsWaveModel::operator()(int n, int m, double t){
    int N = height.getNx();
    int M = height.getNy();
    double Lx = height.getLx();
    double Ly = height.getLy();
    if(abs(n)>N/2 && abs(m)>M/2){
        throw std::invalid_argument("mauvais argument pour le modèle de Philips n ou m hors des bornes");
    }
    Vector<std::complex<double>> x(2);
    x(0) = std::complex<double>((double)n*Lx/N,0.0);
    x(1) = std::complex<double>((double)m*Ly/M,0.0);
    Vector<std::complex<double>> k(2);

    std::complex<double> i(0.0,1.0);
    std::complex<double> h(0.0,0.0);

    std::complex<double> h_tilde(0.0,0.0);
    double ksi_i=0.0, ksi_r=0.0;

    for (int i=-N/2; i<N/2+1;i++){
        for (int j=-M/2; i<M/2+1;j++){
            k(0) = std::complex<double>((double)2*M_PI*i/Lx,0.0);
            k(1) = std::complex<double>((double)2*M_PI*j/Ly,0.0);

            ksi_i = getGauss(0.0,1.0);
            ksi_i = getGauss(0.0,1.0);
            h_tilde = 1/sqrt(2.0) * (ksi_r + i*ksi_i)*exp(i*w(k)*t*sqrt(P(k)));
            h_tilde += 1/sqrt(2.0) * (ksi_r - i*ksi_i)*exp(i*w(k)*t*sqrt(P(-k)));
            //A DEBUG
           // h += h_tilde* std::exp(i*k*x);
        }
    }
    return h;
}
