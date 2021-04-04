cmake_minimum_required(VERSION 3.17)
project(oop6_UI)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop6_UI main.cpp TaskController.h TaskView.h ReportView.h PersonController.h PersonView.h ReportController.h )
include_directories(/Users/dariapomazan/CLionProjects/oop6_DAL)
include_directories(/Users/dariapomazan/CLionProjects/oop6_BLL)