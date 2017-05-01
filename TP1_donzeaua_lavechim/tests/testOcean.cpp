#include "Ocean.h"
#include "GerstnerWave.h"
#include "GerstnerWaveModel.h"
#include <iostream>
#include <assert.h>
#include <sstream>

using namespace std;

int main() {

	std::stringstream str;

    //Création du modèle
    //Création des ondes de Gerstner
    Vector<double> x1(2,1);
    Vector<double> vectOnde1(2,4);
    GerstnerWave onde1(x1, vectOnde1, 2, 20);

    Vector<double> x2(2,8);
    Vector<double> vectOnde2(2,3);
    GerstnerWave onde2(x2, vectOnde2, 4, 40);

    //Création du modèle de Gerstner
    GerstnerWaveModel GWM(45,0,0,0,0);
    GWM.addGerstnerWave(onde1);
    GWM.addGerstnerWave(onde2);

    //Création de Océan
    double Lx = 10;
    double Ly = 10;
    unsigned int nx = 2;
    unsigned int ny = 2;
    Height H(Lx, Ly, nx, ny);
    Ocean testOcean(Lx, Ly, nx, ny, 0, H, GWM);

    //Test de gl_vertices
    testOcean.gl_vertices();
    str.str("");
    testOcean.print_vertices(str);
    assert(str.str() == "[ 0 0 0 ]\n[ 5 0 0 ]\n[ 10 0 0 ]\n[ 0 5 0 ]\n[ 5 5 0 ]\n[ 10 5 0 ]\n[ 0 10 0 ]\n[ 5 10 0 ]\n[ 10 10 0 ]\n\n");
    std::cout << "gl_vertices() : OK\n";


  return 0;
}
