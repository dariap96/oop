cmake_minimum_required(VERSION 3.17)
project(oop6_BLL)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop6_BLL main.cpp Stuff.h StuffService.cpp TaskService.cpp Task_Control_System.h Task_Control_System_Service.cpp TaskService.cpp Task.h IService.h Service.cpp)
include_directories(/Users/dariapomazan/CLionProjects/oop6_DAL)