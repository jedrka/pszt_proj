cmake_minimum_required(VERSION 3.6)
project(pszt1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Solver.h Model.h State.h SolverDFS.cpp SolverDFS.h ModelSzachy.cpp ModelSzachy.h StateSzachownica.cpp StateSzachownica.h SolverH.cpp SolverH.h)
add_executable(pszt1 ${SOURCE_FILES} Solver.h)