//
// Created by NigelWork on 07/05/2024.
//

#ifndef OPENGLCOURSEWORK_IMPORTBASE_H
#define OPENGLCOURSEWORK_IMPORTBASE_H

#include "../elements/mesh.h"

namespace importMesh {
    struct importerMesh{
        virtual bool fromFile(const std::string& path, elements::mesh* mesh) = 0;
    };
}

#endif //OPENGLCOURSEWORK_IMPORTBASE_H
