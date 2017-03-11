/*
 * Height.cpp
 *
 *  Created on: 3 Mars 2017
 *      Author: marvin
 */

#include "Height.h"
#include <math.h>
//Constructeurs et méthodes d'initialisation
void Height::init(double Lx, double Ly, int nx, int ny) {
	this->Lx = Lx;
	this->Ly = Ly;
	this->nx = nx;
	this->ny = ny;
}

Height::Height() {
	this->init(0,0,0,0);
}

Height::Height(const Height & h) {
  this->init(h.Lx, h.Ly, h.nx, h.ny);
	hauteurs = Dvector(h.hauteurs);
}

Height::Height(double Lx, double Ly, int nx, int ny) {
	this->init(Lx, Ly, nx, ny);
	hauteurs = Dvector((nx+1)*(ny+1));
}

Height::Height(double Lx, double Ly, int nx, int ny, const Dvector &v) {
	this->init(Lx,Ly,nx,ny);
	hauteurs = Dvector((nx+1)*(ny+1));
	this->fill(v);
}

void Height::fill(const Dvector &v) {
	if(v.size() != (nx+1)*(ny+1)) {
		throw std::invalid_argument("Vous essayez d'initialiser une matrice de hauteurs avec un vecteur qui possède une taille incompatible.\n");
	} else {
		hauteurs = Dvector(v);
	}
}

//Opérateurs

double const & Height::operator() (double x, double y, double t) const {
	if( (x < 0 || x > Lx) || (y < 0 || y > Ly) ) {
		throw std::invalid_argument("Vous essayez d'accéder à un élément en dehors de la matrice de hauteurs.\n");
	} else {
		int i = floor(x*nx/Lx);
		int j = floor(y*ny/Ly);
		return hauteurs(i*nx+j); //que faire de t ?
	}
}

//Opérateurs de flux
std::ostream & operator <<(std::ostream &Out, const Height &h){

	double x;
	double y;
	int nx = h.getNx();
	int ny = h.getNy();
	double Lx = h.getLx();
	double Ly = h.getLy();
	for(int i=0; i <= nx ; i++) {
    for(int j=0; j <= ny; j++) {
    	x = i*Lx/nx;
    	y = j*Ly/ny;
    	Out<<"("<< x <<","<< y << "," << h(x,y,0) <<")\n";	//que faire du temps ?
    }
  }

  Out<<std::endl;
  return Out;
}



//Accesseurs et utilitaires
double Height::getLx() const{
	return Lx;
}

double Height::getLy() const{
	return Ly;
}

int Height::getNx() const{
	return nx;
}

int Height::getNy() const{
	return ny;
}

void Height::display(std::ostream& str) const {
	//double fixed;
	str << " ";
	for(int i = 0; i <= nx; i++) {
		for(int j = 0; j <= ny; j++) {
			str << hauteurs(i*nx+j) << " ";
		}
		str << "\n ";
	}
}

