//
// Created by NigelWork on 22/04/2024.
//

#include "../../packageM.h"
#include "openGLBufferManager.h"

void render::vertexBuffer::createBuffers(std::vector<elements::vertexHolder> vertices, std::vector<unsigned int> indices) {
    glGenVertexArrays(1, &mVA);
    glBindVertexArray(mVA);

    glGenBuffers(1, &mVB);
    glBindBuffer(GL_ARRAY_BUFFER, mVB);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(elements::vertexHolder), vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &mIB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(elements::vertexHolder), (const void*)offsetof(elements::vertexHolder, mPos));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(elements::vertexHolder), (const void*)offsetof(elements::vertexHolder, mNormal));

    // Texture coordinates
    glEnableVertexAttribArray(2);
    // 2 is the index of the texture coordinates
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(elements::vertexHolder), (const void*)offsetof(elements::vertexHolder, mUV));

    glBindVertexArray(0);

}

void render::vertexBuffer::destroyBuffers() {
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDeleteVertexArrays(1, &mVA);
    glDeleteBuffers(1, &mVB);
    glDeleteBuffers(1, &mIB);
}

void render::vertexBuffer::bind() {
    glBindVertexArray(mVA);
}

void render::vertexBuffer::unbind() {
    glBindVertexArray(0);
}

void render::vertexBuffer::draw(int indexCount) {
    bind();

    // Draw the triangles using the indices for the vertices in the vertex buffer
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);

    unbind();

}

// This section will be used to create a frame buffer foe the object



void render::frameBuffer::createFrameBuffer(int32_t width, int32_t height) {

    mWidth = width;
    mHeight = height;




    if (mFBO) {
        destroyFrameBuffer();
    }



    // Generate the frame buffer object
    glGenFramebuffers(1, &mFBO);
    // Bind the frame buffer object
    glBindFramebuffer(GL_FRAMEBUFFER, mFBO);
    glCreateTextures(GL_TEXTURE_2D, 1, &mTexId);
    glBindTexture(GL_TEXTURE_2D, mTexId);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mTexId, 0);

    glCreateTextures(GL_TEXTURE_2D, 1, &mDepthId);
    glBindTexture(GL_TEXTURE_2D, mDepthId);
    glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH24_STENCIL8, mWidth, mHeight);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    if (mDepthId == 0) {
        std::cerr << "mDepthId is not initialized" << std::endl;
        return;
    }

    if (!glIsTexture(mDepthId)) {
        std::cerr << "mDepthId is not a valid texture" << std::endl;
        return;
    }

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, mDepthId, 0);

    GLenum buffers[4] = { GL_COLOR_ATTACHMENT0 };
    glDrawBuffers(mTexId, buffers);

    unbind();




}

void render::frameBuffer::bind() {
    glBindFramebuffer(GL_FRAMEBUFFER, mFBO);
    glViewport(0, 0, mWidth, mHeight);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void render::frameBuffer::unbind() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void render::frameBuffer::destroyFrameBuffer() {
    if (mFBO)
    {
        glDeleteFramebuffers(GL_FRAMEBUFFER, &mFBO);
        glDeleteTextures(1, &mTexId);
        glDeleteTextures(1, &mDepthId);
        mTexId = 0;
        mDepthId = 0;
    }
}

uint32_t render::frameBuffer::getTexture() {
    return mTexId;
}