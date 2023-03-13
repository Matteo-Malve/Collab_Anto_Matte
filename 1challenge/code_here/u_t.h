#ifndef INC_1CHALLENGE_U_T_H
#define INC_1CHALLENGE_U_T_H

#include <vector>
#include "Time_Vector.h"
#include "../include/NewtonSolver/Newton.hpp"
using std::vector;

class u_t {
private:
    vector<double> uh;
    size_t N;
public:
    explicit u_t(Time_Vector th){
        uh={};
        N=th.get_size();
        uh.reserve(N);
    }
    explicit u_t(size_t n){
        N=n;
        uh={};
        uh.reserve(N);
    }
    double & operator[](unsigned int i) {return uh[i];}


    u_t derive(){
        // ???????
    }
};


#endif //INC_1CHALLENGE_U_T_H
