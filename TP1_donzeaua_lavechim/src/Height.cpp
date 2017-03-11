/*
 * Height.cpp
 *
 *  Created on: 3 Mars 2017
 *      Author: marvin
 */

#include "Height.h"

//Constructeurs et méthodes d'initialisation
Height::Height() {
	Lx = 0;
	Ly = 0;
	nx = 0;
	ny = 0;
}

Height::Height(double Lx, double Ly, int nx, int ny) {
	this->Lx = Lx;
	this->Ly = Ly;
	this->nx = nx;
	this->ny = ny;
	
	hauteurs = Dvector(nx*ny);
}

void Height::fill(const Dvector &v) {
	if(v.size() != nx*ny) {
		throw std::invalid_argument("Vous essayez d'initialiser une matrice de hauteurs avec un vecteur qui possède une taille incompatible.\n");
	} else {
		hauteurs = Dvector(v);
	}
}

//Opérateurs

double & Height::operator() (int i, int j) {
	if( (i < 0 || i >= nx) || (j < 0 || j >= ny) ) {
		throw std::invalid_argument("Vous essayez d'accéder à un élément en dehors de la matrice de hauteurs.\n");
	} else {
		return hauteurs(i*nx+j);
	}
}
//Accesseurs et utilitaires
double Height::getLx() const {
	return Lx;
}

double Height::getLy() const {
	return Ly;
}

int Height::getNx() const {
	return nx;
}

int Height::getNy() const {
	return ny;
}

void Height::display(std::ostream& str) const {
	//double fixed;
	str << " ";
	for(int i = 0; i < nx; i++) {
		for(int j = 0; j < ny; j++) {
			str << hauteurs(i*nx+j) << " ";
		}
		str << "\n ";
	}
}

