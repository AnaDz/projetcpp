#include <iostream>
#include <assert.h>
#include "Vector.h"
#include <sstream>

//Fichier de test
//du template Vector
//Constructeurs

int main() {

    Vector<double> v1(30000000,5.0);

    Vector<double> v2 = v1;
    return 0;
}

