#include "Height.h"

Height::Height(){
  Lx=0;
  Ly=0;
  nx=0;
  ny=0;
  hauteurs = Dvector();
}

Height::Height(double L_x, double L_y, int n_x, int n_y){
  Lx=L_x;
  Ly=L_y;
  nx=n_x;
  ny=n_y;
  hauteurs = Dvector(nx*ny,0);
}

Height::Height(const Height &h){
  Lx=h.Lx;
  Ly=h.Ly;
  nx=h.nx;
  ny=h.ny;
  hauteurs = Dvector(h.hauteurs);
}

Height::~Height(){
  //delete(&hauteurs);
}

/*Height& operator =(const Height &h){

}*/
