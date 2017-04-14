/*
 * Dvector.h
 *
 *  Created on: 3 Mars 2017
 *      Author: marvin
 */

#ifndef HEIGHT_H_
#define HEIGHT_H_
#include "Vector.h"
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
		Vector<double> hauteurs;

		void init(double Lx, double Ly, int nx, int ny);

	public:
	//Constructeurs et méthodes d'initialisation

		Height();
		Height(const Height & h);
		Height(double Lx,double Ly,int nx,int ny);
		Height(double Lx, double Ly, int nx, int ny, const Vector<double> &v);

		void fill(const Vector<double> &v);

		//Opérateurs
			//accesseurs
		double const & operator()(double x, double y) const;
		double & operator()(double x, double y);

			//recopie
		Height & operator=(const Height &h);

			//égalité
		bool operator==(const Height &v);

		//Accesseurs
		double getLx() const;
		double getLy() const;
		int getNx() const;
		int getNy() const;
		void display(std::ostream& str) const;

};

//flux
std::ostream & operator<<(std::ostream &Out, const Height &h);


#endif /* HEIGHT_H_ */
