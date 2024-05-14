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
#include "texture.h"



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

    void update(shaderUtils::shader* shaderProgram) override{

        //
        shaderProgram->setVec3("albedo", mColor);

        shaderProgram->setF1(mRoughness, "roughness");
        shaderProgram->setF1(mMetallic, "metallic");
        shaderProgram->setF1(1.0f, "ao");
        shaderProgram->setF1(1.0f, "material.ao");

        shaderProgram->setI1(mTextureLoaded ? 1 : 0, "textureLoaded");

        // update the camera position
        shaderProgram->setVec3("camPos", {0.0f, 0.0f, 0.0f});


    }
    bool loadTexture(const std::vector<std::string>& filename);



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

    // texture manager
     std::shared_ptr<elements::texture> mTexture;

    bool mTextureLoaded = false;

    };
}

#endif //OPENGLCOURSEWORK_MESH_H
