//
// Created by NigelWork on 20/04/2024.
//

#ifndef OPENGLCOURSEWORK_FRONTPAGE_H
#define OPENGLCOURSEWORK_FRONTPAGE_H

// This class will be used to display the front page of the application
// This will be the first thing the user sees when they open the application
// The front page will have a title, a description of the application, and a button to start the application

// The front page will be displayed using OpenGL and GLFW to create a window and render the front page
// The front page will be displayed using a simple 2D interface with text and buttons

// The front page will be created using the ImGui library which provides a simple way to create user interfaces

// include the necessary libraries
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../Lib/imgui/imgui.h"
#include "../../Lib/imgui/imgui_impl_glfw.h"
#include "../../Lib/imgui/imgui_impl_opengl3.h"

// create the frontPage class

class frontPage {

public:
    frontPage(GLFWwindow* window){
        setupImGui(window);
    }

    ~frontPage(){
        cleanupImGui();
    }

    void render(){
        renderUI();
    }

private:
    void setupImGui(GLFWwindow* window);

    void cleanupImGui();

    void renderUI();


    // create a variable to store the window pointer




};


#endif //OPENGLCOURSEWORK_FRONTPAGE_H
