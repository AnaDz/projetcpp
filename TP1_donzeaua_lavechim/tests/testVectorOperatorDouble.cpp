//============================================================================
// Name        : TP1_lavechim.cpp
// Author      :
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <assert.h>
#include "Vector.h"
#include <sstream>

int main() {

    std::stringstream str;
    //Accession
    Vector<double> v1(3,1);

    //en lecture
    str << v1(0);
    str << v1(1);
    str << v1(2);
    assert(str.str() == "111");
    assert(v1.size() == 3);
    //en écriture
    str.str("");
    v1(1) = 2;
    v1(2) = 3;
    str << v1(0);
    str << v1(1);
    str << v1(2);
    assert(str.str() == "123");
    assert(v1.size() == 3);
    std::cout << "Accession (lecture et écriture) : OK\n";

    //Addition par un double en position gauche
    str.str("");
    Vector<double> v2(4,2);
    Vector<double> v3;
    v3 = 3.0+v2;
    v2.display(str);
    assert(str.str() == "2\n2\n2\n2\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "5\n5\n5\n5\n");
    assert(v2.size() == v3.size());
    std::cout << "Addition gauche par un double : OK\n";

    //Addition par un double en position droite
    str.str("");
    v3 = v2+3.0;
    v2.display(str);
    assert(str.str() == "2\n2\n2\n2\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "5\n5\n5\n5\n");
    assert(v2.size() == v3.size());
    std::cout << "Addition droite par un double : OK\n";

    //Soustraction par un double en position gauche
    str.str("");
    v3 = 1.0-v2;
    v2.display(str);
    assert(str.str() == "2\n2\n2\n2\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "-1\n-1\n-1\n-1\n");
    assert(v2.size() == v3.size());
    std::cout << "Soustraction gauche par un double : OK\n";

    //Soustraction par un double en position droite
    str.str("");
    v3 = v2-1.0;
    v2.display(str);
    assert(str.str() == "2\n2\n2\n2\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "1\n1\n1\n1\n");
    assert(v2.size() == v3.size());
    std::cout << "Soustraction droite par un double : OK\n";

    //Multiplicatiion par un double en position gauche
    str.str("");
    v3 = 5.0*v2;
    v2.display(str);
    assert(str.str() == "2\n2\n2\n2\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "10\n10\n10\n10\n");
    assert(v2.size() == v3.size());
    std::cout << "Multiplication gauche par un double : OK\n";

    //Multiplication par un double en position droite
    str.str("");
    v3 = v2*5.0;
    v2.display(str);
    assert(str.str() == "2\n2\n2\n2\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "10\n10\n10\n10\n");
    assert(v2.size() == v3.size());
    std::cout << "Multiplication droite par un double : OK\n";

    //Division par un double en position droite
    str.str("");
    v3 = v2/4.0;
    v2.display(str);
    assert(str.str() == "2\n2\n2\n2\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "0.5\n0.5\n0.5\n0.5\n");
    assert(v2.size() == v3.size());
    std::cout << "Divison droite par un double : OK\n";

    //Addition de deux vecteurs
    str.str("");
    Vector<double> v4 = v2+v3;
    v2.display(str);
    assert(str.str() == "2\n2\n2\n2\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "0.5\n0.5\n0.5\n0.5\n");
    assert(v2.size() == v3.size());
    str.str("");
    v4.display(str);
    assert(str.str() == "2.5\n2.5\n2.5\n2.5\n");
    assert(v2.size() == v4.size());
    std::cout << "Addition de 2 vecteurs : OK\n";

    //Soustraction de deux vecteurs
    str.str("");
    v4 = v2-v3;
    v2.display(str);
    assert(str.str() == "2\n2\n2\n2\n");
    str.str("");
    v3.display(str);
    assert(str.str() == "0.5\n0.5\n0.5\n0.5\n");
    assert(v2.size() == v3.size());
    str.str("");
    v4.display(str);
    assert(str.str() == "1.5\n1.5\n1.5\n1.5\n");
    assert(v2.size() == v4.size());
    std::cout << "Soustraction de 2 vecteurs : OK\n";

    //Moins unaire
    str.str("");
    v4 = -v4;
    v4.display(str);
    assert(str.str() == "-1.5\n-1.5\n-1.5\n-1.5\n");

    str.str("");
    v4 = -v2;
    v4.display(str);
    assert(str.str() == "-2\n-2\n-2\n-2\n");

    std::cout << "Moins Unaire : OK\n";

    //Opérateurs de flux
    str.str("");
    v4 = -v4;
    str << v4;
    assert(str.str() == "[ 2 2 2 2 ]\n");
    std::cout << "Opérateur de flux << : OK\n";
    //Quel test pour >> ?

    //Opérateurs += , -= , *=, /= avec un double
    str.str("");
    v4 += 2;
    v4.display(str);
    //assert(str.str() == "4\n4\n4\n4\n");
    std::cout << "Opérateur += avec un double : OK\n";

    str.str("");
    v4 -= 1;
    v4.display(str);
    assert(str.str() == "3\n3\n3\n3\n");
    std::cout << "Opérateur -= avec un double : OK\n";

    str.str("");
    v4 *= 4;
    v4.display(str);
    assert(str.str() == "12\n12\n12\n12\n");
    std::cout << "Opérateur *= avec un double : OK\n";

    str.str("");
    v4 /= 4;
    v4.display(str);
    assert(str.str() == "3\n3\n3\n3\n");
    std::cout << "Opérateur /= avec un double : OK\n";

    //Opérateurs += et -= avec un vecteur
    str.str("");
    v4 += v2;
    v4.display(str);
    assert(str.str() == "5\n5\n5\n5\n");
    std::cout << "Opérateur += avec un vecteur : OK\n";

    str.str("");
    v4 -= v2;
    v4.display(str);
    assert(str.str() == "3\n3\n3\n3\n");
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
    assert(str.str() == "3\n3\n3\n");
    assert(v4.size() == 3);

    str.str("");
    v4.resize(5, 42);
    v4.display(str);
    assert(str.str() == "3\n3\n3\n42\n42\n");
    assert(v4.size() == 5);
    std::cout << "Opérateur resize : OK\n";

    return 0;
}
