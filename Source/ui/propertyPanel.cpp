//
// Created by NigelWork on 11/05/2024.
//


#include "../../packageM.h"
#include "propertyPanel.h"
#include "../utils/ImguiWidgets.h"

namespace UI{
void UI::propertyPanel::render(UI::sceneView *sceneView) {
    auto mesh = sceneView->getMesh();
    ImGui::Begin("Properties");
    if (ImGui::CollapsingHeader("Mesh",ImGuiTreeNodeFlags_DefaultOpen)) {

        if (ImGui::Button("Load Mesh")) {
            fileDialog.Open();
        }
        ImGui::SameLine();
        ImGui::Text(Currentfile.c_str());
    }


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

    if (ImGui::CollapsingHeader("Light",ImGuiTreeNodeFlags_DefaultOpen)) {
        ImGui::Separator();
        ImGui::Text("Light Position");
        if(sceneView != nullptr && sceneView->getLight() != nullptr) {
            imguiWidgets::drawVec3Control("Position", sceneView->getLight()->mPosition);
        } else {
            // Log an error message or handle the error appropriately
            std::cerr << "Error: No light to draw" << std::endl;

        }

    }

    ImGui::End();

    fileDialog.Display();
    if (fileDialog.HasSelected()){
        auto path = fileDialog.GetSelected().string();
        Currentfile = path.substr(path.find_last_of("/\\") + 1);
        mMeshLoadCallback(path);
        fileDialog.ClearSelected();
    }

}

} // namespace UI
