#include <iostream>
#include <cassert>
#include "Vector.h"
#include <sstream>
#include <complex>

//Fichier de test
//du template Vector
//Constructeurs avec complexes

int main() {
    std::complex<double> c1(3.0,2.0);
    std::stringstream str;
    Vector<std::complex<double>> v1;
    assert(v1.size() == 0);
    v1.display(str);
    assert(str.str() == "");
    std::cout << "Constructeur par défaut : OK\n";

    str.str("");
    Vector<std::complex<double>> v2(3);
    assert(v2.size() == 3);
    v2.display(str);

    assert(str.str() == "(0,0)\n(0,0)\n(0,0)\n");
    std::cout << "Constructeur avec taille : OK\n";

    str.str("");
    Vector<std::complex<double>> v3(3, c1);
    assert(v3.size() == 3);
    v3.display(str);

    assert(str.str() == "(3,2)\n(3,2)\n(3,2)\n");
    std::cout << "Constructeur avec taille et valeur : OK\n";

    str.str("");
    Vector<std::complex<double>> v4(v3);
    assert(v4.size() == 3);
    v4.display(str);
    assert(str.str() == "(3,2)\n(3,2)\n(3,2)\n");
    std::cout << "Constructeur par copie : OK\n";

    str.str("");
    Vector<std::complex<double>> v5("../tests/testFile2.txt");
    assert(v5.size() == 6);
    v5.display(str);
    assert(str.str() == "(1,2)\n(1,2)\n(2,1)\n(1,2)\n(1,2)\n(1,2)\n");
    std::cout << "Constructeur avec lecture de fichier : OK\n";

    return 0;
}

