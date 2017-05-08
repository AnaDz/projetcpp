#ifndef DVECTOR_H
#define DVECTOR_H
#include <fstream>
#include <iostream>


class Dvector {

private:
  int dim;
  double* vect;
  void init(int d);

public:

  Dvector();
  Dvector(int d, double v=0); // V=0 si on le mets pas on l'init à 0
  Dvector(const Dvector & V);
  Dvector(std::string file);
  ~Dvector();

  void display(std::ostream& str);
  int size() const; //const = interdit de modif l'objet
  void fillRandomly();
  void resize(int newDim);
  void resize(int newDim, double val);
  double norm();
  /* OPERATOR */
  double& operator()(int i);
  double const & operator()(int i) const;

  Dvector odd(); // retourne un Dvector avec que les indices impairs
  Dvector even(); // ----- pairs

  Dvector operator +=(double d);
  Dvector operator *=(double d);
  Dvector operator -=(double d);
  Dvector operator /=(double d);
  Dvector operator -();
  Dvector& operator =(const Dvector &v);
  Dvector & operator+=(const Dvector v);
	Dvector & operator-=(const Dvector v);
  bool operator == (const Dvector &v);
};

Dvector operator +(double d, const Dvector & v);
Dvector operator +(const Dvector & v, double d);

Dvector operator -(double d, const Dvector & v);
Dvector operator -(const Dvector & v, double d);

Dvector operator *(double d, const Dvector & v);
Dvector operator *(const Dvector & v, double d);

Dvector operator /(double d, const Dvector & v);
Dvector operator /(const Dvector & v, double d);

Dvector operator +(const Dvector & v1, const Dvector & v2);
Dvector operator -(const Dvector & v1, const Dvector & v2);

std::ostream & operator <<(std::ostream &Out, const Dvector &v);
std::istream & operator >>(std::istream &In, Dvector &v);


Dvector* FFT(Dvector realPart, Dvector imPart);

#endif
