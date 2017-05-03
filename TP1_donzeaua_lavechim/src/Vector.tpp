#include "Vector.h"
#include <ctime>
#include <cstring>
#include <cmath>
#include <stdexcept>




template<class T> void Vector<T>::init(int d){
    if (d>0) {
        dim = d;
        vect = new T[d];
    } else if(d==0){
        dim = d;
        vect = nullptr;
    } else{
        throw std::invalid_argument("La taille d'un vecteur doit être supérieure ou égale à 0");
    }
}

template<class T> unsigned int Vector<T>::size() const{
    return dim;
}

template<class T> Vector<T>::Vector(){
    //std::cout << "__Constructeur simple__" << std::endl;
    dim = 0;
    vect = nullptr; //c++ 2011
}


template<class T> Vector<T>::Vector(int d, T v){
    //std::cout << "__Constructeur dim val__" << std::endl;
    this->init(d);
    for(int i = 0; i<dim; i++){
        vect[i] = v;
    }
}

template<class T> Vector<T>::Vector(const Vector<T> & V){
    //std::cout << "__Constructeur copie__" << std::endl;
    int d = V.dim;
    this->init(d);
    for(int i =0; i<dim; i++){
        vect[i] = V.vect[i];
    }
}

template<class T> Vector<T>::Vector(std::string file){
//  std::cout << "__Constructeur fichier__" << std::endl;

    std::ifstream fichier (file.c_str(), std::ios::in);
    if(fichier){
        int d = 0;
        T val;
        while (fichier>>val)
        {
            d++;
        }
        fichier.close();
        init(d);
        int i = 0;
        std::ifstream refichier(file.c_str(), std::ios::in);
        if(refichier) {
            T val;
            while (refichier >> val) {
                vect[i] = val;
                i++;
            }
            refichier.close();
        }
    }else {
        init(0);
    }
}

template<class T> Vector<T>::~Vector(){
//  std::cout << "Destruction" << std::endl;
    delete [] vect;
}

template<class T> void Vector<T>::display(std::ostream& str) {
    str << "( ";
    for(int i=0; i<dim; i++){
        str<<vect[i]<<" ";
    }
    str << ")";
}


template<class T> void Vector<T>::fillRandomly(){
    srand(time(NULL));
    for(int i=0; i<dim;i++){
        vect[i]= T (rand());
        vect[i] = vect[i]/T (RAND_MAX);
    }
}

template<class T> T& Vector<T>::operator()(int i){
    if(i<0 || i >= dim){
        throw std::invalid_argument(" : L'indice d'un vecteur doit être compris entre 0 et dim -1 ");
    } else {
        return vect[i];
    }
}

template<class T> void Vector<T>::resize(int newDim){
    if (this->dim < newDim){
        throw std::invalid_argument("Il faut spécifier une valeur dans l'extension du vecteur");
    } else if(newDim<=0){
        throw std::invalid_argument("Il faut une taille >0");
    } else {

/*    Vector<T> newVect(newDim);
    for (int i=0; i<newDim; i++){
      newVect(i) = this->vect[i];
    }
    *this = newVect;*/
        this->dim = newDim;
    }
}

