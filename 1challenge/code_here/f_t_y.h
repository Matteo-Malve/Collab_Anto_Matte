#ifndef INC_1CHALLENGE_F_T_Y_H
#define INC_1CHALLENGE_F_T_Y_H

#include <functional>
using std::function;
using y_t = const function<double(double)>;

class f_t_y {
private:
    const function<double(double,y_t)> f;

};



#endif //INC_1CHALLENGE_F_T_Y_H
