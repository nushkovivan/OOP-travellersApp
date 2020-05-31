cmake_minimum_required(VERSION 3.15)
project(travellersApp)

set(CMAKE_CXX_STANDARD 11)

add_executable(travellersApp main.cpp User.cpp User.h Destination.h Destination.cpp functions.cpp)