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

    }

    void render(UI::sceneView* sceneView);

    void meshLoadCallback(const std::function<void(const std::string&)>& callback){
        mMeshLoadCallback = callback;
    }


private:
    std::string Currentfile;
    ImGui::FileBrowser fileDialog;
    std::function<void(const std::string&)> mMeshLoadCallback;

};
}


#endif //OPENGLCOURSEWORK_PROPERTYPANEL_H
