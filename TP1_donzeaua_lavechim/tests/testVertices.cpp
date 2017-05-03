#include <iostream>
#include <cassert>
#include "Vector.h"
#include "Height.h"
#include "Ocean.h"
#include <vector>
#include <sstream>
#include <complex>

using namespace std;

int main() {

    Height H(10, 10, 2, 2);

    unsigned int nx = H.getNx();
    unsigned int ny = H.getNy();
    vector<Vector<double>> vertices((nx+1)*(ny+1));

    //Resize
    cout << "taille vertices : " << vertices.size() << "\n";
    for(unsigned int i = 0; i < vertices.size(); i++) {
        vertices[i].resize(3, 0);
    }

    //gl_vertices

    cout << "nx : " << nx << "\n";
    for(unsigned int i = 0; i <= nx; i++) {
        for(unsigned int j = 0; j <= ny; j++) {
            vertices[i+(nx+1)*j](2) = H(i*10/nx, j*10/ny);
            vertices[i+(nx+1)*j](1) = j*10/nx;
            vertices[i+(nx+1)*j](0) = i*10/ny;
        }
    }

    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i];
    }
    cout << "\n" << endl;
}
