cmake_minimum_required(VERSION 3.29)
project(SheepFight)

set(CMAKE_CXX_STANDARD 20)

add_executable(SheepFight
        src/main.cpp
        src/Game.cpp
        src/Game.h
        src/Manual.h
        src/Player.cpp
        src/Player.h
        src/Queue.cpp
        src/Queue.h
        src/Line.cpp
        src/Line.h
        src/Score.cpp
        src/Score.h
        src/Animal.cpp
        src/Animal.h
        src/Health.cpp
)


target_link_libraries(SheepFight
        sfml-graphics
        sfml-window
        sfml-system
)
