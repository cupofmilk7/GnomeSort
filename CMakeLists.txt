cmake_minimum_required(VERSION 3.29)
project(GnomeSort)

set(CMAKE_CXX_STANDARD 20)

add_executable(GnomeSort main.cpp
        sort.cpp
        sort.h
        arrayWork.cpp
        checkData.cpp
        checkData.h
        arrayWork.h
        fileFunctions.cpp
        fileFunctions.h)
