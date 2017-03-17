//
// Created by skip on 17/03/17.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <fstream>
#include <iostream>

template <typename T>

class Vector {

private:
    int dim;
    T* vect;
    void init(int d);

public:

    Vector<T>();
    Vector<T>(int d, T v=0); // V=0 si on le mets pas on l'init à 0
    Vector<T>(const Vector<T> & V);
    Vector<T>(std::string file);
    ~Vector<T>();

    void display(std::ostream& str);
    int size() const; //const = interdit de modif l'objet
    void fillRandomly();
    void resize(int newDim);
    void resize(int newDim, T val);
    T norm();
    /* OPERATOR */
    T& operator()(int i);
    T const & operator()(int i) const;

    Vector<T> odd(); // retourne un Vector<T> avec que les indices impairs
    Vector<T> even(); // ----- pairs

    Vector<T> operator +=(double d);
    Vector<T> operator *=(double d);
    Vector<T> operator -=(double d);
    Vector<T> operator /=(double d);
    Vector<T> operator -();
    Vector<T>& operator =(const Vector<T> &v);
    Vector<T> & operator+=(const Vector<T> v);
    Vector<T> & operator-=(const Vector<T> v);
    bool operator == (const Vector<T> &v);
};

/*Vector<T> operator +(double d, const Vector<T> & v);
Vector<T> operator +(const Vector<T> & v, double d);

Vector<T> operator -(double d, const Vector<T> & v);
Vector<T> operator -(const Vector<T> & v, double d);

Vector<T> operator *(double d, const Vector<T> & v);
Vector<T> operator *(const Vector<T> & v, double d);

Vector<T> operator /(double d, const Vector<T> & v);
Vector<T> operator /(const Vector<T> & v, double d);

Vector<T> operator +(const Vector<T> & v1, const Vector<T> & v2);
Vector<T> operator -(const Vector<T> & v1, const Vector<T> & v2);

std::ostream & operator <<(std::ostream &Out, const Vector<T> &v);
std::istream & operator >>(std::istream &In, Vector<T> &v);


Vector<T>* FFT(Vector<T> realPart, Vector<T> imPart);*/


#include "Vector.tpp"
#endif //VECTOR_H
