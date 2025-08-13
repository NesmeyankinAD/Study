###
cmake_minimum_required(VERSION 3.20)

set(PostgreSQL_ADDITIONAL_VERSIONS "17")

project(PostgreSQL_client)

add_subdirectory(libpqxx libpqxx-build)

add_library(SQL_master SHARED SQL_master.h SQL_master.cpp)

add_executable(PostgreSQL_client PostgreSQL_client.cpp)

target_compile_features(PostgreSQL_client PRIVATE cxx_std_17)

target_link_libraries(PostgreSQL_client SQL_master pqxx)