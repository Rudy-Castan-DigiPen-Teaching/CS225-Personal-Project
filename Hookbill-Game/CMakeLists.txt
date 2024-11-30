project(Game)
# Hookbill-Game/CMakeLists.txt

add_executable(Hookbill-Game main.cpp src/TestLevel.cpp)

# Hookbill-Physics 라이브러리와 링크
target_link_libraries(Hookbill-Game PRIVATE Engine)

# Hookbill-Physics의 헤더 파일 경로를 추가
target_include_directories(Hookbill-Game PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}  # Hookbill-Game의 헤더 경로
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/Hookbill-Engine/include
)

# 빌드 유형에 따라 Engine.dll 경로 설정
set(ENGINE_DLL_PATH "${CMAKE_BINARY_DIR}/Hookbill-Engine/Debug/Engine.dll")

# Game 출력 폴더 경로 설정 (빌드 유형 포함)
set(GAME_OUTPUT_PATH "${CMAKE_BINARY_DIR}/Hookbill-Game/Debug")

# 중복된 슬래시 방지 (경로가 두 번 슬래시가 들어가는 문제 해결)
string(REPLACE "//" "/" ENGINE_DLL_PATH ${ENGINE_DLL_PATH})
string(REPLACE "//" "/" GAME_OUTPUT_PATH ${GAME_OUTPUT_PATH})

# Game 빌드 후, Engine.dll을 Game 출력 폴더로 복사하는 커스텀 명령 추가
add_custom_command(
    TARGET Hookbill-Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${ENGINE_DLL_PATH} ${GAME_OUTPUT_PATH}/Engine.dll  # 정확한 복사 경로로 설정
    COMMENT "Engine.dll을 Game 출력 폴더로 복사"
)
