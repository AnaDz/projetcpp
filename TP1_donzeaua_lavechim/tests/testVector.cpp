#include <iostream>
#include <assert.h>
#include "Vector.h"
#include <sstream>

//Fichier de test
//du template Vector
//Constructeurs

int main() {

	  std::stringstream str;
    Vector<double> v1;
  	assert(v1.size() == 0);
  	v1.display(str);
  	assert(str.str() == "");
  	std::cout << "Constructeur par défaut : OK\n";

  	str.str("");
  	Vector<double> v2(3);
  	assert(v2.size() == 3);
  	v2.display(str);

  	assert(str.str() == "0\n0\n0\n");
  	std::cout << "Constructeur avec taille : OK\n";

  	str.str("");
  	Vector<double> v3(3, 2.5);
  	assert(v3.size() == 3);
  	v3.display(str);
  	assert(str.str() == "2.5\n2.5\n2.5\n");
  	std::cout << "Constructeur avec taille et valeur : OK\n";

  	str.str("");
  	Vector<double> v4(v3);
  	assert(v4.size() == 3);
  	v4.display(str);
  	assert(str.str() == "2.5\n2.5\n2.5\n");
  	std::cout << "Constructeur par copie : OK\n";

  	str.str("");
  	Vector<double> v5("../tests/testFile.txt");
  	assert(v5.size() == 10);
  	v5.display(str);
  	std::cout << "Constructeur avec lecture de fichier : OK\n";

  	return 0;
}
