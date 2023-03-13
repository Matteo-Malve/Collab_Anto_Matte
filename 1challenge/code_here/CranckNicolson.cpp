#include "CranckNicolson.h"
// Opz 1
double F(double x){
    return (x - h/2*(f(th[i],x)+f(th[i-1],uh[i-1])) - uh[i-1]);
};

tuple<Time_Vector,u_t,double> CranckNicolson::solveCN () {      // [th,uh,residual]
    th=Time_Vector(T,dt);
    u_t uh(th);
    // Solve
    uh[0]=y0;
    for(unsigned int i=1;i<N;++i){
        u_t d_uh=uh.derive();

        F=F_template(uh);
        NewtonSolver NS(,/* ??? d_uh  ??? */,
                        toll, toll, max_it);
    }
    return std::make_tuple(th,uh,res);
}

// Opz 3 Lambda
