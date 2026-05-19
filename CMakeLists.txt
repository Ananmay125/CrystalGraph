cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("CrystalGraph")

add_subdirectory(libs/glfw)

add_executable (CrystalGraph
    "src/Main.cpp"
    "src/renderer.cpp" 
    "src/renderer.h"

    "libs/glad/src/glad.c"

    # ui link
    "libs/imgui/imgui.cpp"
    "libs/imgui/imgui_demo.cpp"
    "libs/imgui/imgui_draw.cpp"
    "libs/imgui/imgui_tables.cpp"
    "libs/imgui/imgui_widgets.cpp"
    "libs/imgui/ImGuizmo.cpp"
    "libs/imgui/backends/imgui_impl_glfw.cpp"
    "libs/imgui/backends/imgui_impl_opengl3.cpp"
    "libs/stb_image_write.h"
)

target_include_directories(CrystalGraph PRIVATE 
    libs/glfw/include
    libs/glad/include
    libs/glm
    libs
    libs/imgui
    libs/imgui/backends
)

target_link_libraries(CrystalGraph PRIVATE 
    glfw
    opengl32
)

add_custom_command(TARGET CrystalGraph POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders"
    "$<TARGET_FILE_DIR:CrystalGraph>/shaders"
)

add_custom_command(TARGET CrystalGraph POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/res"
    "$<TARGET_FILE_DIR:CrystalGraph>/res"
)

target_compile_definitions(CrystalGraph PRIVATE IMGUI_DEFINE_MATH_OPERATORS)

install(TARGETS CrystalGraph DESTINATION .)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/shaders/" DESTINATION "shaders")
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/res/" DESTINATION "res")
