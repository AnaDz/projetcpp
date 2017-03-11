#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <cassert>


int main() {

  Dvector Ve(3);
  assert(Ve.size() == 3);
  std::cout << "Constructeur avec taille : OK" << std::endl;

  Dvector v(3,2.5);
  assert( v.size() == 3 );
  std::stringstream str;
  v.display( str );
  assert( str.str() == "2.5\n2.5\n2.5\n" );
  std::cout << "Constructeur avec taille + valeur : OK"<< std::endl;


  Dvector V2(3);
  V2.fillRandomly();

  Dvector V3(V2);
  std::stringstream str1;
  std::stringstream str2;
  V2.display(str1);
  V3.display(str2);
  assert(str1.str() == str2.str());
  std::cout << "Constructeur par copie : OK" << std::endl;
  std::ofstream fichier("vecteur.txt", std::ios::out | std::ios::trunc);
  if(fichier){
      V3.display(fichier);
      fichier.close();
  }
  std::stringstream str3;
  Dvector V4("vecteur.txt");
  V4.display(str3);
  assert(str3.str() == str2.str());
  std::cout << "Contructeur par lecture de fichier : OK" << std::endl;



  Dvector v5(3,1.52);
  v5(1) = 3.2;
  assert(v5(0)==1.52);
  assert(v5(1)==3.2);
  assert(v5(2)==1.52);
  std::cout << "accesseur \"()\" : OK" << std::endl;


  Dvector v6 = v5+1.0;
  assert(v6(0)==2.52);
  assert(v6(1)==4.2);
  assert(v6(2)==2.52);
  std::cout << "operateur vect + double : OK" << std::endl;

  Dvector v10 = 1.0+v5;
  assert(v10(0)==2.52);
  assert(v10(1)==4.2);
  assert(v10(2)==2.52);
  std::cout << "operateur double + vect : OK" << std::endl;

  Dvector v7 = v6 -1.0;
  assert(v7(0)==1.52);
  assert(v7(1)==3.2);
  assert(v7(2)==1.52);
  std::cout << "operateur vect - double : OK" << std::endl;

  Dvector v11 = 10.0-v6;
  assert(v11(0)==7.48);
  assert(v11(1)==5.8);
  assert(v11(2)==7.48);
  std::cout << "operateur double - vect : OK" << std::endl;

  Dvector v8 = v5 *2.0;
  assert(v8(0)==3.04);
  assert(v8(1)==6.4);
  assert(v8(2)==3.04);
  std::cout << "operateur vect * double : OK" << std::endl;

  Dvector v12 = 2.0*v5;
  assert(v12(0)==3.04);
  assert(v12(1)==6.4);
  assert(v12(2)==3.04);
  std::cout << "operateur double * vect : OK" << std::endl;

  Dvector v9 = v8/2.0;
  assert(v9(0)==1.52);
  assert(v9(1)==3.2);
  assert(v9(2)==1.52);
  std::cout << "operateur vect / double : OK" << std::endl;

  Dvector v13(3,2.0);
  Dvector v14 = 4.0/v13;
  assert(v14(0)==2.0);
  assert(v14(1)==2.0);
  assert(v14(2)==2.0);
  std::cout << "operateur double / vect : OK" << std::endl;

  Dvector v15 = v14 + v13;
  assert(v15(0)==4.0);
  assert(v15(1)==4.0);
  assert(v15(2)==4.0);
  std::cout << "operateur vect + vect : OK" << std::endl;

  Dvector v16 = v15 - v13;
  assert(v16(0)==2.0);
  assert(v16(1)==2.0);
  assert(v16(2)==2.0);
  std::cout << "operateur vect - vect : OK" << std::endl;

  Dvector v17 = -v16;
  assert(v17(0)==-2.0);
  assert(v17(1)==-2.0);
  assert(v17(2)==-2.0);
  std::cout << "operateur -vect : OK" << std::endl;

  std::cout << "Test du <<. Expected :\"Vecteur : -2 -2 -2\". Result : " ;
  std::cout << v17 << std::endl;

  Dvector v18(3);
  std::cout << "Entrer 3 nombres" << std::endl;
  std::cin >> v18;
  std::cout << v18 << std::endl;

  Dvector v19;
  v19 = v17;
  assert(v19(0)==-2.0);
  assert(v19(1)==-2.0);
  assert(v19(2)==-2.0);
  std::cout << "operateur vect = vect : OK" << std::endl;

  bool b = v19==v17;
  std::cout << "operateur == doit retourner true : ";
  std::cout << b << std::endl;

  b = v15 == v19;
  std::cout << "operateur == doit retourner false : ";
  std::cout << b << std::endl;

  v19.resize(2);
  assert(v19.size()==2);
  assert(v19(0) == -2.0);
  assert(v19(1) == -2.0);
  std::cout << "méthode resize avec une taille plus petite : OK" << std::endl;

  v19.resize(4, 1.0);
  assert(v19.size()==4);
  assert(v19(0) == -2.0);
  assert(v19(1) == -2.0);
  assert(v19(2) == 1.0);
  assert(v19(3) == 1.0);
  std::cout << "méthode resize avec une taille plus grande : OK" << std::endl;

  std::cout<<"Ca a marché ! \n";
  return 0;
}
