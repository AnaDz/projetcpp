/*
 * Dvector.h
 *
 *  Created on: 3 Mars 2017
 *      Author: marvin
 */

#ifndef HEIGHT_H_
#define HEIGHT_H_
#include "Dvector.h"
#include <ostream>
#include <istream>
#include <iostream>
#include <stdexcept>

class Height {
	
	private:
	double Lx;
	double Ly;
	int nx;
	int ny;
	Dvector hauteurs;
	
	public:
	
	//Constructeurs et méthodes d'initialisation
	Height() ;
	Height(double Lx,double Ly,int nx,int ny);
	
	void fill(const Dvector &v);
	
	//Opérateurs
	double & operator()(int i, int j);
	
	//Accesseurs
	double getLx() const;
	double getLy() const;
	int getNx() const;
	int getNy() const;
	void display(std::ostream& str) const;
	
};

#endif /* HEIGHT_H_ */
