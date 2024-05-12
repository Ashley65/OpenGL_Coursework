//
// Created by NigelWork on 06/05/2024.
//

#include "openGLContext.h"

// GL includes



#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glew.h>


namespace render
{

    static void onKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
     auto winCB = static_cast<IWindow*>(glfwGetWindowUserPointer(window));
        winCB->keyCallback(key, scancode, action, mods);
    }

    static void onScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
    {
        auto winCB = static_cast<IWindow*>(glfwGetWindowUserPointer(window));
        winCB->scrollCallback(yoffset);
    }
    static void onResizeCallback(GLFWwindow* window, int width, int height)
    {
        auto winCB = static_cast<IWindow*>(glfwGetWindowUserPointer(window));
        winCB->resizeCallback(width, height);
    }
    static void onCloseCallback(GLFWwindow* window)
    {
        auto winCB = static_cast<IWindow*>(glfwGetWindowUserPointer(window));
        winCB->closeWindow();
    }


    bool openGLContext::init(IWindow *window) {

        // init glfw
        if (!glfwInit())
        {
            std::cout << "Failed to initialize GLFW" << std::endl;
            return false;
        }

        // Create a window and store this window as window pointer so that it can be used in the callbacks later
        auto win = glfwCreateWindow(window->width, window->height, window->title.c_str(), nullptr, nullptr);
        window->setNativeWindow(win);

        if (!win)
        {
            std::cout << "Failed to create window" << std::endl;
            return false;
        }

        // initailize the window
        mWindow = window;

        // Set the window callbacks
        glfwSetWindowUserPointer(win, window);
        glfwSetKeyCallback(win, onKeyCallback);
        glfwSetScrollCallback(win, onScrollCallback);
        glfwSetWindowSizeCallback(win, onResizeCallback);
        glfwSetWindowCloseCallback(win, onCloseCallback);
        glfwMakeContextCurrent(win);

        GLenum err = glewInit();
        if (err != GLEW_OK)
        {
            // Problem: glewInit failed, something is seriously wrong. and it should be logged
            std::cout << "Failed to initialize GLEW" << std::endl;
            std::cout << glewGetErrorString(err) << std::endl;
            return false;
        }

        // Enable depth testing
        glEnable(GL_DEPTH_TEST);


        return true;

    }

    void openGLContext::preRender() {
        if (mWindow == nullptr) {
            // initialize the window
            std::cerr << "mWindow is null" << std::endl;
        }
        glViewport(0,0, mWindow->width, mWindow->height);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void openGLContext::postRender() {
        if (mWindow == nullptr) {
            std::cerr << "mWindow is null" << std::endl;
            return;
        }
        glfwSwapBuffers(static_cast<GLFWwindow*>(mWindow->getNativeWindow()));
        glfwPollEvents();
    }

    void openGLContext::endRender() {
        glfwDestroyWindow((GLFWwindow*)mWindow->getNativeWindow());
        glfwTerminate();
    }
}