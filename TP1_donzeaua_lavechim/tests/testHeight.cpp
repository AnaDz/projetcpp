
#include "Height.h"
#include "Dvector.h"
#include <iostream>
#include <assert.h>
#include <sstream>

int main() {

	std::cout << "Tests de la classe Height:\n";
	std::stringstream str;
	
	Height h(10, 10, 2, 2);
	str << h.getLx() << " " << h.getLy() << "\n";
	assert(str.str() == "10 10\n");
	std::cout << "Accesseurs Lx et Ly : OK\n";
	
	str.str("");
	str << h.getNx() << " " << h.getNy() << "\n";
	assert(str.str() == "2 2\n");
	std::cout << "Accesseurs Nx et Ny : OK\n";
	
	str.str("");
	Dvector v1(4, 5);
	h.fill(v1);
	h.display(str);
	assert(str.str() == " 5 5 \n 5 5 \n ");
	std::cout << "Méthode fill à partir d'un vecteur : OK\n";
	
	str.str("");
	str << h(0,0) << " ";
	str << h(0,1) << " ";
	str << h(1,0) << " ";
	str << h(1,1);
	assert(str.str() == "5 5 5 5");
	std::cout << "Opérateur d'accession () : OK\n";
	return 0;
}
