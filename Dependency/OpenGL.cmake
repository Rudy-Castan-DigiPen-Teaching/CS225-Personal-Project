find_package(OpenGL REQUIRED)
add_library(HookBill-OPENGL INTERFACE)

target_link_libraries(HookBill-OPENGL INTERFACE ${OPENGL_LIBRARIES})
