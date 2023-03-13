#ifndef NEWTON_HPP
#define NEWTON_HPP

#include <functional>
#include <limits>

class NewtonSolver{
public:
    NewtonSolver(const std::function<double(double)> &f, 
                const std::function<double(double)> &df,
                double toll_res = std::numeric_limits<double>::epsilon()*1000.0,
                double toll_incr = std::numeric_limits<double>::epsilon()*1000.0,
                unsigned int max_it=100):
        m_f(f),
        m_df(df),
        m_toll_res(toll_res),
        m_toll_incr(toll_incr),
        m_max_it(max_it),
        m_x(0),
        m_df_x(0),
        m_dx(0),
        m_iter(0)
        {};

    void solve(double x0){
        // implementation
        m_x=x0;
        for(m_iter=0;m_iter<m_max_it;++m_iter){
            m_res=m_f(m_x);
            if(std::abs(m_res)<m_toll_res)
                break;
            m_df_x=m_df(m_x);
            m_dx=m_res/m_df_x;
            m_x-=m_dx;
            if(std::abs(m_dx)<m_toll_incr)
                break;
        }
    }

    double get_result() const { return m_x; };
    double get_residual() const{return m_res;}
private:
    const std::function<double(double)> m_f;
    const std::function<double(double)> m_df;
    const double m_toll_res;
    const double m_toll_incr;
    const unsigned int m_max_it;

    double m_x;
    double m_df_x;
    double m_dx;
    double m_res;
    double m_iter = 0;
};




#endif //NEWTON_HPP