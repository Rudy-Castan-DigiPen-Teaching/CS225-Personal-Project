project(Game)
# Hookbill-Game/CMakeLists.txt

add_executable(Hookbill-Game main.cpp)

# Hookbill-Physics 라이브러리와 링크
target_link_libraries(Hookbill-Game PRIVATE Engine)

# Hookbill-Physics의 헤더 파일 경로를 추가
target_include_directories(Hookbill-Game PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}  # Hookbill-Game의 헤더 경로
    ${CMAKE_SOURCE_DIR}/Hookbill-Engine/include
)

