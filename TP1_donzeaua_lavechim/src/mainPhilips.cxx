#include <GL/glut.h>
#include <iostream>
#include "Ocean.h"
#include "PhilipsWaveModel.h"
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

  /** Initialiser du champ de hauteur */
  double Lx = 500;
  double Ly = 500;
  unsigned int nx = 250;
  unsigned int ny = 250;
  Height H(Lx, Ly, nx, ny);

  /** Initialiser du modèle*/
  PhilipsWaveModel phil(dirV, alignV, inten, lambda, ajustV, H);

  /** Initialiser de l'océan */
  ocean = new Ocean(Lx, Ly, nx, ny, 0, H, phil);
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
