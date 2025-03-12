cmake_minimum_required(VERSION 3.22.0)

project(Leaver_prj)

add_library(LeaverDLL SHARED Leaver.h Leaver.cpp)
add_executable(Leaver_client Client.cpp)
target_link_libraries(Leaver_client LeaverDLL)