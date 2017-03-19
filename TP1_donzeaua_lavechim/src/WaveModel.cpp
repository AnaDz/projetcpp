#include "WaveModel.h"

WaveModel::WaveModel(double dirV, double alignV, double intens, double lambda, double ajust) {
    this->directionVent = dirV;
    this->alignementVent = alignV;
    this->intensite = intens;
    this->ajustVague = ajust;
    this->longueurOnde = lambda;
}

double WaveModel::getAjustementVague() {
    return this->ajustVague;
}

double WaveModel::getAlignementVent() {
    return this->alignementVent;
}

double WaveModel::getDirectionVent() {
    return this->directionVent;
}

double WaveModel::getIntensite() {
    return this->intensite;
}

double WaveModel::getLongueurOnde() {
    return this->longueurOnde;
}

void WaveModel::display(std::ostream& str) {
    str << "Direction du vent : ";
    str << this->directionVent << "\n";
    str << "Alignement avec le vent : ";
    str << this->alignementVent << "\n";
    str << "Intensité : " << this->intensite << "\n";
    str << "Longueur d'onde : " << this->longueurOnde << "\n";
    str << "Ajustement de la vague : " << this->ajustVague << "\n";
}

void WaveModel::init_param(double dirV, double alignV,double inten, double lambda, double ajustV){
  directionVent = dirV; // entre  et 2*pi
  alignementVent = alignV;
  intensite = inten;
  longueurOnde = lambda;
  ajustVague = ajustV;
}

 WaveModel::~WaveModel() {

 }
