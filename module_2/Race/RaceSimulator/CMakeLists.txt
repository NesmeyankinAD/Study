cmake_minimum_required(VERSION 3.22.0)

project(race_simulator)

set(SOURCES 
Vehicle.cpp
GroundVehicle.cpp
AirVehicle.cpp
Camel.cpp
FastCamel.cpp
Boots.cpp
Centaur.cpp
MagicCarpet.cpp
Eagle.cpp
Broom.cpp)

set(HEADERS 
Vehicle.h
GroundVehicle.h
AirVehicle.h
Camel.h
FastCamel.h
Boots.h
Centaur.h
MagicCarpet.h
Eagle.h
Broom.h)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(VehiclesEnvironment SHARED ${SOURCES} ${HEADERS} VehiclesEnvironment.h VehiclesEnvironment.cpp)

add_executable(race_client Race.cpp)

target_link_libraries(race_client VehiclesEnvironment)