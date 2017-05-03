#include <iostream>
#include <cassert>
#include "Vector.h"
#include <vector>
#include <sstream>
#include <complex>

int main() {

  Height h(10, 10, 2, 2);

  int nx = h.getNx();
  int ny = h.getNy();
  vector<Vector<double>> vertices(H.size());

  for(int i = 0; i < vertices.size(); i++) {
      vertices[i].resize(3, 0.0);
  }

  for(int i = 0; i < nx; i++) {
    for(int j = 0; j < ny; j++) {
      vertices(i*nx+j)[2] = H(i*nx, j*ny);
      vertices(i*nx+j)[1] = i*nx;
      vertices(i*nx+j)[0] = j*ny;
    }
  }




}
