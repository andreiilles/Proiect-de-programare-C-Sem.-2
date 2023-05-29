cmake_minimum_required(VERSION 3.25)
project(proiect_pp_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(proiect_pp_cpp shared/data/Elev.cpp shared/data/Elev.h shared/data/Absenta.cpp shared/data/Absenta.h shared/data/Materie.cpp shared/data/Materie.h shared/data/Nota.cpp shared/data/Nota.h shared/data/Data.cpp shared/data/Data.h app2/app2.cpp shared/data/UsefulFunctions.cpp shared/data/UsefulFunctions.h)
