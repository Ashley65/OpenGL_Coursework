//
// Created by NigelWork on 21/04/2024.
//

#ifndef OPENGLCOURSEWORK_VERTEXHOLDER_H
#define OPENGLCOURSEWORK_VERTEXHOLDER_H

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>
#include <string>

namespace elements {
    class vertexHolder{
    public:
        vertexHolder() : mPos(), mNormal(),mUV(){

        }
        vertexHolder(glm::vec3 pos, glm::vec3 normal, glm::vec2 uv);
        vertexHolder(const std::vector<std::string> tokens);
        glm::vec3 mPos{};
        glm::vec3 mNormal{};
        glm::vec2 mUV{};

    };
};


#endif //OPENGLCOURSEWORK_VERTEXHOLDER_H
