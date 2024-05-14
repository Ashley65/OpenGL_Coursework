//
// Created by NigelWork on 21/04/2024.
//

#include "TGWindow.h"
#include "../importMesh/objImport.h"


namespace window{
    bool GLWindow::init(int mWidth, int mHeight, const std::string& mTitle) {
        width = mWidth;
        height = mHeight;
        title = mTitle;



        mRenderCtx->init(this);
        mUICtx->init(this);

        sceneViewCtx = std::make_unique<sceneView>();
        propertyPanelCtx = std::make_unique<propertyPanel>();

        propertyPanelCtx->meshLoadCallback([this](const std::string& path){
            sceneViewCtx->loadMesh(path);
        });

        propertyPanelCtx->textureLoadCallback([this](const std::string& path){
            sceneViewCtx->loadTexture({path});
        });






        return isRunning;
    }

    GLWindow::~GLWindow() {
        mRenderCtx->endRender();
        mUICtx->endRender();
    }

    void GLWindow::keyCallback(int key, int scancode, int action, int mods) {

        if (action == GLFW_PRESS) {
            // This is the escape key m
            if (key == GLFW_KEY_ESCAPE) {
                closeWindow();
            }
            // This checks if the key is the space key and activates the camera movement
            if (key == GLFW_KEY_SPACE) {
                //check if the camera is active
                if (sceneViewCtx->isCameraActive()) {
                    sceneViewCtx->onMouseRelease();
                } else {
                    sceneViewCtx->onMouseClick();
                }

            }
            // activates the camera movement
            if (key == GLFW_KEY_W) {
                sceneViewCtx->moveCameraForward();
            }
            if (key == GLFW_KEY_S) {
                sceneViewCtx->moveCameraBackward();
            }
            if (key == GLFW_KEY_R) {
                sceneViewCtx->resetCamera();
            }
            if (key == GLFW_KEY_A) {
                sceneViewCtx->moveCameraLeft();
            }
            if (key == GLFW_KEY_D) {
                sceneViewCtx->moveCameraRight();
            }
            if (key == GLFW_KEY_Q) {
                sceneViewCtx->moveCameraUp();
            }
            if (key == GLFW_KEY_E) {
                sceneViewCtx->moveCameraDown();
            }




        }

    }

    void GLWindow::scrollCallback(double delta) {
        sceneViewCtx->OnMouseScroll(delta);

    }

    void GLWindow::resizeCallback(int width, int height) {
        width = width;
        height = height;

        sceneViewCtx ->resize(width, height);
        render();
    }

    void GLWindow::closeWindow() {
        isRunning = false;

    }

    void GLWindow::render() {

        mRenderCtx ->preRender();
        mUICtx ->preRender();

        sceneViewCtx -> render();
        propertyPanelCtx -> render(sceneViewCtx.get());

        mUICtx ->postRender();

        mRenderCtx -> postRender();

        handleInput();



    }

    void GLWindow::handleInput() {
        double x, y;
        glfwGetCursorPos(mWindow, &x, &y);

        sceneViewCtx->onMouseMove(x, y, element::elemInput::Right);

    }


}