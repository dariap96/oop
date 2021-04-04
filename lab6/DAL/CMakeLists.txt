cmake_minimum_required(VERSION 3.17)
project(oop6_DAL)

set(CMAKE_CXX_STANDARD 20)

add_library(oop6_DAL Stuff.h Task.h StuffRepository.cpp Task_Control_System_Repository.cpp TaskRepository.cpp)