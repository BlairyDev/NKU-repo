cmake_minimum_required(VERSION 3.29)
project(prog2revise)

set(CMAKE_CXX_STANDARD 17)

add_executable(prog2revise prog2.cpp
        Account.cpp
        Account.h
        Bank.cpp
        Bank.h
        ATM.cpp
        ATM.h
)
