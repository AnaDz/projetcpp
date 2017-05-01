#include <iostream>
#include <assert.h>
#include "PhilipsWaveModel.h"
#include <sstream>

using namespace std;

int main() {

	std::stringstream str;
    double vent = M_PI;
    double alignementvent = 1;
    double vitesse = 3;
    double lambda = 1.2;
    double ajustementvague = 3;
    Height h = Height(10,10,2,2);
    PhilipsWaveModel phil(vent, alignementvent, vitesse, lambda, ajustementvague, h);
    double hauteur = phil(2,4, 5);
    std::cout<<"Calcul de la hauteur en 2,4 au temps 5 :";
    std::cout<< hauteur << "\n";
    std::cout<< "Height a : " ;
    std::cout<<phil.getH()(1,2)<<"\n";
    h.display(std::cout);
	return 0;
}
