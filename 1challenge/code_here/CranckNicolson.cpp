#include "CranckNicolson.h"

tuple<Time_Vector,u_t,double> CranckNicolson::solveCN () {      // [th,uh,residual]
    th=Time_Vector(T,dt);
    u_t uh(th);
    // Solve

    return std::make_tuple(th,uh,res);
}