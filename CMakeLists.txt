cmake_minimum_required(VERSION 3.27)
project(EasyDDOS)

set(CMAKE_CXX_STANDARD 14)

add_executable(EasyDDOS
        src/main.cpp
        src/death_ping.cpp
        src/LanArp.cpp
        src/HttpRequests_Socket.cpp
)
