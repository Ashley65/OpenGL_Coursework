//
// Created by NigelWork on 22/04/2024.
//

#ifndef OPENGLCOURSEWORK_INPUT_H
#define OPENGLCOURSEWORK_INPUT_H

#include <GLFW/glfw3.h>
#include <string>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

namespace element{
    enum class elemInput{
        KEY,
        MOUSE,
        SCROLL,
        Left = 0,
        Right = 1,
        Middle = 2,
        None =1024
    };

    class Input{
    public:
        static elemInput getKeyPressed(GLFWwindow *window){
            for(int i = 0; i < 1024; i++){
                if(glfwGetKey(window, i) == GLFW_PRESS){
                    return static_cast<elemInput>(i);
                }
            }
            return elemInput::None;
        }
    };
}

#endif //OPENGLCOURSEWORK_INPUT_H