template<class T> void Vector<T> ::resize(int newDim, T val){
    if (this->dim < newDim){
        Vector<T> newVect(newDim);
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

template<class T> T Vector<T> ::norm() {
    T norme=0;
    for (int i = 0 ; i<this->dim; i++){
        norme += vect[i]*vect[i];
    }
    return sqrt(norme);
}

template<class T> Vector<T> Vector<T> ::odd(){
    Vector<T> newvect(this->size()/2);
    for(int i=1; i<this->size(); i+=2){
        newvect(i/2) = this->vect[i];
    }
    return newvect;
}

template<class T> Vector<T> Vector<T>::even() {
    Vector<T> newvect;
    if(this->size()%2 == 0){
        newvect = Vector<T>(this->size()/2 );
    } else {
        newvect= Vector<T>(this->size()/2 +1);
    }
    for(int i=0; i<this->size(); i+=2){
        newvect(i/2)=this->vect[i];
    }
    return newvect;

}


/* OPERATEUR INTERNES */

template<class T> T const & Vector<T>::operator()(int i) const{
    if(i<0 || i>= dim){
        throw std::invalid_argument("L'indice d'un vecteur doit être compris entre 0 et dim -1");
    } else {
        return vect[i];
    }
}

template<class T> Vector<T> Vector<T>::operator +=(T d){
    for(int i=0; i<this->dim; i++){
        this->vect[i] = this->vect[i] + d;
    }
    return *this;
}

template<class T> Vector<T> Vector<T>::operator *=(T d){
    for(int i=0; i<this->dim; i++){
        this->vect[i] = this->vect[i] * d;
    }
    return *this;
}

template<class T> Vector<T> Vector<T>::operator -=(T d){
    for(int i=0; i<this->dim; i++){
        this->vect[i] = this->vect[i] - d;
    }
    return *this;
}

template<class T> Vector<T> Vector<T>::operator /=(T d){
    if (d!=T()){
        for(int i=0; i<this->dim; i++){
            this->vect[i] = this->vect[i] / d;
        }
        return *this;
    } else {
        throw std::invalid_argument("Attention : division par 0");
    }

}

template<class T> Vector<T> Vector<T>::operator -(){
    Vector<T> v(*this);
    for (int i=0; i<v.size(); i++){
        v(i) = -v(i);
    }
    return v;
}

template<class T> Vector<T>& Vector<T>::operator =(const Vector<T> &v){
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

        memcpy(vect, v.vect, dim*sizeof(T));

    }
    return *this;
}

template<class T> Vector<T> & Vector<T>::operator+=(const Vector<T> v) {
    if(dim == v.size()) {
        for(int i = 0; i<dim; i++) {
            vect[i] += v(i);
        }
    } else {
        throw std::invalid_argument("Addition de 2 vecteurs de taille différentes.\n");
    }
    return *this;
}

template<class T> Vector<T> & Vector<T>::operator-=(const Vector<T> v) {
    if(dim == v.size()) {
        for(int i = 0; i<dim; i++) {
            vect[i] -= v(i);
        }
    } else {
        throw std::invalid_argument("Soustraction de 2 vecteurs de taille différentes.\n");
    }
    return *this;
}


template<class T> bool Vector<T>::operator ==(const Vector<T> &v) const{
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

//___________________FIN CLASSE Vector_______________________//

/* OPERATEUR EXTERNES */
template<class T> Vector<T> operator +(T d, const Vector<T> & v){
    Vector<T> vect(v);
    vect += d;
    return vect;
}

template<class T> Vector<T> operator +(const Vector<T> & v, T d){
    Vector<T> vect(v);
    vect += d;
    return vect;
}


template<class T> Vector<T> operator -(T d, const Vector<T> & v){
    Vector<T> vect(v);
    for(int i=0; i<vect.size(); i++){
        vect(i) = d - vect(i);
    }
    return vect;
}

template<class T> Vector<T> operator -(const Vector<T> & v, T d){
    Vector<T> vect(v);
    vect -=d;
    return vect;
}


template<class T> Vector<T> operator *(T d, const Vector<T> & v){
    Vector<T> vect(v);
    vect *= d;
    return vect;
}

template<class T> Vector<T> operator *(const Vector<T> & v, T d){
    Vector<T> vect(v);
    vect *= d;
    return vect;
}


template<class T> Vector<T> operator /(const Vector<T> & v, T d){
    Vector<T> vect(v);
    vect /=d;
    return vect;
}

template<class T>Vector<T> operator +(const Vector<T> & v1, const Vector<T> & v2){
    Vector<T> v_1(v1);
    Vector<T> v_2(v2);

    if (v_1.size()==v_2.size()){
        for (int i=0; i<v_1.size(); i++){
            v_1(i) = v_1(i) + v_2(i);
        }
        return v_1;
    } else {
        throw std::invalid_argument("Somme entre vecteurs de taille différente");
    }
}

template<class T> Vector<T> operator -(const Vector<T> & v1, const Vector<T> & v2){
    Vector<T> v_1(v1);
    Vector<T> v_2(v2);

    if (v_1.size()==v_2.size()){
        for (int i=0; i<v_1.size(); i++){
            v_1(i) = v_1(i) - v_2(i);
        }
        return v_1;
    } else {
        throw std::invalid_argument("Somme entre vecteurs de taille différente");
    }
}

template <class T> T operator *(const Vector<T> & v1, const Vector<T> & v2){
    T res;
    if(v1.size() == v2.size()){
        res = v1(0)*v2(0);
        for(int i=1; i<v1.size();i++){
            res += v1(i)*v2(i);
        }
    } else {
        throw std::invalid_argument("Produit scalaire entre vecteurs de taille différente");
    }
    return res;
}


template<class T> std::ostream & operator <<(std::ostream &Out, const Vector<T> &v){
    Vector<T> vec(v);
    Out << "[ ";

    for (int i=0; i<vec.size(); i++){
        Out<<vec(i)<<" ";
    }
    Out<<"]";
    Out<<std::endl;
    return Out;
}

template<class T> std::istream & operator >>(std::istream &In, Vector<T> &v){
    //Vector<T> vec(v);
    for (int i=0; i<v.size(); i++){
        In>>v(i);
    }

    return In;
}


Vector<std::complex<double>> inline conj(Vector<std::complex<double>> v){
    int n = v.size();
    Vector<std::complex<double>> res(n);        //\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\//
    for (int i =0; i<n; i++){                   //        /!\ inline indispensable /!\          //
        res(i) = std::conj(v(i));               //  /!\ pour éviter la multiple définition /!\  //
    }                                           //\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\//
    return res;
}

void inline FFT(Vector<std::complex<double>>& vecteur){
    int n = vecteur.size();
    if(n>1){
        if(n%2 !=0){
            throw std::invalid_argument("On essaye de calculer la FFT d'un vecteur de taille impaire !");
        }
        Vector<std::complex<double>> evens(vecteur.even());
        FFT(evens);
        Vector<std::complex<double>> odds(vecteur.odd());
        FFT(odds);

        std::complex<double> t;
        for(int k=0; k<n/2; k++){
            double expo = exp(-2*M_PI*(double)k/n);
            t = odds(k)*expo;
            vecteur(k) = evens(k) + t;
            vecteur(k+(n/2)) = evens(k)-t;
        }

    }
}

void inline iFFT(Vector<std::complex<double>> & vecteur){
    int n = vecteur.size();
    std::complex<double>n_complex((double) n, 0.0);
    if (n>1){
        vecteur = conj(vecteur);
        FFT(vecteur);
        vecteur= conj(vecteur)/n_complex;
    }
}
