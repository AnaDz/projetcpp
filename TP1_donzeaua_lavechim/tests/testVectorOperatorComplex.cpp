
#include <iostream>
#include <cassert>
#include "Vector.h"
#include <sstream>
#include <complex>

int main() {

    std::complex<double> c1(1.0,2.0);
    std::stringstream str;
    //Accession
    Vector<std::complex<double>> v1(3,c1);

    //en lecture
    str << v1(0);
    str << v1(1);
    str << v1(2);
    assert(str.str() == "(1,2)(1,2)(1,2)");
    assert(v1.size() == 3);
    //en écriture
    str.str("");
    v1(1) = std::complex<double>(2.0,1.0);
    v1(2) = std::complex<double>(3.0,4.0);
    str << v1(0);
    str << v1(1);
    str << v1(2);
    assert(str.str() == "(1,2)(2,1)(3,4)");
    assert(v1.size() == 3);
    std::cout << "Accession (lecture et écriture) : OK\n";

    //Addition par un double en position gauche
    str.str("");
    Vector<std::complex<double>> v2(4,std::complex<double>(2.0,1.0));
    Vector<std::complex<double>> v3;
    v3 = std::complex<double>(3.0,0.0)+v2;
    v2.display(str);
    assert(str.str() == "( (2,1) (2,1) (2,1) (2,1) )\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "( (5,1) (5,1) (5,1) (5,1) )\n");
    assert(v2.size() == v3.size());
    std::cout << "Addition gauche par un double : OK\n";

    //Addition par un double en position droite
    str.str("");
    v3 = v2+std::complex<double>(3.0,1.0);
    v2.display(str);
    assert(str.str() == "( (2,1) (2,1) (2,1) (2,1) )\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "( (5,2) (5,2) (5,2) (5,2) )\n");
    assert(v2.size() == v3.size());
    std::cout << "Addition droite par un double : OK\n";

    //Soustraction par un double en position gauche
    str.str("");
    v3 = std::complex<double>(1.0,0.0)-v2;
    v2.display(str);
    assert(str.str() == "( (2,1) (2,1) (2,1) (2,1) )\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "( (-1,-1) (-1,-1) (-1,-1) (-1,-1) )\n");
    assert(v2.size() == v3.size());
    std::cout << "Soustraction gauche par un double : OK\n";

    //Soustraction par un double en position droite
    str.str("");
    v3 = v2-std::complex<double>(1.0,0.0);
    v2.display(str);
    assert(str.str() == "( (2,1) (2,1) (2,1) (2,1) )\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "( (1,1) (1,1) (1,1) (1,1) )\n");
    assert(v2.size() == v3.size());
    std::cout << "Soustraction droite par un double : OK\n";

    //Multiplicatiion par un double en position gauche
    str.str("");
    v3 = std::complex<double>(5.0,0.0)*v2;
    v2.display(str);
    assert(str.str() == "( (2,1) (2,1) (2,1) (2,1) )\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "( (10,5) (10,5) (10,5) (10,5) )\n");
    assert(v2.size() == v3.size());
    std::cout << "Multiplication gauche par un double : OK\n";

    //Multiplication par un double en position droite
    str.str("");
    v3 = v2*std::complex<double>(5.0,1.0);
    v2.display(str);
    assert(str.str() == "( (2,1) (2,1) (2,1) (2,1) )\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "( (9,7) (9,7) (9,7) (9,7) )\n");
    assert(v2.size() == v3.size());
    std::cout << "Multiplication droite par un double : OK\n";

    //Division par un double en position droite
    str.str("");
    v3 = v2/std::complex<double>(4.0,1.0);
    v2.display(str);
    assert(str.str() == "( (2,1) (2,1) (2,1) (2,1) )\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "( (0.529412,0.117647) (0.529412,0.117647) (0.529412,0.117647) (0.529412,0.117647) )\n");
    assert(v2.size() == v3.size());
    std::cout << "Divison droite par un double : OK\n";

    //Addition de deux vecteurs
    str.str("");
    v3 = Vector<std::complex<double>>(4,std::complex<double>(1.0,3.0));
    Vector<std::complex<double>> v4 = v2+v3;
    v2.display(str);
    assert(str.str() == "( (2,1) (2,1) (2,1) (2,1) )\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "( (1,3) (1,3) (1,3) (1,3) )\n");
    assert(v2.size() == v3.size());
    str.str("");
    v4.display(str);
    assert(str.str() == "( (3,4) (3,4) (3,4) (3,4) )\n");
    assert(v2.size() == v4.size());
    std::cout << "Addition de 2 vecteurs : OK\n";

    //Soustraction de deux vecteurs
    str.str("");
    v4 = v2-v3;
    v2.display(str);
    assert(str.str() == "( (2,1) (2,1) (2,1) (2,1) )\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "( (1,3) (1,3) (1,3) (1,3) )\n");
    assert(v2.size() == v3.size());
    str.str("");
    v4.display(str);
    assert(str.str() == "( (1,-2) (1,-2) (1,-2) (1,-2) )\n");
    assert(v2.size() == v4.size());
    std::cout << "Soustraction de 2 vecteurs : OK ";

    //Moins unaire
    str.str("");
    v4 = -v4;
    v4.display(str);
    assert(str.str() == "( (-1,2) (-1,2) (-1,2) (-1,2) )\n");

    str.str("");
    v4 = -v2;
    v4.display(str);
    assert(str.str() == "( (-2,-1) (-2,-1) (-2,-1) (-2,-1) )\n");

    std::cout << "Moins Unaire : OK\n";

    //Opérateurs de flux
    str.str("");
    v4 = -v4;
    str << v4;
    assert(str.str() == "[ (2,1) (2,1) (2,1) (2,1) ]\n");
    std::cout << "Opérateur de flux << : OK\n";
    //Quel test pour >> ?

    //Opérateurs += , -= , *=, /= avec un double
    str.str("");
    v4 += std::complex<double>(2,2);
    v4.display(str);
    assert(str.str() == "( (4,3) (4,3) (4,3) (4,3) )\n");
    std::cout << "Opérateur += avec un double : OK\n";

    str.str("");
    v4 -= std::complex<double>(1,1);
    v4.display(str);
    assert(str.str() == "( (3,2) (3,2) (3,2) (3,2) )\n");
    std::cout << "Opérateur -= avec un double : OK\n";

    str.str("");
    v4 *= std::complex<double>(2,0);
    v4.display(str);
    assert(str.str() == "( (6,4) (6,4) (6,4) (6,4) )\n");
    std::cout << "Opérateur *= avec un double : OK\n";

    str.str("");
    v4 /=std::complex<double>(2,0);
    v4.display(str);
    assert(str.str() == "( (3,2) (3,2) (3,2) (3,2) )\n");
    std::cout << "Opérateur /= avec un double : OK\n";

    //Opérateurs += et -= avec un vecteur
    str.str("");
    v4 += v2;
    v4.display(str);
    assert(str.str() == "( (5,3) (5,3) (5,3) (5,3) )\n");
    std::cout << "Opérateur += avec un vecteur : OK\n";

    str.str("");
    v4 -= v2;
    v4.display(str);
    assert(str.str() == "( (3,2) (3,2) (3,2) (3,2) )\n");
    std::cout << "Opérateur -= avec un vecteur : OK\n";

    //Opérateur de comparaison
    str.str("");
    str << (v4 == v2) << "\n";
    str << (v4 == v4) << "\n";
    assert(str.str() == "0\n1\n");
    std::cout << "Opérateur == : OK\n";

    //Resize
    str.str("");
    v4.resize(3);
    v4.display(str);
    assert(str.str() == "( (3,2) (3,2) (3,2) )\n");
    assert(v4.size() == 3);

    str.str("");
    v4.resize(5, std::complex<double>(2,0));
    v4.display(str);
    assert(str.str() == "( (3,2) (3,2) (3,2) (2,0) (2,0) )\n");
    assert(v4.size() == 5);
    std::cout << "Opérateur resize : OK\n";

    return 0;
}
