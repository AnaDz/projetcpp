
#include "Height.h"
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
	Dvector v1(9, 200);
	h.fill(v1);
	h.display(str);
	assert(str.str() == " 200 200 200 \n 200 200 200 \n 200 200 200 \n ");
	std::cout << "Méthode fill à partir d'un vecteur : OK\n";

	str.str("");
	str << h(0,10) << " ";
	str << h(0,10) << " ";
	str << h(1,0) << " ";
	str << h(10,10);
	assert(str.str() == "200 200 200 200");
	std::cout << "Opérateur d'accession () : OK\n";


	str.str("");
	Dvector v2(9);
	std::stringstream str2;
	str2 << "1\n2\n3\n4\n5\n6\n7\n8\n9";
	str2 >> v2;
	Height h2(10, 10, 2, 2, v2);
	str << h2;
	assert(str.str() == "(0,0,1)\n(0,5,2)\n(0,10,3)\n(5,0,3)\n(5,5,4)\n(5,10,5)\n(10,0,5)\n(10,5,6)\n(10,10,7)\n\n");
	std::cout << "Opérateur de flux << : OK\n";
	return 0;
}
