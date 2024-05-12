//
// Created by NigelWork on 11/05/2024.
//

#ifndef OPENGLCOURSEWORK_IMGUIWIDGETS_H
#define OPENGLCOURSEWORK_IMGUIWIDGETS_H

#include "../../packageM.h"
#include <imgui.h>
#include <imgui_internal.h>

namespace imguiWidgets{

    static void drawVec3Control(const std::string& label, glm::vec3& values, float resetValue = 0.0f, float columnWidth = 100.0f) {

        std::cout << "Entering drawVec3Control function\n";
        std::cout << "Label: " << label << "\n";
        std::cout << "Values: " << values.x << ", " << values.y << ", " << values.z << "\n";
        std::cout << "Reset Value: " << resetValue << "\n";
        std::cout << "Column Width: " << columnWidth << "\n";

        if (!&values){
            std::cerr << "Error: No values to draw" << std::endl;
            return;

        }
        ImGuiIO &io = ImGui::GetIO();
        auto boldFont = io.Fonts->Fonts[0];

        ImGui::PushID(label.c_str());




        ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

        float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
        ImVec2 buttonSize = {lineHeight + 3.0f, lineHeight};

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.1f, 0.15f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.2f, 0.2f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.8f, 0.1f, 0.15f, 1.0f));
        ImGui::PushFont(boldFont);
        if (ImGui::Button("X", buttonSize)) values.x = resetValue;
        ImGui::PopFont();
        ImGui::PopStyleColor(3);

        ImGui::SameLine();
        ImGui::DragFloat("##X", &values.x, 0.1f);
        ImGui::PopItemWidth();
        ImGui::SameLine();

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.7f, 0.3f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.8f, 0.4f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.2f, 0.7f, 0.3f, 1.0f));
        ImGui::PushFont(boldFont);
        if (ImGui::Button("Y", buttonSize)) values.y = resetValue;
        ImGui::PopFont();
        ImGui::PopStyleColor(3);

        ImGui::SameLine();
        ImGui::DragFloat("##Y", &values.y, 0.1f);
        ImGui::PopItemWidth();
        ImGui::SameLine();

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.1f, 0.2f, 0.7f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.2f, 0.3f, 0.8f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.1f, 0.2f, 0.7f, 1.0f));
        ImGui::PushFont(boldFont);
        if (ImGui::Button("Z", buttonSize)) values.z = resetValue;
        ImGui::PopFont();
        ImGui::PopStyleColor(3);

        ImGui::SameLine();
        ImGui::DragFloat("##Z", &values.z, 0.1f);
        ImGui::PopItemWidth();
        ImGui::PopStyleVar();
        ImGui::Columns(1);

        ImGui::PopID();


    }
}



#endif //OPENGLCOURSEWORK_IMGUIWIDGETS_H
