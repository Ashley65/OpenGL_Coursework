//
// Created by NigelWork on 25/04/2024.
//

#ifndef OPENGLCOURSEWORK_SCENEVIEW_H
#define OPENGLCOURSEWORK_SCENEVIEW_H



#include "../elements/mesh.h"
#include "../elements/light.h"
#include "../elements/camera.h"
#include "../render/openGLBufferManager.h"
#include "../elements/input.h"
#include "../shader/shaderUtils.h"


namespace UI{

    class sceneView {
        public:
        sceneView():mCamera(nullptr), mLight(nullptr), mShader(nullptr), mFrameBuffer(nullptr), mScreenSize({800, 600}){
            mFrameBuffer = std::make_shared<render::frameBuffer>();
            mFrameBuffer->createFrameBuffer(mScreenSize.x, mScreenSize.y);
            mShader = std::make_unique<shaderUtils::shader>();

            mShader->loadShader("../shaders/vertexShader.glsl", "../shaders/fragmentShader.glsl");
            mLight = std::make_shared<elements::light>();

            mCamera = std::make_unique<element::camera>(glm::vec3(0.0f, 0.0f, 3.0f), 45.0f, 1.3f, 0.1f, 100.0f);

        }
        ~sceneView(){
            mShader->unloadShader();
        }
        void resize(int32_t width, int32_t height);
        void render();
        void loadMesh(const std::string& path);
        void setMesh(const std::shared_ptr<elements::mesh>& mesh){
            mMesh = mesh;
        }
        std::shared_ptr<elements::mesh> getMesh(){
            return mMesh;
        }
        // get light
        std::shared_ptr<elements::light> getLight(){
            return mLight;
        }
        // get camera
        std::shared_ptr<element::camera> getCamera(){
            return mCamera;
        }
        void OnMouseScroll(float offset);
        void onMouseMove(float x, float y, element::elemInput button);

        void resetCamera(){
            mCamera->reset();
        }



    private:
        std::shared_ptr<element::camera> mCamera;
        std::shared_ptr<elements::light> mLight;
        std::shared_ptr<elements::mesh> mMesh;
        std::shared_ptr<element::Input> mInput;
        std::shared_ptr<shaderUtils::shader> mShader;
        std::shared_ptr<render::fraBuffer> mFrameBuffer;
        glm::vec2 mScreenSize;


    };

}

#endif //OPENGLCOURSEWORK_SCENEVIEW_H
