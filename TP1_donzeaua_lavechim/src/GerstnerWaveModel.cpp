#include "GerstnerWaveModel.h"

//GerstnerWaveModel::GerstnerWaveModel(Dvector X_0 = 0, Dvector vectOnde = 0, double phase = 0, double ampli = 0, const list<GerstnerWave> & listGerWave = list<GerstnerWave>()) : WaveModel(dirV, alignV, intens, lambda, just) {

GerstnerWaveModel::GerstnerWaveModel(double dirV, double alignV, double inten,double lambda, double ajustV)
{
  init_param(dirV, alignV, inten, lambda, ajustV);
}

GerstnerWaveModel::GerstnerWaveModel(double dirV, double alignV, double inten, double lambda, double ajustV, list<GerstnerWave> listGerWave)
{
  init_param(dirV, alignV, inten, lambda, ajustV);
  this->listGerWave = listGerWave;
}


void GerstnerWaveModel::addGerstnerWave(const GerstnerWave & W){
    this->listGerWave.push_back(W);
}

double GerstnerWaveModel::operator()(double x, double y, double t) {
  std::cout << "Not implemented yet\n";
  double res = 0;
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
}
