cmake_minimum_required(VERSION 3.0.0)
project(Memo VERSION 0.1.0)

add_subdirectory(backend)

add_executable(Memo main.cpp)
target_link_libraries(Memo backend)
