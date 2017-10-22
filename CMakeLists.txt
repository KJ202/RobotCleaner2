cmake_minimum_required(VERSION 2.6)

#Déclaration du projet

project(RobotCleaner2)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

#Déclaration de l'exécutable

add_executable(

        robot_cleaner2

        src/action.cpp

        src/dp.cpp

        src/main.cpp

        src/montecarlo.cpp

        src/qlearning.cpp
	src/qlearningLinearApprox.cpp
        src/state.cpp
        
        src/world.cpp
        
        include/action.hpp
        include/dp.hpp
        include/montecarlo.hpp
        include/qlearning.hpp
        include/qlearningLinearApprox.hpp
        include/state.hpp
        include/types.hpp
        include/world.hpp
        
        
)
