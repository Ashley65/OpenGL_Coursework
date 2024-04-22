cmake_minimum_required(VERSION 3.27)
project(OpenGLCoursework)

set(CMAKE_CXX_STANDARD 20)

set(IMGUI_SOURCES
        ${CMAKE_SOURCE_DIR}/Lib/imgui/imgui.cpp
        ${CMAKE_SOURCE_DIR}/Lib/imgui/imgui.h
        ${CMAKE_SOURCE_DIR}/Lib/imgui/imgui_draw.cpp
        ${CMAKE_SOURCE_DIR}/Lib/imgui/imgui_internal.h
        ${CMAKE_SOURCE_DIR}/Lib/imgui/imgui_widgets.cpp
        ${CMAKE_SOURCE_DIR}/Lib/imgui/imgui_impl_glfw.cpp
        ${CMAKE_SOURCE_DIR}/Lib/imgui/imgui_impl_opengl3.cpp
        Source/window/frontPage/frontPage.cpp
        Source/window/frontPage/frontPage.h
        Source/window/windowBase.h
        Source/render/renderBase.h
        Source/elements/elements.h
)

add_executable(OpenGLCoursework main.cpp
        Source/generating/PerlinNoise.cpp
        Source/generating/PerlinNoise.h
        Source/elements/camera.cpp
        Source/elements/camera.h
        ${IMGUI_SOURCES}
        Source/window/TGWindow.cpp
        Source/window/TGWindow.h
        Source/render/renderBase.h
        Source/elements/vertexHolder.cpp
        Source/elements/vertexHolder.h
        Source/elements/input.h
        Source/shader/shaderUtils.cpp
        Source/shader/shaderUtils.h
        Source/render/openGLBufferManager.cpp
        Source/render/openGLBufferManager.h
)





find_package(OpenGL REQUIRED)
target_link_libraries(OpenGLCoursework PRIVATE OpenGL::GL)
find_package(glm CONFIG REQUIRED)
target_link_libraries(OpenGLCoursework PRIVATE glm::glm)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(OpenGLCoursework PRIVATE glfw)

find_package(GLEW REQUIRED)
target_link_libraries(OpenGLCoursework PRIVATE GLEW::GLEW)

find_package(glad CONFIG REQUIRED)
target_link_libraries(OpenGLCoursework PRIVATE glad::glad)

find_package(glui CONFIG REQUIRED)
target_link_libraries(OpenGLCoursework PRIVATE glui::glui glui::glui_static)

find_package(soil2 CONFIG REQUIRED)
target_link_libraries(OpenGLCoursework PRIVATE soil2)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(OpenGLCoursework PRIVATE imgui::imgui)

find_package(assimp CONFIG REQUIRED)
target_link_libraries(OpenGLCoursework PRIVATE assimp::assimp)