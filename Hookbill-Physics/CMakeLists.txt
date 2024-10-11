# PhysicsEngine/CMakeLists.txt

# 라이브러리 생성
add_library(Hookbill-Physics STATIC Physics-Core.cpp)
##include(../Dependency/Dependency.cmake)
# 헤더 파일 경로 추가
target_include_directories(Hookbill-Physics PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${Dependency_INCLUDE_DIRS}  # Dependency의 헤더 파일 경로 추가
)
# 필요하다면 다른 라이브러리와 링크 (Dependency와 같은)
target_link_libraries(Hookbill-Physics PUBLIC Dependency)
