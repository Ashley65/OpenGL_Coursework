//
// Created by NigelWork on 11/05/2024.
//


#include "../../packageM.h"
#include "propertyPanel.h"
#include "../utils/ImguiWidgets.h"

namespace UI{
void UI::propertyPanel::render(UI::sceneView *sceneView) {
    auto mesh = sceneView->getMesh();
    // get the texture


    ImGui::Begin("Properties");
    if (ImGui::CollapsingHeader("Mesh",ImGuiTreeNodeFlags_DefaultOpen)) {

        if (ImGui::Button("Load Mesh")) {
            fileDialog.Open();
        }
        ImGui::SameLine();
        ImGui::Text(Currentfile.c_str());
    }

    ImGui::Separator();

    if (ImGui::CollapsingHeader("Texture",ImGuiTreeNodeFlags_DefaultOpen)) {
        if (ImGui::Button("Load Texture")) {
            textureFileDialog.Open();
        }
        ImGui::SameLine();
        ImGui::Text(textureFile.c_str());
    }

    ImGui::Separator();

    if (ImGui::CollapsingHeader("Material",ImGuiTreeNodeFlags_DefaultOpen)) {

        if (!mesh) {
            ImGui::Text("No Mesh Loaded");
        } else {

            ImGui::ColorPicker3("Colour", &mesh->mColor[0],
                                ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_DisplayRGB);
            ImGui::SliderFloat("Roughness", &mesh->mRoughness, 0.0f, 1.0f);
            ImGui::SliderFloat("Metallic", &mesh->mMetallic, 0.0f, 1.0f);

        }
    }


    ImGui::Separator();

    if (ImGui::CollapsingHeader("Light",ImGuiTreeNodeFlags_DefaultOpen)) {
        ImGui::Separator();
        ImGui::Text("Light Position");
        if(sceneView != nullptr && sceneView->getLight() != nullptr) {
            imguiWidgets::drawVec3Control("Position", sceneView->getLight()->mPosition);
        } else {
            // Log an error message or handle the error appropriately
            std::cerr << "Error: No light to draw" << std::endl;

        }
        ImGui::Separator();
        ImGui::Text("Light Strength");
        ImGui::SliderFloat("Strength", &sceneView->getLight()->mStrength, 0.0f, 1000.0f);
        ImGui::Separator();
        ImGui::Text("Light Colour");
        ImGui::ColorPicker3("Colour", &sceneView->getLight()->mColor[0],
                            ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_DisplayRGB);
    }

    // Camera properties
    if (ImGui::CollapsingHeader("Camera",ImGuiTreeNodeFlags_DefaultOpen)){
        ImGui::Separator();

        ImGui::Separator();
        ImGui::Text("Camera Reset");
        // Reset Camera
        if (ImGui::Button("Reset Camera")){
            sceneView->resetCamera();
        }
    }

    // c



    ImGui::End();

    fileDialog.Display();
    if (fileDialog.HasSelected()){
        auto path = fileDialog.GetSelected().string();
        Currentfile = path.substr(path.find_last_of("/\\") + 1);
        mMeshLoadCallback(path);
        fileDialog.ClearSelected();
    }

    textureFileDialog.Display();
    if (textureFileDialog.HasSelected()){
        auto path = textureFileDialog.GetSelected().string();
        textureFile = path.substr(path.find_last_of("/\\") + 1);
        sceneView->getMesh()->loadTexture({path});
        textureFileDialog.ClearSelected();
    }

}

} // namespace UI
