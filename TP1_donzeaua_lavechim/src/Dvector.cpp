#include "Dvector.h"
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <cstring>


void Dvector::init(int d){
  if (d>0) {
    dim = d;
    vect = new double[d];
  } else if(d==0){
    dim = d;
    vect = nullptr;
  } else{
    throw std::invalid_argument("La taille d'un vecteur doit être supérieure ou égale à 0");
  }
}

int Dvector::size() const{
  return dim;
}

Dvector::Dvector(){
  //std::cout << "__Constructeur simple__" << std::endl;
  dim = 0;
  vect = nullptr; //c++ 2011
}


Dvector::Dvector(int d, double v){
  //std::cout << "__Constructeur dim val__" << std::endl;
  this->init(d);
  for(int i = 0; i<dim; i++){
    vect[i] = v;
  }
}

Dvector::Dvector(const Dvector & V){
  //std::cout << "__Constructeur copie__" << std::endl;
  int d = V.dim;
  this->init(d);
  for(int i =0; i<dim; i++){
    vect[i] = V.vect[i];
  }
}

Dvector::Dvector(std::string file){
//  std::cout << "__Constructeur fichier__" << std::endl;
  std::ifstream fichier(file.c_str(), std::ios::in);
  if(fichier){
    int d = 0;
    double val;
    while (fichier>>val)
    {
        d++;
    }
    fichier.close();
    init(d);
  }else {
    init(0);
  }

  int i = 0;
  std::ifstream refichier(file.c_str(), std::ios::in);
  if(refichier){
    double val;
    while (refichier>>val)
    {
        vect[i] = val;
        i++;
    }
    refichier.close();
  }


}

Dvector::~Dvector(){
//  std::cout << "Destruction" << std::endl;
  delete [] vect;
}

void Dvector::display(std::ostream& str) {
  for(int i=0; i<dim; i++){
    str<<vect[i]<<"\n";
  }
}


void Dvector::fillRandomly(){
  srand(time(NULL));
  for(int i=0; i<dim;i++){
    vect[i]= double (rand());
    vect[i] = vect[i]/double (RAND_MAX);
  }
}

double& Dvector::operator()(int i){
  if(i<0 || i>= dim){
    throw std::invalid_argument("L'indice d'un vecteur doit être compris entre 0 et dim -1");
  } else {
    return vect[i];
  }
}

void Dvector::resize(int newDim){
  if (this->dim < newDim){
    throw std::invalid_argument("Il faut spécifier une valeur dans l'extension du vecteur");
  } else if(newDim<=0){
    throw std::invalid_argument("Il faut une taille >0");
  } else {

/*    Dvector newVect(newDim);
    for (int i=0; i<newDim; i++){
      newVect(i) = this->vect[i];
    }
    *this = newVect;*/
    this->dim = newDim;
  }
}
void Dvector::resize(int newDim, double val){
  if (this->dim < newDim){
    Dvector newVect(newDim);
    for (int i = 0; i<this->dim; i++){
      newVect(i) = this->vect[i];
    }
    for (int i = this->dim; i<newDim; i++){
      newVect(i) = val;
    }
    //delete(this->vect);
    *this = newVect;
  } else {
    throw std::invalid_argument("Il faut une taille plus grande sinon, il faut appeler la méthode sans nouvelle valeur");
  }
}

/* OPERATEUR INTERNES */

double const & Dvector::operator()(int i) const{
  if(i<0 || i>= dim){
    throw std::invalid_argument("L'indice d'un vecteur doit être compris entre 0 et dim -1");
  } else {
    return vect[i];
  }
}

Dvector Dvector::operator +=(double d){
  for(int i=0; i<this->dim; i++){
    this->vect[i] = this->vect[i] + d;
  }
  return *this;
}

Dvector Dvector::operator *=(double d){
  for(int i=0; i<this->dim; i++){
    this->vect[i] = this->vect[i] * d;
  }
  return *this;
}

Dvector Dvector::operator -=(double d){
  for(int i=0; i<this->dim; i++){
    this->vect[i] = this->vect[i] - d;
  }
  return *this;
}

Dvector Dvector::operator /=(double d){
  if (d!=0){
    for(int i=0; i<this->dim; i++){
      this->vect[i] = this->vect[i] / d;
    }
    return *this;
  } else {
    throw std::invalid_argument("Attention : division par 0");
  }

}

