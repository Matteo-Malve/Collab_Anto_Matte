#include "CranckNicolson.h"

tuple<Time_Vector,u_t,double> CranckNicolson::solveCN () {      // [th,uh,residual]
    th=Time_Vector(T,dt);
    u_t uh(th);
    // Solve
    uh[0]=y0;
    for(unsigned int i=1;i<N;++i){
        u_t d_uh=uh.derive();
        NewtonSolver NS(uh,/* ??? d_uh  ??? */,
                        toll, toll, max_it);
    }
    return std::make_tuple(th,uh,res);
}