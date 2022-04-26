cmake_minimum_required(VERSION 3.20)
project(Casino_Royale)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)
add_executable(Casino_Royale main.cpp src/Karta.cpp src/Casino.cpp src/Player.cpp src/Bot.cpp src/IPlayer.cpp)
