#ifndef OCEAN_H
#define OCEAN_H

#include "WaveModel.h"
#include "Height.h"
#include <vector>

using namespace std;

class Ocean {

private:
    double Lx;        // longueur du domaine dans la direction x
    double Ly;        // longueur du domaine dans la direction y
    int nx;           // nombre de pts de discrétisation du domaine dans la direction x
    int ny;           // nombre de pts de discrétisation du domaine dans la direction y
    double t;         // le temps courant
    Height H;         // la hauteur de la houle
    WaveModel *Model;  // le modèle utilisé
    vector<double> vertices;

public:

    //Constructeurs
    Ocean(double Lx, double Ly, int nx, int ny, double t, Height H, WaveModel & Model, vector<double> vertices);
    Ocean(WaveModel & Model);
    Ocean(const Ocean & O);
    Ocean();

    //Opérateurs
    Ocean & operator=(const Ocean & O);


    //Destructeur
    ~Ocean();
};

#endif //OCEAN_H
