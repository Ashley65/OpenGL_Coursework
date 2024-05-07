//
// Created by NigelWork on 21/04/2024.
//

#ifndef OPENGLCOURSEWORK_TGWINDOW_H
#define OPENGLCOURSEWORK_TGWINDOW_H

#pragma once
//including th shader class
#include "../shader/shaderUtils.h"
// include the elements need for running the rendering engine
#include "../elements/mesh.h"
#include "../elements/light.h"
#include "../elements/camera.h"
// include the render engine classes
#include "../render/openGLBufferManager.h"
#include "../render/openGLContext.h"
#include "../render/uiContext.h"
// include the window base class
#include "windowBase.h"
// including the ui elements for the window
#include "../ui/sceneView.h"

#include <memory>

using namespace render;
using namespace elements;
using namespace UI;


namespace window {
    class GLWindow : public IWindow {
    public:
        GLWindow(): isRunning(true), mWindow(nullptr)
        {


            mUICtx = std::make_unique<uiContext>();
            mRenderCtx = std::make_unique<openGLContext>();

        }
        ~GLWindow();

        bool init(int mWidth, int mHeight, const std::string& mTitle);

        void *getNativeWindow() override {
            return mWindow;
        }
        void setNativeWindow(void *window) override {
            mWindow = (GLFWwindow*)window;
        }

        void keyCallback(int key, int scancode, int action, int mods) override;
        void scrollCallback(double delta) override;
        void resizeCallback(int width, int height) override;
        void closeWindow() override;
        void render();
        void handleInput();

        bool isRunningWindow() const { return isRunning; }

    private:

        // make a window context
        GLFWwindow *mWindow;
        // make a render context
        std::unique_ptr<openGLContext> mRenderCtx;
        // make a ui context
        std::unique_ptr<uiContext> mUICtx;
        // UI context for the window components
        std::unique_ptr<sceneView> sceneViewCtx;

        bool isRunning;




    };

}
\

#endif //OPENGLCOURSEWORK_TGWINDOW_H
