cmake_minimum_required(VERSION 3.5)

project(HW_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HW_1 main.cpp BoolStack.h BoolStack.cpp BoolQueue.h BoolQueue.cpp)
