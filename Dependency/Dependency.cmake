include(FetchContent)
include(Dependency/GSL.cmake)

add_library(Dependency INTERFACE)
target_include_directories(Dependency INTERFACE  ${GSL_SOURCE_DIR}/include)
target_link_libraries(Dependency INTERFACE Microsoft.GSL::GSL)
target_compile_features(Dependency INTERFACE cxx_std_17)