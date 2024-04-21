//
// Created by NigelWork on 21/04/2024.
//

#ifndef OPENGLCOURSEWORK_RENDERBASE_H
#define OPENGLCOURSEWORK_RENDERBASE_H

#include "../window/windowBase.h"

namespace render {
    class IRender {
    public:
        virtual void init() = 0;
        virtual void render() = 0;
        virtual void update() = 0;
        virtual void setWindow(IWindow *window) = 0;
        virtual void setWindowSize(int width, int height) = 0;
        virtual void setWindowTitle(std::string title

#endif //OPENGLCOURSEWORK_RENDERBASE_H
