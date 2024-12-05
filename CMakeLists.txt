cmake_minimum_required(VERSION 3.29)
project(SheepFight)

set(CMAKE_CXX_STANDARD 20)

add_executable(SheepFight
        src/main.cpp
        src/Game.cpp
        src/Game.h
        src/Manual.h
)


target_link_libraries(SheepFight
        sfml-graphics
        sfml-window
        sfml-system
)
