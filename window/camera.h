//
// Created by NigelWork on 15/04/2024.
//

#ifndef OPENGLCOURSEWORK_CAMERA_H
#define OPENGLCOURSEWORK_CAMERA_H


#include <iostream> // this is needed for provides basic input/output services
#include <cmath> // this is needed for the sin and cos functions
#include <algorithm> // this is needed for the min and max functions
#include <stdexcept> // this is needed for the runtime_error
#include <glm/glm.hpp> // this is needed for the glm::vec3
#include <glm/gtc/matrix_transform.hpp> // this is needed for the glm::lookAt and glm::perspective functions
#include <glfw/glfw3.h> // this is needed for the GLFWwindow which will be used for the user input


class camera {
public:
    camera();

    // setters
    void setCameraPosition(const glm::vec3 &position);
    void setRotation(float yaw, float pitch);
    void setFOV(float fov);
    void setAspect(float aspect);
    void setNearClip(float nearClip);
    void setFarClip(float farClip);

    // getters
    glm::vec3 getCameraDirection() const;
    glm::vec3 getPosition() const;
    glm::vec3 getUp() const;
    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix() const;

    // Process user input
    void processInput(GLFWwindow *window, float deltaTime);
    // update
    void update(GLFWwindow *window, float deltaTime);

    // Other functions
    void move(const glm::vec3& offset);
    void rotate(float yawOffset, float pitchOffset);

private:
    glm::vec3 position;
    float yaw;
    float pitch;
    float fov;
    float aspect;
    float nearClip;
    float farClip;

};

#endif //OPENGLCOURSEWORK_CAMERA_H
