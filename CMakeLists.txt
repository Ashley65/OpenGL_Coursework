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
        ${CMAKE_SOURCE_DIR}/Lib/imgui/imfilebrowser.h
        Source/ui/frontPage/frontPage.cpp
        Source/ui/frontPage/frontPage.h
        Source/window/windowBase.h
        Source/render/renderBase.h
        Source/elements/elements.h
        Source/elements/mesh.cpp
        Source/elements/mesh.h
        Source/elements/light.h
        Source/ui/sceneView.cpp
        Source/ui/sceneView.h
        Source/render/uiContext.cpp
        Source/render/uiContext.h
)

set(ELEMENTS_SOURCES
        Source/elements/elements.h
        Source/elements/mesh.cpp
        Source/elements/mesh.h
        Source/elements/light.h
        Source/elements/vertexHolder.cpp
        Source/elements/vertexHolder.h
        Source/elements/camera.cpp
        Source/elements/camera.h
        Source/elements/input.h
)
set(SHADER_SOURCES
        Source/shader/shaderUtils.cpp
        Source/shader/shaderUtils.h
)

set(RENDER_SOURCES
        Source/render/renderBase.h
        Source/render/openGLBufferManager.cpp
        Source/render/openGLBufferManager.h
        Source/render/openGLContext.cpp
        Source/render/openGLContext.h
        Source/render/uiContext.cpp
        Source/render/uiContext.h
)

set(UI_SOURCES
        Source/ui/sceneView.cpp
        Source/ui/sceneView.h
)

set(WINDOW_SOURCES
        Source/window/TGWindow.cpp
        Source/window/TGWindow.h
        Source/ui/frontPage/frontPage.cpp
        Source/ui/frontPage/frontPage.h
        Source/window/windowBase.h
)

set(GENERATING_SOURCES
        Source/generating/PerlinNoise.cpp
        Source/generating/PerlinNoise.h
)

add_executable(OpenGLCoursework main.cpp
        ${GENERATING_SOURCES}
        ${IMGUI_SOURCES}
        ${ELEMENTS_SOURCES}
        ${SHADER_SOURCES}
        ${RENDER_SOURCES}
        ${UI_SOURCES}
        ${WINDOW_SOURCES}
        Source/app.cpp
        Source/app.h

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