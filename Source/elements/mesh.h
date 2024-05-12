//
// Created by NigelWork on 23/04/2024.
//

#ifndef OPENGLCOURSEWORK_MESH_H
#define OPENGLCOURSEWORK_MESH_H



#include "vertexHolder.h"
#include "elements.h"
#include "../render/renderBase.h"
#include "../render/openGLBufferManager.h"
#include "../shader/shaderUtils.h"


namespace elements{
class mesh : public elements::Elements{
    public:
    mesh() = default;
    virtual ~mesh();
    bool loadMesh(const std::string& filename);
    void addVertex(const vertexHolder& vertex){
        mVertices.push_back(vertex);
    }
    void addVertexIndex(const unsigned int index){
        mIndices.push_back(index);
    }
    std::vector<vertexHolder>& getVertices(){
        return mVertices;
    }
    std::vector<unsigned int> getVertexIndices(){
        return mIndices;
    }

    void updateMaterialProperties(const glm::vec3& color, float roughness, float metallic) {
        mColor = color;
        mRoughness = roughness;
        mMetallic = metallic;
    }

    void update(shaderUtils::shader* shaderProgram) override{

        //
        shaderProgram->setVec3("albedo", mColor);

        shaderProgram->setF1(mRoughness, "roughness");
        shaderProgram->setF1(mMetallic, "metallic");
        shaderProgram->setF1(1.0f, "ao");
        shaderProgram->setF1(1.0f, "material.ao");

    }



    void init();
    void createBuffer();
    void destroyBuffer();
    void render() ;

    void bind();

    void unbind();

    glm::vec3 mColor = { 1.0f, 0.0f, 0.0f };
    float mRoughness = 0.2f;
    float mMetallic = 0.1f;



private:

    // Inherited via Elements
    std::vector<vertexHolder> mVertices;
    std::vector<unsigned int> mIndices;


    //buffer manager
    std::unique_ptr<render::vertexBuffer> mBufferManager;

    };
}

#endif //OPENGLCOURSEWORK_MESH_H
