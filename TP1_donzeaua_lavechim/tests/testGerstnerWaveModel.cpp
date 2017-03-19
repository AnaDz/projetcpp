#include <iostream>
#include <assert.h>
#include "GerstnerWaveModel.h"
#include <sstream>

using namespace std;

int main() {

	std::stringstream str;
  list<GerstnerWave> listGWM;
  GerstnerWaveModel GWM(0,0,0,0,0,listGWM);
  GWM.display(str);
  std::cout << str.str();

	return 0;
}
