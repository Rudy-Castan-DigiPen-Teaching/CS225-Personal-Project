cmake_minimum_required(VERSION 3.0.0)
project(Physics VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Physics  main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


include(FetchContent)
FetchContent_Declare(box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
        GIT_TAG 411acc32eb6d4f2e96fc70ddbdf01fe5f9b16230)

FetchContent_MakeAvailable(box2d)








