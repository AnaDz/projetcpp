//
// Created by skip on 17/03/17.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <fstream>
#include <iostream>
#include <complex>

template <class T>

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

    Vector<T> operator +=(T d);
    Vector<T> operator *=(T d);
    Vector<T> operator -=(T d);
    Vector<T> operator /=(T d);
    Vector<T> operator -();
    Vector<T>& operator =(const Vector<T> &v);
    Vector<T> & operator+=(const Vector<T> v);
    Vector<T> & operator-=(const Vector<T> v);
    bool operator == (const Vector<T> &v);
};

template <class T> Vector<T> operator +(T d, const Vector<T> & v);
template <class T> Vector<T> operator +(const Vector<T> & v, T d);

template <class T> Vector<T> operator -(T d, const Vector<T> & v);
template <class T> Vector<T> operator -(const Vector<T> & v, T d);

template <class T> Vector<T> operator *(T d, const Vector<T> & v);
template <class T> Vector<T> operator *(const Vector<T> & v, T d);

template <class T> Vector<T> operator /(const Vector<T> & v, T d);

template <class T> Vector<T> operator +(const Vector<T> & v1, const Vector<T> & v2);
template <class T> Vector<T> operator -(const Vector<T> & v1, const Vector<T> & v2);

template <class T> std::ostream & operator <<(std::ostream &Out, const Vector<T> &v);
template <class T> std::istream & operator >>(std::istream &In, Vector<T> &v);



void FFT(Vector<std::complex<double>> & vecteur);
void iFFT(Vector<std::complex<double>> & vecteur);

#include "Vector.tpp"
#endif //VECTOR_H
