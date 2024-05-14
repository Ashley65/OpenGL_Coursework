//
// Created by NigelWork on 24/04/2024.
//

#ifndef OPENGLCOURSEWORK_LIGHT_H
#define OPENGLCOURSEWORK_LIGHT_H

#pragma once

#include "../../packageM.h"
#include "elements.h"
#include "../shader/shaderUtils.h"

namespace elements {
    class light : public elements::Elements {

    public:
        light(){
            mColor = glm::vec3 {1.0f, 1.0f, 1.0f};
            mPosition = {0.0f, 0.0f, 0.0f};
            mAmbient = {0.2f, 0.2f, 0.2f};
            mDiffuse = {0.5f, 0.5f, 0.5f};
            mSpecular = {1.0f, 1.0f, 1.0f};
            mStrength = 100.0f;
        }

        ~light() {}

        void update(shaderUtils::shader* shader) override {
            shader->setVec3("lightPosition", mPosition);
            shader->setVec3("lightAmbient", mAmbient);
            shader->setVec3("lightDiffuse", mDiffuse);
            shader->setVec3("lightColor", mColor * mStrength);
            shader->setVec3("lightSpecular", mSpecular);

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
