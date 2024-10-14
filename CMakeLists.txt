cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(CS225 VERSION 0.1.0 LANGUAGES C CXX)
include(Dependency/Dependency.cmake)
add_subdirectory(Hookbill-Physics)  ##Physics Engine
add_subdirectory(Hookbill-Game)

