//
// Created by NigelWork on 24/04/2024.
//

#ifndef OPENGLCOURSEWORK_LIGHT_H
#define OPENGLCOURSEWORK_LIGHT_H


#include "elements.h"
#include "../shader/shaderUtils.h"

namespace elements {
    class light : public elements::Elements {

    public:
        light(){
            mColor = {1.0f, 1.0f, 1.0f};
            mPosition = {0.0f, 0.0f, 0.0f};
            mAmbient = {0.2f, 0.2f, 0.2f};
            mDiffuse = {0.5f, 0.5f, 0.5f};
            mSpecular = {1.0f, 1.0f, 1.0f};
            mStrength = 100.0f;
        }

        ~light() {}

        void update(shaderUtils::shader* shader) override {
            shader->setVec3("light.position", mPosition);
            shader->setVec3("light.ambient", mAmbient);
            shader->setVec3("light.diffuse", mDiffuse);
            shader->setVec3("light.Color", mColor * mStrength);
            shader->setVec3("light.specular", mSpecular);

        }

        glm::vec3 mColor{};
        glm::vec3 mPosition{};
        glm::vec3 mAmbient{};
        glm::vec3 mDiffuse{};
        glm::vec3 mSpecular{};
        float mStrength;









    };
}

#endif //OPENGLCOURSEWORK_LIGHT_H
