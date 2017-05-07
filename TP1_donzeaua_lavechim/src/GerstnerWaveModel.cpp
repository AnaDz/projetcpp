#include "GerstnerWaveModel.h"

GerstnerWaveModel::GerstnerWaveModel(double dirV, double alignV, double inten,double lambda, double ajustV) {
  init_param(dirV, alignV, inten, lambda, ajustV);
}

GerstnerWaveModel::GerstnerWaveModel(double dirV, double alignV, double inten, double lambda, double ajustV, list<GerstnerWave> listGerWave) {
  init_param(dirV, alignV, inten, lambda, ajustV);
  this->listGerWave = listGerWave;
}


void GerstnerWaveModel::addGerstnerWave(const GerstnerWave & W){
    this->listGerWave.push_back(W);
}

double GerstnerWaveModel::operator()(double x, double y, double t) {
  double res = 0;
  std::list<GerstnerWave>::iterator i;
  for(i = listGerWave.begin(); i != listGerWave.end(); i++) {
    res += (*i).computeHeight(x, y, t);
  }
  return res;
}

GerstnerWaveModel::~GerstnerWaveModel() {
  this->listGerWave.clear();
}

void GerstnerWaveModel::display(std::ostream& str) {
  std::cout << "Ce modèle de houle de Gerstner contient les paramètres suivants :\n";
  std::cout << "Direction du vent : " << this->directionVent << "\n";
  std::cout << "Alignement du vent  : " << this->alignementVent << "\n";
  std::cout << "Intensité du vent : " << this->intensite << "\n";
  std::cout << "Ajustement des vagues : " << this->ajustVague << "\n";
  std::cout << "Longueur d'ondes : " << this->longueurOnde << "\n";

  std::cout << "Et les ondes suivantes : \n";
  std::list<GerstnerWave>::iterator i;
  for(i = listGerWave.begin(); i != listGerWave.end(); i++) {
    (*i).display(str);
  }
}
void GerstnerWaveModel::printtype() {
  std::cout << "Gerstner" << std::endl;
}
