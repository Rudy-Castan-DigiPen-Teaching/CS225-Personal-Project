project(Engine)

file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(Engine SHARED ${sources} ${headers})

target_link_libraries(Engine PUBLIC Hookbill-Physics)
## todo add graphics_library here 

target_compile_definitions(Engine PRIVATE HOOKBILL_EXPORT)


target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
    ${CMAKE_SOURCE_DIR}/Hookbill-Physics
)


