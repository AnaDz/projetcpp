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
	int nx; //nx correspond aux nombres d'intervalles, donc nx+1
	int ny;
	Dvector hauteurs;
	void init(double Lx, double Ly, int nx, int ny);

	public:
	//Constructeurs et méthodes d'initialisation

	Height();
	Height(const Height & h);
	Height(double Lx,double Ly,int nx,int ny);
	Height(double Lx, double Ly, int nx, int ny, const Dvector &v);

	void fill(const Dvector &v);

	//Opérateurs
	double const & operator()(double x, double y) const;
	double & operator()(double x, double y);
	//Accesseurs
	double getLx() const;
	double getLy() const;
	int getNx() const;
	int getNy() const;
	void display(std::ostream& str) const;

};

	//Opérateurs de flux
	std::ostream & operator<<(std::ostream &Out, const Height &h);
#endif /* HEIGHT_H_ */
