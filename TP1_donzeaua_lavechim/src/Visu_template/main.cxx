#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Ocean.h"
#include "GerstnerWaveModel.h"
#include "

/** @todo Inclure les fichiers de définition du problème */

#include "window.hxx"
Ocean* ocean; 
int mainwindow;

int main(int argc, char** argv) {
  /** Initialiser des paramètres de simulation */
  double dirV = 3.1415;
  double alignV = 2;
  double inten = 5;
  double lambda = 5;
  double ajustV = 5;

  /** Initialiser du modèle*/
  //Création des ondes de Gerstner
  Vector<double> x1(2,1);
  Vector<double> vectOnde1(2,4);
  GerstnerWave onde1(x1, vectOnde1, 2, 20);

  Vector<double> x2(2,8);
  Vector<double> vectOnde2(2,3);
  GerstnerWave onde2(x2, vectOnde2, 4, 40);

  //Création du modèle de Gerstner
  GerstnerWaveModel GWM(dirV, alignV, inten, lambda , ajustV);
  GWM.addGerstnerWave(onde1);
  GWM.addGerstnerWave(onde2);

  /** Initialiser du champ de hauteur */
  double Lx = 10;
  double Ly = 10;
  unsigned int nx = 2;
  unsigned int ny = 2;
  Height H(Lx, Ly, nx, ny);

  /** Initialiser de l'océan */
  Ocean testOcean(Lx, Ly, nx, ny, 0, H, GWM);

  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);

  /* Execute la simulation */
  Window::launch();

  /* Libère la mémoire */
  Window::quit();
  delete ocean;

  return 0;

}
