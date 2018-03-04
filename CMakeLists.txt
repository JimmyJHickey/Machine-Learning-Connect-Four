cmake_minimum_required(VERSION 3.9)
project(Machine_Learning_Connect_Four)

set(CMAKE_CXX_STANDARD 11)

include_directories(cpp/inc)
include_directories(cpp/lib)

add_executable(Machine_Learning_Connect_Four
        cpp/inc/constants.h
        cpp/inc/game_board.h
        cpp/inc/human_player.h
        cpp/inc/minimax_player.h
        cpp/inc/player.h
        cpp/lib/lib.lib
        cpp/src/driver.cpp
        cpp/src/game_board.cpp
        cpp/src/human_player.cpp
        cpp/src/minimax_player.cpp
        cpp/src/player.cpp
        cpp/makefile)
