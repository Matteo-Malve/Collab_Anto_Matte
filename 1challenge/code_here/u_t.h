#ifndef INC_1CHALLENGE_U_T_H
#define INC_1CHALLENGE_U_T_H

#include <vector>
#include "Time_Vector.h"
using std::vector;

class u_t {
public:
    vector<double> uh;
    u_t(Time_Vector th){
        uh={};
        uh.reserve(th.get_size());
    }
};


#endif //INC_1CHALLENGE_U_T_H
