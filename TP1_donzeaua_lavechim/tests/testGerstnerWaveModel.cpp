#include <iostream>
#include <assert.h>
#include "GerstnerWaveModel.h"
#include "GerstnerWave.h"
#include "Vector.h"
#include <sstream>

using namespace std;

int main() {

	std::stringstream str;

	//Création des ondes de Gerstner
	Vector<double> x1(2,1);
	Vector<double> vectOnde1(2,4);
	GerstnerWave onde1(x1, vectOnde1, 2, 20);

	Vector<double> x2(2,8);
	Vector<double> vectOnde2(2,3);
	GerstnerWave onde2(x2, vectOnde2, 4, 40);

	//Création du modèle
  	GerstnerWaveModel GWM(45,0,0,0,0);
	GWM.addGerstnerWave(onde1);
	GWM.addGerstnerWave(onde2);

	GWM.display(str);
	std::cout << str.str();

	return 0;
}
