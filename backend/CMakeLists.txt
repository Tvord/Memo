cmake_minimum_required(VERSION 3.0.0)
project(Memo VERSION 0.1.0)

include_directories(DataCards/include)

add_library(memback STATIC backend.h DataCards/include/iDataCard.h DataCards/src/iDataCard.cpp)
