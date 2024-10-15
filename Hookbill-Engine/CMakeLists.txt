project(Engine)

file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${PROJECT_NAME} SHARED ${sources} ${headers})

target_link_libraries(Engine PUBLIC Hookbill-Physics)

target_include_directories
(
    ${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/includes 
    ${CMAKE_SOURCE_DIR}/Hookbill-Physics
​)

