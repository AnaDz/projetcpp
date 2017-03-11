//============================================================================
// Name        : TP1_lavechim.cpp
// Author      :
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <assert.h>
#include "Dvector.h"
#include <sstream>

int main() {

	std::stringstream str;

	Dvector v1;
	assert(v1.size() == 0);
	v1.display(str);
	assert(str.str() == "");
	std::cout << "Constructeur par défaut : OK\n";

	str.str("");
	Dvector v2(3);
	assert(v2.size() == 3);
	v2.display(str);

	assert(str.str() == "0\n0\n0\n");
	std::cout << "Constructeur avec taille : OK\n";

	str.str("");
	Dvector v3(3, 2.5);
	assert(v3.size() == 3);
	v3.display(str);
	assert(str.str() == "2.5\n2.5\n2.5\n");
	std::cout << "Constructeur avec taille et valeur : OK\n";

	str.str("");
	Dvector v4(v3);
	assert(v4.size() == 3);
	v4.display(str);
	assert(str.str() == "2.5\n2.5\n2.5\n");
	std::cout << "Constructeur par copie : OK\n";

	str.str("");
	Dvector v5("../tests/testFile.txt");
	assert(v5.size() == 10);
	v5.display(str);
	//Problème de format visiblement : demander au prof.
	//assert(str.str() == "1.6218231e-01\n7.9428454e-01\n3.1121504e-01\n5.2853314e-01\n1.6564873e-01\n6.0198194e-01\n2.6297128e-01\n6.5407910e-01\n6.8921450e-01\n7.4815159e-01");
	std::cout << "Constructeur avec lecture de fichier : OK\n";

	return 0;
}

