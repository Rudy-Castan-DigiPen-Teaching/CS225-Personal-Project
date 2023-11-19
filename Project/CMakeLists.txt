cmake_minimum_required(VERSION 3.11)
project(Physics VERSION 0.1.0 LANGUAGES C CXX)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=-*,cppcoreguidelines-*;-fix;-fix-errors;")



# GSL 라이브러리 포함
include(FetchContent)
FetchContent_Declare(
    GSL
    GIT_REPOSITORY https://github.com/microsoft/GSL
    GIT_TAG v4.0.0
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(GSL)

# Box2D 라이브러리 포함
FetchContent_Declare(
    box2d
    GIT_REPOSITORY https://github.com/erincatto/box2d
    GIT_TAG 411acc32eb6d4f2e96fc70ddbdf01fe5f9b16230
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(box2d)

# 실행 파일 및 라이브러리 링크 생성
add_executable(Physics main.cpp)
target_link_libraries(Physics PRIVATE box2d)
target_link_libraries(Physics PRIVATE GSL)

# 테스트 활성화
include(CTest)
enable_testing()
