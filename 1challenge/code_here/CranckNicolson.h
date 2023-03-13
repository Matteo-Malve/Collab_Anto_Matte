#ifndef INC_1CHALLENGE_CRANCKNICOLSON_H
#define INC_1CHALLENGE_CRANCKNICOLSON_H

#include "u_t.h"
#include "Time_Vector.h"
#include <tuple>
using std::tuple;
#include <functional>
using std::function;
using y_t = const function<double(double)>;
using f_t_y = const function<double(double,y_t)>;
#include "../include/NewtonSolver/Newton.hpp"

class CranckNicolson {
public:
    CranckNicolson(f_t_y forzante, double yinit, double Tmax, double hh, unsigned int nn, const double tol, const unsigned int max_iter):
                    f(forzante), y0(yinit), T(Tmax), h(hh), N(nn), dt(T/N), toll(tol),max_it(max_iter){};
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
        unsigned int N;
        double dt;
        // Numeric:
        const double toll;
        const unsigned int max_it;
        // BC:
        double y0;
// Opz 2
    double F(double t, double uh, double x){
        return (x - h/2*(f(t,x)+f(t,uh)) - uh);
    };
};




#endif //INC_1CHALLENGE_CRANCKNICOLSON_H
