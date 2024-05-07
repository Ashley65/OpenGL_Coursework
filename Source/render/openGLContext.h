//
// Created by NigelWork on 06/05/2024.
//

#ifndef OPENGLCOURSEWORK_OPENGLCONTEXT_H
#define OPENGLCOURSEWORK_OPENGLCONTEXT_H

#pragma once

#include "renderBase.h"

namespace render {
    class openGLContext : public renderContext {
    public:
        bool init(IWindow *window) override;

        void preRender() override;

        void postRender() override;

        void endRender() override;

    };

}

#endif //OPENGLCOURSEWORK_OPENGLCONTEXT_H