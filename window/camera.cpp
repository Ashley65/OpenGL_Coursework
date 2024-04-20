//
// Created by NigelWork on 15/04/2024.
//

#include "camera.h"

camera::camera()
        : position(0.0f, 0.0f, 0.0f),
          yaw(0.0f),
          pitch(0.0f),
          fov(45.0f),
          aspect(4.0f / 3.0f),
          nearClip(0.1f),
          farClip(100.0f) {}

void camera::setCameraPosition(const glm::vec3 &position) {
    this->position = position;

}
void camera::setRotation(float yaw, float pitch) {
    if (pitch > 89.0f || pitch < -89.0f) {
        throw std::runtime_error("Invalid pitch");
    }
    this->yaw = yaw;
    this->pitch = pitch;
}
void camera::setFOV(float fov) {
    if (fov <= 0 || fov >= 180) {
        throw std::runtime_error("Invalid FOV");
    }
    this->fov = fov;
}
void camera::setAspect(float aspect) {
    if (aspect <= 0) {
        throw std::runtime_error("Invalid aspect ratio");
    }
    this->aspect = aspect;
}
void camera::setNearClip(float nearClip) {
    if (nearClip <= 0) {
        throw std::runtime_error("Invalid near clip");
    }
    this->nearClip = nearClip;
}
void camera::setFarClip(float farClip) {
    if (farClip <= 0) {
        throw std::runtime_error("Invalid far clip");
    }
    this->farClip = farClip;
}

glm::vec3 camera::getCameraDirection() const {
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    return glm::normalize(direction);
}
glm::vec3 camera::getPosition() const {
    return position;
}
glm::mat4 camera::getViewMatrix() const{
    return glm::lookAt(position, position + getCameraDirection(), glm::vec3(0.0f, 1.0f, 0.0f));

}
glm::mat4 camera::getProjectionMatrix() const {
    return glm::perspective(glm::radians(fov), aspect, nearClip, farClip);
}

void camera::update(GLFWwindow *window, float deltaTime) {
    processInput(window, deltaTime);
    // do nothing

}
void camera::move(const glm::vec3 &offset) {
    position += offset;
}
void camera::rotate(float yawOffset, float pitchOffset) {
    yaw += yawOffset;
    pitch += pitchOffset;
    pitch = std::max(-89.0f, std::min(89.0f, pitch));
}

glm::vec3 camera::getUp() const {
    return {0.0f, 1.0f, 0.0f};
}
void camera::processInput(GLFWwindow *window, float deltaTime) {
    // set the speed of the camera movement
    float speed = 2.5f * deltaTime;

    // check if the user has pressed the W key and move the camera forwards with a positive speed
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        move(speed * getCameraDirection());
    }
    // check if the user has pressed the S key and move the camera backwards with a negative speed
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        move(-speed * getCameraDirection());
    }
    // check if the user has pressed the A key and move the camera to the left with a negative speed
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        move(-glm::normalize(glm::cross(getCameraDirection(), getUp())) * speed);
    }
    // check if the user has pressed the D key and move the camera to the right with a positive speed
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        move(glm::normalize(glm::cross(getCameraDirection(), getUp())) * speed);
    }

    // check if the user has pressed the left arrow key and rotate the camera to the left with a negative speed
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        rotate(-speed, 0.0f);
    }
    // check if the user has pressed the right arrow key and rotate the camera to the right with a positive speed
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        rotate(speed, 0.0f);
    }

    // check if the user has pressed the up arrow key and rotate the camera up with a negative speed
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        rotate(0.0f, -speed);
    }
    // check if the user has pressed the down arrow key and rotate the camera down with a positive speed
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        rotate(0.0f, speed);
    }
}