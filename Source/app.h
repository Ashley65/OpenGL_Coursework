//
// Created by NigelWork on 07/05/2024.
//

#ifndef OPENGLCOURSEWORK_APP_H
#define OPENGLCOURSEWORK_APP_H

#include "window/TGWindow.h"
#include "elements/camera.h"




class app {

    public:
    app(const std::string& applicationName);

    static app& Instance(){
        if(mInstance == nullptr){
            mInstance = new app("OpenGL Coursework");
        }
        return *mInstance;
    }
    void loop();


private:
    static app* mInstance;

    std::unique_ptr<window::GLWindow> mWindow;


};


#endif //OPENGLCOURSEWORK_APP_H
