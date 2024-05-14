//
// Created by NigelWork on 11/05/2024.
//

#ifndef OPENGLCOURSEWORK_PROPERTYPANEL_H
#define OPENGLCOURSEWORK_PROPERTYPANEL_H

#include "../elements/light.h"
#include "sceneView.h"


//imgui library
#include <imgui.h>
#include "../utils/ImguiWidgets.h"
#include <ImFileBrowser.h>
#include <functional>

namespace UI{
class propertyPanel {
public:
    propertyPanel(){

        Currentfile = "<`No File Loaded`>";
        fileDialog.SetTitle("Find a file to load");
        fileDialog.SetTypeFilters({".obj", ".fbx", ".dae"});


        //texture file dialog
        textureFile = "<`No File Loaded`>";
        textureFileDialog.SetTitle("Find a texture file to load");
        textureFileDialog.SetTypeFilters({".png", ".jpg", ".jpeg"});

    }

    void render(UI::sceneView* sceneView);

    void meshLoadCallback(const std::function<void(const std::string&)>& callback){
        mMeshLoadCallback = callback;
    }
    void textureLoadCallback(const std::function<void(const std::string&)>& callback){
        mTextureLoadCallback = callback;
    }


private:
    std::string Currentfile;
    std::string textureFile;
    ImGui::FileBrowser fileDialog;
    ImGui::FileBrowser textureFileDialog;
    std::function<void(const std::string&)> mMeshLoadCallback;
    std::function<void(const std::string&)> mTextureLoadCallback;


};
}


#endif //OPENGLCOURSEWORK_PROPERTYPANEL_H
