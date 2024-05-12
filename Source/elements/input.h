//
// Created by NigelWork on 22/04/2024.
//

#ifndef OPENGLCOURSEWORK_INPUT_H
#define OPENGLCOURSEWORK_INPUT_H

#include "../../packageM.h"

namespace element{
    enum class elemInput{

        Left = 0,
        Right = 1,
        Middle = 2,
        None =9
    };

    class Input{
    public:
        static elemInput getKeyPressed(GLFWwindow *window){
           elemInput result = elemInput::None;

           if(glfwGetMouseButton(window, 0) == GLFW_PRESS)
               return elemInput::Left;
           else if(glfwGetMouseButton(window, 1) == GLFW_PRESS)
               return elemInput::Right;
           else if(glfwGetMouseButton(window, 2) == GLFW_PRESS)
               return elemInput::Middle;


            return elemInput::None;
        }
    };
}

#endif //OPENGLCOURSEWORK_INPUT_H