Dvector Dvector::operator -(){
  Dvector v(*this);
  for (int i=0; i<v.size(); i++){
    v(i) = -v(i);
  }
  return v;
}

Dvector& Dvector::operator =(const Dvector &v){
  // Verifier si on fait a = a (retourner *this)
  // verifier si taille = 0
  //cas a=b si taille différente on réallou a (delete(a.vect
  if(*this==v){
    return *this;
  } else if(v.size()==0){
    if(this->vect != nullptr){
        delete [] this->vect;
    }
    init(0);
  } else {
    if(dim!=v.size()){
      if(this->vect != nullptr){
          delete [] this->vect;
      }
      init(v.size());
    }

    memcpy(vect, v.vect, dim*sizeof(double));

  }
  return *this;
}

Dvector & Dvector::operator+=(const Dvector v) { 
    if(dim == v.size()) {
		  for(int i = 0; i<dim; i++) {
		  	vect[i] += v(i);
		  }
		} else {
			throw std::invalid_argument("Addition de 2 vecteurs de taille différentes.\n");
		}
}

Dvector & Dvector::operator-=(const Dvector v) { 
    if(dim == v.size()) {
		  for(int i = 0; i<dim; i++) {
		  	vect[i] -= v(i);
		  }
    } else {
    	throw std::invalid_argument("Soustraction de 2 vecteurs de taille différentes.\n");
    }
}


bool Dvector::operator ==(const Dvector &v){
  if (v.size()== this->dim){
    bool res = true;
    for (int i=0; i<this->dim; i++){
      res = res && (v(i)==this->vect[i]);
    }
    return res;
  } else {
    return false;
  }
}

//___________________FIN CLASSE Dvector_______________________//

/* OPERATEUR EXTERNES */

Dvector operator +(double d, const Dvector & v){
  Dvector vect(v);
  vect += d;
  return vect;
}

Dvector operator +(const Dvector & v, double d){
  Dvector vect(v);
  vect += d;
  return vect;
}


Dvector operator -(double d, const Dvector & v){
  Dvector vect(v);
  for(int i=0; i<vect.size(); i++){
    vect(i) = d - vect(i);
  }
  return vect;
}

Dvector operator -(const Dvector & v, double d){
  Dvector vect(v);
  vect -=d;
  return vect;
}


Dvector operator *(double d, const Dvector & v){
  Dvector vect(v);
  vect *= d;
  return vect;
}

Dvector operator *(const Dvector & v, double d){
  Dvector vect(v);
  vect *= d;
  return vect;
}

Dvector operator /(double d, const Dvector & v){
  Dvector vect(v);
  for(int i=0; i<vect.size(); i++){
    if (vect(i) != 0){
      vect(i) = d / vect(i);
    } else {
      throw std::invalid_argument("Attention : division par 0");
    }
  }
  return vect;
}

Dvector operator /(const Dvector & v, double d){
  Dvector vect(v);
  vect /=d;
  return vect;
}

Dvector operator +(const Dvector & v1, const Dvector & v2){
  Dvector v_1(v1);
  Dvector v_2(v2);

  if (v_1.size()==v_2.size()){
    for (int i=0; i<v_1.size(); i++){
      v_1(i) = v_1(i) + v_2(i);
    }
    return v_1;
  } else {
    throw std::invalid_argument("Somme entre vecteurs de taille différente");
  }
}

Dvector operator -(const Dvector & v1, const Dvector & v2){
  Dvector v_1(v1);
  Dvector v_2(v2);

  if (v_1.size()==v_2.size()){
    for (int i=0; i<v_1.size(); i++){
      v_1(i) = v_1(i) - v_2(i);
    }
    return v_1;
  } else {
    throw std::invalid_argument("Somme entre vecteurs de taille différente");
  }
}

std::ostream & operator <<(std::ostream &Out, const Dvector &v){
  Dvector vec(v);
  Out << "[ ";

  for (int i=0; i<vec.size(); i++){
    Out<<vec(i)<<" ";
  }
  Out<<"]";
  Out<<std::endl;
  return Out;
}

std::istream & operator >>(std::istream &In, Dvector &v){
  //Dvector vec(v);
  for (int i=0; i<v.size(); i++){
    In>>v(i);
  }

  return In;
}
