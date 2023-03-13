//
// Created by Matteo Malvestiti on 11/03/23.
//

#ifndef INC_1CHALLENGE_TIME_VECTOR_H
#define INC_1CHALLENGE_TIME_VECTOR_H

#include <vector>
#include <cmath>
using std::vector;

class Time_Vector {
    vector<double> th;
public:
    Time_Vector(double T,double dt){
        unsigned int N=floor(T/dt);
        th.reserve(N);
        for(unsigned int i=0;i<N;++i)
            th[i]=dt*i;
    }
    size_t get_size(){return th.size();}
    double & operator[](unsigned int i) {return th[i];}
};


#endif //INC_1CHALLENGE_TIME_VECTOR_H
