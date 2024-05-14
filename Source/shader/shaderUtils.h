//
// Created by NigelWork on 22/04/2024.
//

#ifndef OPENGLCOURSEWORK_SHADERUTILS_H
#define OPENGLCOURSEWORK_SHADERUTILS_H


#include <string>
#include <glm/glm.hpp>

namespace shaderUtils{

    // This a utility class for loading, compiling and linking vertex and fragment shaders to a program
    class shader{
    private:
        // This function reads the shader file and returns the shader source code
        unsigned int shaderProgramID;

        // This function will get the compiled shader from the shader source code
        static unsigned int getCompiledShader(unsigned int shaderType, const  std::string& shaderSource);

    public:
        shader() = default;

        // load the shader from the file
        bool loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);

        void setTexture(const std::string &name, unsigned int textureID, int textureUnit) const;

        // use the shader program
        void useShader() const;

        // unload the shader program
        void unloadShader() const;

        // get the shader program ID
        unsigned int getShaderProgramID() const { return shaderProgramID; }

        // setting the
        void setMat4(const std::string &name, const glm::mat4 &mat) const;

        void setVec3(const std::string &name, const glm::vec3 &value) const;

        void setVec4(const std::string &name, const glm::vec4 &value) const;

        void setI1(int v, const std::string &name) const;
        void setF1(float v, const std::string &name) const;
        void setF3(float v1, float v2, float v3, const std::string &name) const;



    };
}


#endif //OPENGLCOURSEWORK_SHADERUTILS_H
