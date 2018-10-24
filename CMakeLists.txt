cmake_minimum_required(VERSION 3.12)
project(UTPod)

set(CMAKE_CXX_STANDARD 14)

add_executable(UtPod UtPod.cpp
        song.cpp
        Song.h Song.cpp UtPod.h UtPodDriver.cpp)