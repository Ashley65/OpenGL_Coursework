//
// Created by NigelWork on 14/05/2024.
//

#ifndef OPENGLCOURSEWORK_TEXTURE_H
#define OPENGLCOURSEWORK_TEXTURE_H

#include "elements.h"

namespace elements {
    class texture : public Elements {
    public:
        texture() : mTextureID(0), mTextureLoaded(false) {}
        bool loadTexture(const std::string &filename);
        void bind(int textureUnit = 0) const;
        GLuint getTextureID() const { return mTextureID; }
        bool isTextureLoaded() const { return mTextureLoaded; }


    private:
        GLuint mTextureID;
        bool mTextureLoaded;
    };
}


#endif //OPENGLCOURSEWORK_TEXTURE_H
