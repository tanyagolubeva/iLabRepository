#include "vector.h" 

template <class X> Cvector<X>::Cvector( int s ){
    size = s;
    data = new X[size];
}

template <class X> Cvector<X>::~Cvector(){
    delete []data;
}

template <class X> X& Cvector<X>::operator[] ( int num ){
    assert (( num >= 0 ) && (num < size));
    return data[size];
}

template <class X> Cvector<X> Cvector<X>::operator = (Cvector m){
    int i;
    for ( i = 0; i < size; i++)
    data[i] = m.data[i];
    return *this;
}

template <class X> Cvector<X> Cvector<X>::operator + ( Cvector m ){
    assert( size == m.size);
    Cvector<X> m1( size );
    int i;
    for ( i = 0; i < size; i++){
    m1.data[i] = m.data[i] + data[i];
    }
    return m1;
} 

template <class X> Cvector<X> Cvector<X>::operator - ( Cvector m ){
    Cvector<X> m1( size );
    int i;
    for ( i = 0; i < size; i++){
    m1.data[i] = m.data[i] - data[i];
    }
    return m1;
}

template <class X> Cvector<X> Cvector<X>::operator * ( int k ){
    Cvector<X> m1( size );
    int i;
    for ( i = 0; i < size; i++){
    m1.data[i] = data[i] * k;
}
   return m1;
}
