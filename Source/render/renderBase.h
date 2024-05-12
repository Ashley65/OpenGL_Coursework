//
// Created by NigelWork on 21/04/2024.
//

#ifndef OPENGLCOURSEWORK_RENDERBASE_H
#define OPENGLCOURSEWORK_RENDERBASE_H

#pragma once

#include "../../packageM.h"


#include "../elements/vertexHolder.h"
#include "../window/windowBase.h"

namespace render {
    class VerIndexBuffer {
    public:
        VerIndexBuffer(): mVB(0), mIB(0), mVA(0) {}

        virtual void createBuffers(std::vector<elements::vertexHolder> vertices, std::vector<unsigned int> indices) = 0;
        virtual void destroyBuffers() = 0;
        virtual void bind() = 0;
        virtual void unbind() = 0;
        virtual void draw(int indexCount) = 0;


    protected:
        GLuint mVB;
        GLuint  mIB;
        GLuint  mVA;

    };

    class fraBuffer {
    public:

        fraBuffer(): mFBO(0), mDepthId{0}
        {

        }

        virtual void createFrameBuffer(int32_t width, int32_t height) = 0;

        virtual void bind() = 0;

        virtual void unbind() = 0;

        virtual void destroyFrameBuffer() = 0;

        virtual uint32_t getTexture() = 0;

    protected:
        uint32_t mFBO = 0;
        uint32_t mTexId = 0;
        uint32_t mDepthId = 0;
        int32_t mWidth = 0;
        int32_t mHeight = 0;
    };

    class renderContext{
    public:
        renderContext(): mWindow(nullptr)
        {

        }
        virtual bool init(IWindow* window){
            mWindow = window;
            return true;
        }

        virtual void preRender() = 0;
        virtual void postRender() = 0;

        virtual void endRender() = 0;




    protected:
        IWindow* mWindow;
    };
}



#endif //OPENGLCOURSEWORK_RENDERBASE_H
