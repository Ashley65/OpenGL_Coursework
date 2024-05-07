//
// Created by NigelWork on 25/04/2024.
//

#include "sceneView.h"
#include <imgui.h>

namespace UI{

void UI::sceneView::resize(int32_t width, int32_t height) {
    mScreenSize.x = width;
    mScreenSize.y = height;
    mFrameBuffer->createFrameBuffer(int32_t(mScreenSize.x), int32_t(mScreenSize.y));

}

void UI::sceneView::OnMouseScroll(float offset) {
    mCamera->onMouseWheel(offset);
}


void UI::sceneView::onMouseMove(float x, float y, element::elemInput button) {
    mCamera->onMouseMove(x, y, button);
}

void UI::sceneView::loadMesh(const std::string &path) {
    if (mMesh) {
        mMesh->loadMesh(path);
    } else {
        mMesh = std::make_shared<elements::mesh>();
        mMesh->loadMesh(path);
    }

}

void UI::sceneView::render() {

    mShader->useShader();
    // need to add light
    mLight->update(mShader.get());

    mFrameBuffer->bind();

    if (mMesh){
        mMesh->update(mShader.get());
        mMesh->render();
    }

    mFrameBuffer->unbind();
    ImGui::Begin("Scene");

    ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
    mScreenSize = {viewportPanelSize.x, viewportPanelSize.y};

    mCamera->setAspect(mScreenSize.x/mScreenSize.y);
    mCamera->update(mShader.get());

    // add rendered texture to ImGUI scene window
    uint64_t textureID = mFrameBuffer->getTexture();
    ImGui::Image((void*)textureID, viewportPanelSize, ImVec2(0, 1), ImVec2(1, 0));

    ImGui::End();


}

}