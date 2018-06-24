cmake_minimum_required(VERSION 3.5)
project(mtm_ex5_world_of_homework)

set(CMAKE_CXX_STANDARD 11)

add_executable(mtm_ex5_world_of_homework Player.h Player.cpp
        Game.h Game.cpp Weapon.h Weapon.cpp mtm_exceptions.h
        Warrior.cpp Warrior.h Wizard.cpp Wizard.h Troll.cpp
        Troll.h main.cpp)