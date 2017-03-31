//
// Created by skip on 24/03/17.
//
int main() {
    int n = 2000;
    double* A = new double[n*n];
    double* B= new double[n*n];
    double* C = new double[n*n];

    for (int i = 0 ; i<n ; i++){
        for (int j=0 ; j<n; j++){
            A[i*n + j] = 3.0;
            B[i*n + j] = 5.0;
        }
    }

    double *ptC(C) ;
    for (int i=0; i<n ; ++i ){
        for (int j=0; j<n ; ++j , ++ptC )
        {
            int k;
            double *ptA(&A[ i * n +0]);
            double * ptB(&B[0*n + j]);
            for ( k =0; k < n ; ++ k , ++ptA , ptB+=n){
                *ptC += *ptA * *ptB ;
            }
        }
    }


  /*  double *ptA(A);
    for( int i = 0; i < n ; ++ i ){
        for ( int k = 0; k < n ; ++ k , ++ ptA )
        {
            int j = 0;
            double * ptB ( & B [k*n +0] ) ;
            double * ptC ( & C [i*n +0] ) ;
            for ( j =0; j < n; ++j , ++ptC , ++ptB ){
                * ptC += * ptA * * ptB ;
            }
        }
    }*/

}