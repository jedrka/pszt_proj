cmake_minimum_required(VERSION 3.6)
project(pszt1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Solver.h Model.h State.h SolverDFS.cpp SolverDFS.h ModelSzachy.cpp ModelSzachy.h StateSzachownica.cpp StateSzachownica.h SolverH.cpp SolverH.h)
add_executable(pszt1 ${SOURCE_FILES} Solver.h)

INCLUDE_DIRECTORIES( allegro-5.0.10-mingw-4.7.0/include )
INCLUDE_DIRECTORIES( SFML-2.4.1/include )


LINK_DIRECTORIES( C:/Users/jedrek/ClionProjects/pszt1/allegro-5.0.10-mingw-4.7.0/lib )
LINK_DIRECTORIES( C:/Users/jedrek/ClionProjects/pszt1/allegro-5.0.10-mingw-4.7.0/bin )

LINK_DIRECTORIES( ./allegro-5.0.10-mingw-4.7.0/lib )
LINK_DIRECTORIES( ./allegro-5.0.10-mingw-4.7.0/bin )

LINK_DIRECTORIES( ./SFL-2.4.1/)
LINK_DIRECTORIES( ./allegro-5.0.10-mingw-4.7.0/bin )

set(CMAKE_VERBOSE_MAKEFILE ON)
set(SFML_ROOT C:/Users/jedrek/ClionProjects/pszt1/SFML-2.4.1)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(pszt1 ${SFML_LIBRARIES})
endif()