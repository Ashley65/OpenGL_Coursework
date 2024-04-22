//
// Created by NigelWork on 22/04/2024.
//

#ifndef OPENGLCOURSEWORK_ELEMENTS_H
#define OPENGLCOURSEWORK_ELEMENTS_H

#include "../shader/shaderUtils.h"

namespace elements {
    class Elements{
    public:
        virtual void update(shaderUtils::shader* shader) = 0;
    };
}




#endif //OPENGLCOURSEWORK_ELEMENTS_H
