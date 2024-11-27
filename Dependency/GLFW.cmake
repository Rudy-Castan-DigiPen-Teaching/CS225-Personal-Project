# GLFW를 FetchContent로 가져오는 설정

include(FetchContent)

# GLFW를 GitHub에서 가져옵니다.
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8  # 필요한 GLFW 버전을 지정합니다. 예: 3.3.8
)

# GLFW가 아직 다운로드되지 않았으면 다운로드하고 빌드합니다.
FetchContent_MakeAvailable(glfw)

# GLFW를 인터페이스 라이브러리로 설정하여 프로젝트에 링크합니다.
add_library(HookBill_glfw INTERFACE)
target_link_libraries(HookBill_glfw INTERFACE glfw)

# GLFW의 include 디렉토리를 프로젝트에 추가합니다.
target_include_directories(HookBill_glfw SYSTEM INTERFACE ${glfw_SOURCE_DIR}/include)
