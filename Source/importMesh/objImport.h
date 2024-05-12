//
// Created by NigelWork on 07/05/2024.
//

#ifndef OPENGLCOURSEWORK_OBJIMPORT_H
#define OPENGLCOURSEWORK_OBJIMPORT_H
#pragma once

#include "importBase.h"
namespace importMesh {
    class objImport : public importerMesh {
    public:
       virtual bool fromFile(const std::string& path, elements::mesh* mesh) override;
    };
}


#endif //OPENGLCOURSEWORK_OBJIMPORT_H
