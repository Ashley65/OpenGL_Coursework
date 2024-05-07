//
// Created by NigelWork on 15/04/2024.
//

#ifndef OPENGLCOURSEWORK_CAMERA_H
#define OPENGLCOURSEWORK_CAMERA_H
#define GLM_ENABLE_EXPERIMENTAL



#include <iostream> // this is needed for provides basic input/output services
#include <cmath> // this is needed for the sin and cos functions
#include <algorithm> // this is needed for the min and max functions
#include <stdexcept> // this is needed for the runtime_error

// openGL libraries
#include <glm/glm.hpp> // this is needed for the glm::vec3
#include <glm/gtx/quaternion.hpp> // this is needed for the glm::quat
#include <glm/gtc/matrix_transform.hpp> // this is needed for the glm::lookAt and glm::perspective functions
#include <glfw/glfw3.h> // this is needed for the GLFWwindow which will be used for the user input

// elements libraries
#include "elements.h" // this is needed for the elements class
#include "input.h"


namespace element {
    class camera: public elements::Elements{

    public:

        camera(const glm::vec3 &position, float yaw, float pitch, float fov, float aspect, float nearClip, float farClip) {
            mPosition = position;
            mYaw = yaw;
            mPitch = pitch;
            mFOV = fov;
            mAspect = aspect;
            mNear = nearClip;
            mFar = farClip;
            updateViewMatrix();
        }
        void update(shaderUtils::shader* shader) override {
            glm::mat4 model = glm::mat4(1.0f);

        }

        void setAspect(float aspect) {
            mProjection = glm::perspective(mFOV, aspect, mNear, mFar);

        }

        void setDistance(float offset) {
            mDistance += offset;
        }
        const glm::mat4& getProjection() const {
            return mProjection;
        }

        glm::mat4 getViewProjection() const {
            return mProjection * getViewMatrix();
        }

        glm::vec3 getUp() const {
            return glm::normalize(glm::cross(cRight, cForward));
        }
        glm::vec3 getRight() const {
            return glm::normalize(glm::cross(cForward, getUp()));
        }
        glm::vec3 getForward() const {
            return glm::normalize(glm::cross(getUp(), cRight));
        }

        glm::quat getOrientation() const {
            return glm::quat(glm::vec3(mPitch, mYaw, 0.0f));
        }

        glm::mat4 getViewMatrix() const {
            return mViewMatrix;
        }

        void onMouseWheel(double delta) {
            setDistance(delta * 0.5f);
            updateViewMatrix();
        }

        void onMouseMove(double x, double y, elemInput button) {
            glm::vec2 currentPos2d = { x, y };


            if (button == elemInput::Right) {
                glm::vec2 pos2d{ x, y };
                glm::vec2 delta = pos2d - mCurrentPos2d;

                float sign = glm::dot(delta, glm::vec2(0.0f, 1.0f));
                float angle = glm::length(delta) * cRotationSpeed;

                if (sign < 0.0f) {
                    angle = -angle;
                }

                mYaw += glm::radians(angle);
                updateViewMatrix();

            }
            else if (button == elemInput::Middle) {
                glm::vec2 pos2d{ x, y };
                glm::vec2 delta = pos2d - mCurrentPos2d;

                float sign = glm::dot(delta, glm::vec2(0.0f, 1.0f));
                float angle = glm::length(delta) * cRotationSpeed;

                if (sign < 0.0f) {
                    angle = -angle;
                }

                mPitch += glm::radians(angle);
                updateViewMatrix();
            }

            mCurrentPos2d = currentPos2d;
        }
        void reset() {
            mPitch = 0.0f;
            mYaw = 0.0f;
            mDistance = 5.0f;
            mFocus = { 0.0f, 0.0f, 0.0f };
            updateViewMatrix();
        }

        void updateViewMatrix() {
            mPosition =  mFocus - getForward() * mDistance;

            glm::quat orientation = getOrientation();
            mViewMatrix = glm::translate(glm::mat4(1.0f), mPosition) * glm::toMat4(orientation);
            mViewMatrix = glm::inverse(mViewMatrix);
        }


    private:
        glm::mat4 mProjection = glm::mat4{ 1.0f };
        glm::vec3 mPosition = { 0.0f, 0.0f, 0.0f };
        glm::mat4 mViewMatrix{};

        glm::vec3 mFocus = { 0.0f, 0.0f, 0.0f };

        float mDistance = 5.0f;
        float mAspect{};
        float mFOV{};
        float mNear{};
        float mFar{};
        float mPitch = 0.0f;
        float mYaw = 0.0f;

        glm::vec2 mCurrentPos2d = { 0.0f, 0.0f };

        const glm::vec3 cRight = { 1.0f, 0.0f, 0.0f };
        const glm::vec3 cUp = { 0.0f, 1.0f, 0.0f };
        const glm::vec3 cForward = { 0.0f, 0.0f, -1.0f };

        const float cRotationSpeed = 2.0f;


    };
}
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
