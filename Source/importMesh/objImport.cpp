//
// Created by NigelWork on 07/05/2024.
//

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include "objImport.h"
#include "../elements/vertexHolder.h"
#include "../utils/strUtils.h"


bool importMesh::objImport::fromFile(const std::string &path, elements::mesh *mesh) {
    std::ifstream in(path, std::ios::in);
    if (!in) {
        std::cerr << "Cannot open " << path << std::endl;
        return false;
    }
    std::vector<glm::vec3> t_vertices;
    std::vector<glm::vec2> t_uvs;
    std::vector<glm::vec3> t_normals;

    std::string sLine;

    // Read the file line by line and parse the data
    while (std::getline(in, sLine)){
        std::istringstream s(sLine);
        std::string sType;
        s >> sType;
        // Check the type of the line and parse the data. if the line is a vertex, uv or normal, store it in the corresponding vector
        if (sType == "v"){
            //read the vertex data
            glm::vec3 vertex;

            s >> vertex.x >> vertex.y >> vertex.z;
            //add to a temporary vertices before indexing
            t_vertices.push_back(vertex);
        } else if (sType == "vt"){
            glm::vec2 uv;
            s >> uv.x >> uv.y;
            t_uvs.push_back(uv);
        } else if (sType == "vn"){
            glm::vec3 normal;
            s >> normal.x >> normal.y >> normal.z;
            t_normals.push_back(normal);

        } else if (sType == "f"){
            std::vector<std::string> tokens;
            std::string v1, v2, v3;
            s >> v1 >> v2 >> v3;

            uint32_t vertexIndex[3], uvIndex[3], normalIndex[3];
            //parse the face data
            vertexIndex[0] = strUtils::tokenize(v1, '/').at(0);
            vertexIndex[1] = strUtils::tokenize(v2, '/').at(0);
            vertexIndex[2] = strUtils::tokenize(v3, '/').at(0);


            mesh->addVertexIndex(vertexIndex[0] - 1);
            mesh->addVertexIndex(vertexIndex[1] - 1);
            mesh->addVertexIndex(vertexIndex[2] - 1);



            // now use the indices to create the concrete vertices for the mesh

        }
    }

    //now use the indices to create the concrete vertices for the mesh
    for (auto vIndex: mesh -> getVertexIndices()){
        elements::vertexHolder vertexHolder;
        vertexHolder.mPos = t_vertices[vIndex];
        vertexHolder.mUV = t_uvs[vIndex];
        vertexHolder.mNormal = t_normals[vIndex];
        mesh->addVertex(vertexHolder);
    }
    return true;
}
