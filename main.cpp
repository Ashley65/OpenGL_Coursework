//#include <iostream>
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//const char* vertexShaderSource = R"(
//#version 330 core
//layout (location = 0) in vec3 aPos;
//void main() {
//    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
//}
//)";
//
//const char* fragmentShaderSource = R"(
//#version 330 core
//out vec4 FragColor;
//void main() {
//    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
//}
//)";
//
//int main() {
//    // Initialize GLFW
//    glfwInit();
//
//    // Set window hints
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    // Create window
//    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Test", nullptr, nullptr);
//    if (window == nullptr) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    // Make the window's context current
//    glfwMakeContextCurrent(window);
//
//    // Initialize GLEW
//    glewExperimental = true;
//    if (glewInit() != GLEW_OK) {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    // Set up vertex data
//    float vertices[] = {
//            -0.5f, -0.5f, 0.0f,
//            0.5f, -0.5f, 0.0f,
//            0.0f,  0.5f, 0.0f
//    };
//
//    // Create a vertex buffer object
//    GLuint VBO;
//    glGenBuffers(1, &VBO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    // Set up vertex attributes
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
//    glEnableVertexAttribArray(0);
//
//    // Create a vertex shader
//    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
//    glCompileShader(vertexShader);
//
//    // Create a fragment shader
//    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
//    glCompileShader(fragmentShader);
//
//    // Create a shader program
//    GLuint shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    // Delete the shaders
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    // Set the clear color
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//
//    // Main loop
//    while (!glfwWindowShouldClose(window)) {
//        // Clear the color buffer
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // Use the shader program
//        glUseProgram(shaderProgram);
//
//        // Draw the triangle
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        // Swap the front and back buffers
//        glfwSwapBuffers(window);
//
//        // Poll for events
//        glfwPollEvents();
//    }
//
//    // Delete the vertex buffer object
//    glDeleteBuffers(1, &VBO);
//
//    // Delete the shader program
//    glDeleteProgram(shaderProgram);
//
//    // Terminate GLFW
//    glfwTerminate();
//
//    return 0;
//}

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Lib/imgui/imgui.h"
#include "Lib/imgui/imgui_impl_glfw.h"
#include "Lib/imgui/imgui_impl_opengl3.h"

#include "Source/ui/frontPage/frontPage.h"

int main() {
   // Initialize GLFW
    if (!glfwInit()) {
         std::cerr << "Failed to initialize GLFW" << std::endl;
         return -1;
    }
    GLFWwindow* window = glfwCreateWindow(1280, 720, "OpenGL Coursework", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // initialize front page
    frontPage frontPage(window);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render front page
        frontPage.render();

        // Swap the front and back buffers
        glfwSwapBuffers(window);

        // Poll for events
        glfwPollEvents();
    }
    // Cleanup
    frontPage.~frontPage();
    // Terminate GLFW
    glfwTerminate();

    return 0;

}