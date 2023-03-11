cmake_minimum_required(VERSION 3.23)
project(1challenge)

set(CMAKE_CXX_STANDARD 20)

add_executable(1challenge main.cpp CranckNicolson.cpp CranckNicolson.h u_t.h f_t_y.h Time_Vector.h)
