#include <iostream>
#include "CranckNicolson.h"
using std::cout;
using std::endl;
double f(double t, double y) {return -t*exp(-y);};


int main() {
    double y0=0;
    double T=1;
    unsigned int N=10;
    CranckNicolson CN(f,y0,T,T/N,N,1e-3,200);
    tuple<Time_Vector,u_t,u_t> result =CN.solveCN ();
    cout<<"uh = ";
    for(unsigned int i=0;i<N;++i)
        cout<<std::get<1>(result)[i]<<" ";
    cout<<"Res = ";
    for(unsigned int i=0;i<N;++i)
        cout<<std::get<2>(result)[i]<<" ";    return 0;
}
