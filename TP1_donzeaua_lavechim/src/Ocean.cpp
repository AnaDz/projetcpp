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
  this->Lx = oce.Lx;
  this->Ly = oce.Ly;
  this->nx = oce.nx;
  this->ny = oce.ny;
  this->t = oce.t;
  this->H = oce.H;
  this->Model = oce.Model;
  this->vertices = oce.vertices;
}


//Opérateurs
Ocean & Ocean::operator=(const Ocean & O) {
  if(*this == O) {
    return *this;
  }
  this->Lx = O.Lx;
  this->Ly = O.Ly;
  this->nx = O.nx;
  this->ny = O.ny;
  this->t = O.t;
  this->H = O.H;
  if(this->Model != nullptr) {
    delete this->Model;
  }
  this->Model = O.Model;
  this->vertices = O.vertices;
  return *this;
}

bool Ocean::operator==(const Ocean &O) const {
  if(this->H == O.H && this->vertices == O.vertices) { //On compare Lx,Ly,nx,ny avec la comp de H
    return true;
  }
  return false;
}

void Ocean::generateHeight(double d) {
  Vector<double> fill((nx+1)*(ny+1), d);
  H.fill(fill);
}

void Ocean::compute(int t) {
  for(unsigned int i = 0; i <= nx; i++) {
    for(unsigned int j = 0; j <= ny; j++) {
      H(i*Lx/nx, j*Ly/ny) = (*Model)(i*Lx/nx, j*Ly/ny, t);
    }
  }
}

void Ocean::init_vertices() {
    for(unsigned int i = 0; i < vertices.size(); i++) {
        vertices[i].resize(3, 0);
    }
}

void Ocean::gl_vertices() {
    for(unsigned int i = 0; i <= nx; i++) {
        for(unsigned int j = 0; j <= ny; j++) {
            vertices[i+(nx+1)*j](2) = H(i*Lx/nx, j*Ly/ny);
            vertices[i+(nx+1)*j](1) = j*Lx/nx;
            vertices[i+(nx+1)*j](0) = i*Ly/ny;
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

  double Ocean::getLx() {
    return Lx;
  }
  
  double Ocean::getLy() {
    return Ly;
  }

  unsigned int Ocean::getNx() {
    return nx;
  }

  unsigned int Ocean::getNy() {
    return ny;
  }
//Destructeur
Ocean::~Ocean(){
}
