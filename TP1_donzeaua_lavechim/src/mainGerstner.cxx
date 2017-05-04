#include <GL/glut.h>
#include <iostream>
#include "Ocean.h"
#include "GerstnerWaveModel.h"
#include "Height.h"
#include "Vector.h"
#include "GerstnerWave.h"

/** @todo Inclure les fichiers de définition du problème */

#include "window.hxx"
#include "camera.hxx"
#include "gl_defs.hxx"

Ocean* ocean;
int mainwindow;

using namespace std;
int main(int argc, char** argv) {

  /** Initialiser des paramètres de simulation */
  double dirV = 3.1415;
  double alignV = 5;
  double inten = 1;
  double lambda = 5;
  double ajustV = 20;

  /** Initialiser du modèle*/
  //Création des ondes de Gerstner
  Vector<double> x1(2,1);
  Vector<double> vectOnde1(2,4);
  GerstnerWave onde1(x1, vectOnde1, 2, 1);

  Vector<double> x2(2,3);
  Vector<double> vectOnde2(2,3);
  GerstnerWave onde2(x2, vectOnde2, 10, 10);

  //Création du modèle de Gerstner
  GerstnerWaveModel GWM(dirV, alignV, inten, lambda , ajustV);
  GWM.addGerstnerWave(onde1);
  GWM.addGerstnerWave(onde2);

  /** Initialiser du champ de hauteur */
  double Lx = 500;
  double Ly = 500;
  unsigned int nx = 250;
  unsigned int ny = 250;
  Height H(Lx, Ly, nx, ny);

  /** Initialiser de l'océan */
  ocean = new Ocean(Lx, Ly, nx, ny, 0, H, GWM);
  ocean->generateHeight(50);

  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);

  /* Execute la simulation */
  Window::launch();

  /* Libère la mémoire */
  Window::quit();
  delete ocean;

  return 0;

}
