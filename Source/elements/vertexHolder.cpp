//
// Created by NigelWork on 21/04/2024.
//

#include "vertexHolder.h"

elements::vertexHolder::vertexHolder(const std::vector<std::string> tokens) {
    //Convert each string to a float
    mPos = glm::vec3(std::stof(tokens[0]), std::stof(tokens[1]), std::stof(tokens[2]));
    mNormal = glm::vec3(std::stof(tokens[3]), std::stof(tokens[4]), std::stof(tokens[5]));
    mUV = glm::vec2(std::stof(tokens[6]), std::stof(tokens[7]));
}

elements::vertexHolder::vertexHolder(glm::vec3 pos, glm::vec3 normal, glm::vec2 uv)
: mPos(pos), mNormal(normal), mUV(uv){



}
