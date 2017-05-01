#include "Ocean.h"
#include <ostream>
#include <istream>
#include <iostream>
#include <stdexcept>

using namespace std;

//Constructeurs
Ocean::Ocean(double Lx, double Ly, unsigned int nx, unsigned int ny, double t, Height H, WaveModel & Model) {
  this->Lx = Lx;
  this->Ly = Ly;
  this->nx = nx;
  this->ny = ny;
  this->t = t;
  if(H.getLx() != Lx || H.getLy() != Ly || H.getNx() != nx || H.getNy() != ny) {
    exit(-1);
  }
  this->H = H;
  this->Model = &Model;
  this->vertices = vector<Vector<double>>((nx+1)*(ny+1));
  init_vertices();
}

Ocean::Ocean(WaveModel & Model) {
  Lx = 100;
  Ly = 100;
  nx = 500;
  ny = 500;
  t = 0;
  Height Hei(Lx, Ly, nx, ny);
  Ocean(Lx,Ly,nx,ny, t, H, Model);
}

Ocean::Ocean(const Ocean & oce) {
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

void Ocean::init_vertices() {
    for(unsigned int i = 0; i < vertices.size(); i++) {
        vertices[i].resize(3, 0);
    }
}

void Ocean::gl_vertices() {
    for(unsigned int i = 0; i <= nx; i++) {
        for(unsigned int j = 0; j <= ny; j++) {
            vertices[i+(nx+1)*j](2) = H(i*10/nx, j*10/ny);
            vertices[i+(nx+1)*j](1) = j*10/nx;
            vertices[i+(nx+1)*j](0) = i*10/ny;
        }
    }
}

ostream & Ocean::print_vertices(ostream& str) {
  for(unsigned int i = 0; i < vertices.size(); i++) {
    str << vertices[i];
  }
  str << endl;
  return str;
}

//Destructeur
Ocean::~Ocean(){
}
