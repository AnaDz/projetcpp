/** Initialise la grille dans la direction x
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayX(const int y, double* const vertices) const {
  for(unsigned int x=0 ; x<nx ; x++) {
    vertices[3*x]   = (Lx/nx)*x;
    vertices[3*x+2] = (Ly/ny)*y;
  }
  vertices[3*nx]   = Lx;
  vertices[3*nx+2] = (Ly/ny)*y;
}

/** Initialise la grille dans la direction y
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayY(const int x, double* const vertices) const {
  for(unsigned int y=0 ; y<ny ; y++) {
    vertices[3*y]   = (Lx/nx)*x;
    vertices[3*y+2] = (Ly/ny)*y;
  }
  vertices[3*ny]   = (Lx/nx)*x;
  vertices[3*ny+2] = Ly;
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un y donné
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayX(const int y, double* const vertices) const {
  for(unsigned int x=0 ; x<nx ; x++) {
    //vertices[3*x+1] = pow(-1, x+y)*H(y,x); //H ou hr ?
    vertices[3*x+1] = H(y,x);
  }
  //vertices[3*nx+1] = pow(-1, nx+y)*H(y,0);  //H ou hr ?
  vertices[3*nx+1] = H(y,0);
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un x donné
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayY(const int x, double* const vertices) const {
  for(unsigned int y=0 ; y<ny ; y++) {
    vertices[3*y+1] = H(y,x);
  }
  vertices[3*ny+1]  = H(0,x);
}
