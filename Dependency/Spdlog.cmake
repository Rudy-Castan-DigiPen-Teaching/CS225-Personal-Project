FetchContent_Declare(
    the_spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.14.1  # 원하는 버전으로 변경
)
FetchContent_MakeAvailable(the_spdlog)

add_library(hookbill-spdlog INTERFACE)
target_include_directories(hookbill-spdlog SYSTEM INTERFACE ${the_spdlog_SOURCE_DIR}/include)