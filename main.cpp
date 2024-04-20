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

int main() {
    // Setup GLFW and GLEW as before...
    glfwInit();

    // Set window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Test", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        glfwTerminate();
        return -1;
    }


    // Setup ImGui binding
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window)) {
        // Start the ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Create a simple ImGui window
        ImGui::Begin("Test Window");
        ImGui::Text("Hello, ImGui!");
        ImGui::End();

        //create a menu bar
        if (ImGui::BeginMainMenuBar()) {
            // File menu
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("Open", "Ctrl+O")) {
                    // Handle Open action

                }
                if (ImGui::MenuItem("Save", "Ctrl+S")) {
                    // Handle Save action
                }
                if (ImGui::MenuItem("Save As..")) {
                    // Handle Save As action
                }
                ImGui::EndMenu();
            }
            // Edit menu
            if (ImGui::BeginMenu("Edit")) {
                if (ImGui::MenuItem("Undo", "Ctrl+Z")) {
                    // Handle Undo action
                }
                if (ImGui::MenuItem("Redo", "Ctrl+Y", false, false)) { // Disabled item
                    // Handle Redo action
                }
                // More items...
                ImGui::EndMenu();
            }
            // Other menus...

            ImGui::EndMainMenuBar();
        }

        // Render ImGui
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();


    }

    // Cleanup ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // Cleanup GLFW and GLEW...
    glfwTerminate();


    return 0;
}