//
// Created by NigelWork on 22/04/2024.
//

#ifndef OPENGLCOURSEWORK_OPENGLBUFFERMANAGER_H
#define OPENGLCOURSEWORK_OPENGLBUFFERMANAGER_H

#include "renderBase.h"

#include "../../packageM.h"

namespace render {
  class vertexBuffer : public VerIndexBuffer {
  public:
      vertexBuffer() : VerIndexBuffer() {}
      void createBuffers(std::vector<elements::vertexHolder> vertices, std::vector<unsigned int> indices) override;
      void destroyBuffers() override;
      void bind() override;
      void unbind() override;
      void draw(int indexCount) override;
  };
  class frameBuffer : public fraBuffer {
    public:
        frameBuffer() : fraBuffer() {}
        void createFrameBuffer(int32_t width, int32_t height) override;
        void bind() override;
        void unbind() override;
        void destroyFrameBuffer() override;
        uint32_t getTexture() override;
  };
}

#endif //OPENGLCOURSEWORK_OPENGLBUFFERMANAGER_H
