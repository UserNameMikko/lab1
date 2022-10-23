cmake_minimum_required(VERSION 3.23)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 main.cpp Brass/Brass.h Strings/Strings.h Percussion/Percussion.h Orchestra/Orchestra.h Brass/Brass.cpp Strings/Strings.cpp Percussion/Percussion.cpp Keeper/Keeper.h Keeper/Keeper.cpp Menu/Menu.h Menu/Menu.cpp)
