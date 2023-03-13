#include "CranckNicolson.h"

tuple<Time_Vector,u_t,u_t> CranckNicolson::solveCN () {      // [th,uh,residual]
    // Solve
    uh[0]=y0;
    res[0]=0;
    for(unsigned int i=1;i<N;++i){
        u_t d_uh=uh.derive();
        auto F = [=](double x) -> double {
            return (x - h/2*(f(th[i],x)+f(th[i-1],uh[i-1])) - uh[i-1]);
        };
        auto dF = [=](double x) -> double {
            return (1 - 1/2*(f(th[i],x)-f(th[i],uh[i-1])));
        };
        NewtonSolver NS(F,dF,toll, toll, max_it);
        NS.solve(uh[i-1]);
        uh[i]=NS.get_result();
        res[i]=NS.get_residual();
    }
    return std::make_tuple(th,uh,res);
}


