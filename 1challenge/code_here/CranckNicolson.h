#ifndef INC_1CHALLENGE_CRANCKNICOLSON_H
#define INC_1CHALLENGE_CRANCKNICOLSON_H

#include <functional>
#include "u_t.h"
#include "f_t_y.h"
#include "Time_Vector.h"
#include <tuple>
using std::tuple;

class CranckNicolson {
public:
    CranckNicolson(f_t_y forzante, double Tmax, double hh, unsigned int nn, const double tol, const unsigned int max_iter):
                    f(forzante), T(Tmax), h(hh), n(nn), dt(T/n), toll(tol),max_it(max_iter){};
    tuple<Time_Vector,u_t,double> solveCN ();      // [th,uh,residual]
private:
    // Results:
        u_t uh;
        Time_Vector th;
        double res;

    // Given:
        // Model:
        f_t_y f;
        double T;
        double h;
        unsigned int n;
        double dt;
        // Numeric:
        const double toll;
        const unsigned int max_it;

};




#endif //INC_1CHALLENGE_CRANCKNICOLSON_H
