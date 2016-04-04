#include <iostream>
#include "vector.h"
using namespace std;
int main(){
    Cvector<int> x(2), y(2), z(2);
    x[0]=1;
    x[1]=1;
    int  k = x[0];
    std::cout<<k<<std::endl;
    y[0]=7;
    y[1]=7;
    z = x + y;
    std::cout<<z[0]<<" "<<z[1]<<" "<<std::endl;
    return 0;
}