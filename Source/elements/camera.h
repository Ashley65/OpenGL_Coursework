//
// Created by NigelWork on 15/04/2024.
//

#ifndef OPENGLCOURSEWORK_CAMERA_H
#define OPENGLCOURSEWORK_CAMERA_H
#define GLM_ENABLE_EXPERIMENTAL


#include <glm/gtx/quaternion.hpp>
#include "../../packageM.h"

// elements libraries
#include "elements.h" // this is needed for the elements class
#include "input.h"
#include "../shader/shaderUtils.h"


namespace element {
    class camera: public elements::Elements{

    public:

        camera(const glm::vec3 &position,  float fov, float aspect, float near, float far) {
            mPosition = position;
            mAspect = aspect;
            mNear = near;
            mFar = far;
            mFOV = fov;

            setAspect(mAspect);
            updateViewMatrix();
        }
        void update(shaderUtils::shader* shader) override {
            glm::mat4 model = glm::mat4(1.0f);
            shader->setMat4("model", model);
            shader->setMat4("view", getViewMatrix());
            shader->setMat4("projection", getProjection());
            shader->setVec3("camPos", mPosition);

        }

        void setAspect(float aspect) {
            mProjection = glm::perspective(mFOV, aspect, mNear, mFar);

        }

        void setDistance(float offset) {
            mDistance += offset;
            updateViewMatrix();
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
            glm::vec2 pos2d{ x, y };


            if (button == elemInput::Right) {
                glm::vec2 delta = (pos2d - mCurrentPos2d) * 0.004f;

                float sign = getUp().y < 0 ? -1.0f : 1.0f;
                mPitch += sign * delta.y * cRotationSpeed;
                mYaw += delta.x * cRotationSpeed;


                updateViewMatrix();

            }
            else if (button == elemInput::Middle) {
                glm::vec2 delta =(pos2d - mCurrentPos2d) * 0.003f;


                mFocus += getRight() * -delta.x * mDistance;
                mFocus += getUp() * delta.y * mDistance;
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

        // get camera position
        glm::vec3 getPosition() {
            return mPosition;
        }

        void moveForward(float speed) {
            mPosition += getForward() * speed;
            updateViewMatrix();
        }
        void moveRight(float speed) {
            mPosition += getRight() * speed;
            updateViewMatrix();
        }
        void moveUp(float speed) {
            mPosition += getUp() * speed;
            updateViewMatrix();
        }
        void moveBackward(float speed) {
            mPosition -= getForward() * speed;
            updateViewMatrix();
        }
        void moveLeft(float speed) {
            mPosition -= getRight() * speed;
            updateViewMatrix();
        }
        void moveDown(float speed) {
            mPosition -= getUp() * speed;
            updateViewMatrix();
        }


        void onKey(int key, int scancode, int action, int mods) {
            if (action == GLFW_PRESS) {
                if (key == GLFW_KEY_R) {
                    reset();
                }
                if (key == GLFW_KEY_W) {
                    mPosition += getForward() * 0.1f;
                    updateViewMatrix();
                }
                if (key == GLFW_KEY_S) {
                    mPosition -= getForward() * 0.1f;
                    updateViewMatrix();
                }
                if (key == GLFW_KEY_A) {
                    mPosition -= getRight() * 0.1f;
                    updateViewMatrix();
                }
                if (key == GLFW_KEY_D) {
                    mPosition += getRight() * 0.1f;
                    updateViewMatrix();
                }

            }
        }


    private:
        glm::mat4 mViewMatrix;
        glm::mat4 mProjection = glm::mat4{ 1.0f };
        glm::vec3 mPosition = { 1.0f, 1.0f, 1.0f };

        glm::vec3 mFocus = { 0.0f, 0.0f, 0.0f };

        float mDistance = 5.0f;
        float mAspect;
        float mFOV;
        float mNear;
        float mFar;

        float mPitch = 0.0f;
        float mYaw = 0.0f;

        glm::vec2 mCurrentPos2d = { 0.0f, 0.0f };

        const glm::vec3 cRight = { 1.0f, 0.0f, 0.0f };
        const glm::vec3 cUp = { 0.0f, 1.0f, 0.0f };
        const glm::vec3 cForward = { 0.0f, 0.0f, -1.0f };

        const float cRotationSpeed = 2.0f;


    };
}

#endif //OPENGLCOURSEWORK_CAMERA_H
