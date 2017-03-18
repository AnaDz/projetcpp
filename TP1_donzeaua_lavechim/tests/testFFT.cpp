#include <iostream>
#include <cassert>
#include "Vector.h"
#include <sstream>
#include <complex>

int main(){
    std::complex<double> c1(1.8,2.6);
    std::stringstream str;
    Vector<std::complex<double>> v1(8,c1);
    Vector<std::complex<double>> v2(v1);
    FFT(v1);
    iFFT(v1);
    assert(v1==v2);
    std::cout<<"FFT + iFFT donne le résultat initial \n";

}