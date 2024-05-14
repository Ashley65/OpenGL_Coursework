//
// Created by NigelWork on 14/05/2024.
//

#include "texture.h"

bool elements::texture::loadTexture(const std::string &filename) {
    mTextureID = SOIL_load_OGL_texture(filename.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y);
    if (mTextureID == 0){
        std::cerr << "Error loading texture: " << filename << " : " << SOIL_last_result() << std::endl;
        mTextureLoaded = false;
        return false;
    } else {
        mTextureLoaded = true;
        return true;
    }
}

void elements::texture::bind(int textureUnit) const {
    if(mTextureLoaded){
        glActiveTexture(GL_TEXTURE0 + textureUnit);
        glBindTexture(GL_TEXTURE_2D, mTextureID);
    }

}
