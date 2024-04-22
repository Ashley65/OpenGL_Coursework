//
// Created by NigelWork on 21/04/2024.
//

#ifndef OPENGLCOURSEWORK_WINDOWBASE_H
#define OPENGLCOURSEWORK_WINDOWBASE_H

#pragma once


#include <string>

class IWindow {
public:
    virtual void *getNativeWindow() = 0;
    virtual void setNativeWindow(void *window) = 0;
    virtual void keyCallback(int key, int scancode, int action, int mods) = 0;
    virtual void scrollCallback(double delta) = 0;
    virtual void resizeCallback(int width, int height) = 0;
    virtual void closeWindow() = 0;

    int width;
    int height;
    std::string title;


};


#endif //OPENGLCOURSEWORK_WINDOWBASE_H
