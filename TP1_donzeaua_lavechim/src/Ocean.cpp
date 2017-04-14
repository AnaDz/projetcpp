#include "Ocean.h"
#include <ostream>
#include <istream>
#include <iostream>
#include <stdexcept>

//Constructeurs
Ocean::Ocean(double Lx, double Ly, int nx, int ny, double t, Height H, WaveModel & Model, vector<double> vertices) {
  std::cout << "NOT IMPLEMENTED YET!\n";
}

Ocean::Ocean(WaveModel & Model) {
  std::cout << "NOT IMPLEMENTED YET!\n";
}

Ocean::Ocean(const Ocean & O) {
  std::cout << "NOT IMPLEMENTED YET!\n";
}

Ocean::Ocean() {
  std::cout << "NOT IMPLEMENTED YET!\n";
}

//Opérateurs
Ocean & Ocean::operator=(const Ocean & O) {
  std::cout << "NOT IMPLEMENTED YET!\n";
  return *this;
}

//Destructeur
Ocean::~Ocean(){
  std::cout << "NOT IMPLEMENTED YET!\n";
}
