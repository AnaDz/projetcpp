#ifndef HEIGHT_H
#define HEIGHT_H

#include "Dvector.h"

class Height {

private:
  double Lx;
  double Ly;
  int nx;
  int ny;
  Dvector hauteurs;
public:
  Height();
  Height(double L_x, double L_y, int n_x, int n_y);
  Height(const Height &h);
  ~Height();

//  Height& operator =(const Height &h);
};

#endif
