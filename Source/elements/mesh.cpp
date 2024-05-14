//
// Created by NigelWork on 23/04/2024.
//

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include "SOIL2/SOIL2.h"

#include "../render/openGLBufferManager.h"



#include "mesh.h"


namespace elements{
    void elements::mesh::init() {
        mBufferManager = std::make_unique<render::vertexBuffer>();

        createBuffer();
    }
    bool mesh::loadMesh(const std::string &filename) {
        const uint32_t cMeshFlagsImport =
                aiProcess_CalcTangentSpace |
                aiProcess_Triangulate |
                aiProcess_SortByPType |
                aiProcess_GenNormals |
                aiProcess_GenUVCoords |
                aiProcess_OptimizeMeshes |
                aiProcess_ValidateDataStructure;

        Assimp::Importer importer;

        const aiScene* scene = importer.ReadFile(filename, cMeshFlagsImport);

        if (scene && scene->HasMeshes()) {
            mVertices.clear();
            mIndices.clear();

            auto* mesh = scene->mMeshes[0];

            for(uint32_t i = 0; i < mesh->mNumVertices; i++) {
                vertexHolder vertex;

                vertex.mPos = {mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z};
                vertex.mNormal = {mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z};

                addVertex(vertex);
            }

            for (size_t i = 0; i < mesh->mNumFaces; i++) {
                auto face = mesh->mFaces[i];

                for (size_t j = 0; j < face.mNumIndices; j++) {
                    addVertexIndex(face.mIndices[j]);
                }
            }

            init();
            return true;
        }

        return false;
    }


    void elements::mesh::createBuffer() {
        mBufferManager->createBuffers(mVertices, mIndices);
    }

    void elements::mesh::destroyBuffer() {
        mBufferManager->destroyBuffers();
    }

    void elements::mesh::render() {

        init();



        // Draw the triangles using the indices for the vertices in the vertex buffer
        mBufferManager->draw((int) mIndices.size());


    }

    void elements::mesh::bind() {
        mBufferManager->bind();
    }

    void elements::mesh::unbind() {
        mBufferManager->unbind();
    }


    mesh::~mesh() {
        destroyBuffer();

    }

    bool mesh::loadTexture(const std::vector<std::string> &filename) {
        return mTexture->loadTexture(filename[0]);
    }


}



