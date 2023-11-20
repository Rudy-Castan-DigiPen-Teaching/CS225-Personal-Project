cmake_minimum_required(VERSION 3.11)
project(Physics VERSION 0.1.0 LANGUAGES C CXX)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=-*,cppcoreguidelines-*;-fix;-fix-errors;")
# ExternalProject 모듈 포함
include(ExternalProject)
include(FetchContent)
# Box2D 라이브러리 포함
FetchContent_Declare(
    box2d
    GIT_REPOSITORY https://github.com/erincatto/box2d
    GIT_TAG 411acc32eb6d4f2e96fc70ddbdf01fe5f9b16230
    GIT_SHALLOW TRUE
)

# Box2D 라이브러리 빌드 시 clang-tidy 비활성화
FetchContent_GetProperties(box2d)
if(NOT box2d_POPULATED)
    FetchContent_Populate(box2d)
    ExternalProject_Add(box2d
        PREFIX ${box2d_BINARY_DIR}
        SOURCE_DIR ${box2d_SOURCE_DIR}
        CMAKE_ARGS -DBOX2D_BUILD_UNIT_TESTS:BOOL=OFF  # 또는 다른 비슷한 플래그
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
    )
endif()

# box2d 라이브러리 빌드 완료 후 라이브러리로 사용
add_library(box2d_imported INTERFACE)
add_dependencies(box2d_imported box2d)
target_include_directories(box2d_imported INTERFACE ${box2d_SOURCE_DIR}/Box2D)

# GSL 라이브러리 포함
include(FetchContent)
FetchContent_Declare(
    GSL
    GIT_REPOSITORY https://github.com/microsoft/GSL
    GIT_TAG v4.0.0
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(GSL)

# 실행 파일 및 라이브러리 링크 생성
add_executable(Physics main.cpp)
target_link_libraries(Physics PRIVATE box2d_imported GSL)

# 테스트 활성화
include(CTest)
enable_testing()
