#include <iostream>
#include <cmath>
#include <cassert>

template <class X> class Cvector{
    private:
    int size;
    X* data;
    public:
    Cvector( int s );
    ~Cvector();
    X& operator [] (int num); 
    Cvector operator + ( Cvector m );
    Cvector operator - ( Cvector m );
    Cvector operator = ( Cvector m );
    Cvector operator * ( int k );
}
;





