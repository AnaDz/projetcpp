#ifndef OCEAN_H
#define OCEAN_H

#include "WaveModel.h"
#include "Height.h"
#include <vector>
#include "Vector.h"
#include <ostream>
using namespace std;

class Ocean {

private:
    double Lx;        // longueur du domaine dans la direction x
    double Ly;        // longueur du domaine dans la direction y
    unsigned int nx;           // nombre de pts de discrétisation du domaine dans la direction x
    unsigned int ny;           // nombre de pts de discrétisation du domaine dans la direction y
    double t;         // le temps courant
    Height H;         // la hauteur de la houle
    WaveModel *Model;  // le modèle utilisé
    vector<Vector<double>> vertices; //tableau dynamique de vecteur de dimension 3

public:

    //Constructeurs
    Ocean(double Lx, double Ly, unsigned int nx, unsigned int ny, double t, Height H, WaveModel &Model);
    Ocean(WaveModel &Model);
    Ocean(const Ocean & O);

    //Opérateurs
    Ocean & operator =(const Ocean &oce);
    bool operator==(const Ocean &O) const;
    void generateHeight(double d);
    void compute();
    void init_vertices();
    void gl_vertices();

    ostream & print_vertices(ostream& str);

    double getLx();
    double getLy();
    unsigned int getNx();
    unsigned int getNy();

    void init_gl_VertexArrayX(const int y, double* const vertices) const;


    void init_gl_VertexArrayY(const int x, double* const vertices) const;

    void gl_VertexArrayX(const int y, double* const vertices) const;

    void gl_VertexArrayY(const int x, double* const vertices) const;

    //Destructeur
    ~Ocean();
};
#include "ocean.hxx"
#endif //OCEAN_H
