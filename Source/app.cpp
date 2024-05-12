//
// Created by NigelWork on 07/05/2024.
//

#include "app.h"

app *app::mInstance = nullptr;

app::app(const std::string &applicationName) {

    mWindow = std::make_unique<window::GLWindow>();
    mWindow->init(1280, 720, applicationName);

}

void app::loop() {
    while (mWindow->isRunningWindow()) {
        mWindow->handleInput();
        mWindow->render();
    }
}
