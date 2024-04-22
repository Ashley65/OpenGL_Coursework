//
// Created by NigelWork on 20/04/2024.
//

#include "frontPage.h"

void frontPage::setupImGui(GLFWwindow *window) {

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

void frontPage::cleanupImGui() {
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

}

void frontPage::renderUI() {
    // Start the ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Render the UI
    ImGui::Begin("Front Page");

    ImGui::Text("Welcome to the OpenGL Coursework");
    ImGui::Text("This application will demonstrate the use of OpenGL to create 3D graphics");
    ImGui::Text("Press the button below to start the application");

    if (ImGui::Button("Start Application")) {
        // Start the application
    }

    ImGui::End();

    // Render the ImGui frame
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

