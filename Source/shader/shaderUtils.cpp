//
// Created by NigelWork on 22/04/2024.
//

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include "shaderUtils.h"

unsigned int shaderUtils::shader::getCompiledShader(unsigned int shaderType, const std::string &shaderSource) {

    unsigned int shaderID = glCreateShader(shaderType);
    const char *shaderSourceC = shaderSource.c_str();
    glShaderSource(shaderID, 1, &shaderSourceC, nullptr);
    glCompileShader(shaderID);

    GLint result;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE){
        int length;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
        auto* strInfoLog = new GLchar[length + 1];
        glGetShaderInfoLog(shaderID, length, nullptr, strInfoLog);
        const char *strShaderType = nullptr;
        switch(shaderType){
            case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
            case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
        }
        fprintf(stderr, "Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog);
    }
    return shaderID;

}

bool shaderUtils::shader::loadShader(const std::string &vertexShaderFile, const std::string &fragmentShaderFile) {

//    Load the vertex shader
    std::ifstream vertexFile(vertexShaderFile);
    const std::string vertexSource((std::istreambuf_iterator<char>(vertexFile)), std::istreambuf_iterator<char>());

    // Load the fragment shader
    std::ifstream fragmentFile(fragmentShaderFile);
    const std::string fragmentSource((std::istreambuf_iterator<char>(fragmentFile)), std::istreambuf_iterator<char>());

    shaderProgramID = glCreateProgram();

    unsigned int vertexShader = getCompiledShader(GL_VERTEX_SHADER, vertexSource);
    unsigned int fragmentShader = getCompiledShader(GL_FRAGMENT_SHADER, fragmentSource);


    glAttachShader(shaderProgramID, vertexShader);
    glAttachShader(shaderProgramID, fragmentShader);

    glLinkProgram(shaderProgramID);
    glValidateProgram(shaderProgramID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);



    return true;
}

void shaderUtils::shader::useShader() const {
    glUseProgram(shaderProgramID);
}

void shaderUtils::shader::unloadShader() const {
    glDeleteProgram(shaderProgramID);
}

void shaderUtils::shader::setMat4(const std::string &name, const glm::mat4 &mat) const {
    GLint myLoc = glGetUniformLocation(shaderProgramID, name.c_str());
    glUniformMatrix4fv(myLoc, 1, GL_FALSE, glm::value_ptr(mat));
}

void shaderUtils::shader::setVec3(const std::string &name, const glm::vec3 &value) const {
    GLint myLoc = glGetUniformLocation(shaderProgramID, name.c_str());
    glUniform3fv(myLoc, 1, glm::value_ptr(value));
}

void shaderUtils::shader::setVec4(const std::string &name, const glm::vec4 &value) const {
    GLint myLoc = glGetUniformLocation(shaderProgramID, name.c_str());
    glUniform4fv(myLoc, 1, glm::value_ptr(value));
}

void shaderUtils::shader::setI1(int v, const std::string &name) const {
    GLint myLoc = glGetUniformLocation(shaderProgramID, name.c_str());
    glUniform1i(myLoc, v);
}

void shaderUtils::shader::setF1(float v, const std::string &name) const {
    GLint myLoc = glGetUniformLocation(shaderProgramID, name.c_str());
    glUniform1f(myLoc, v);
}

void shaderUtils::shader::setF3(float v1, float v2, float v3, const std::string &name) const {
    GLint myLoc = glGetUniformLocation(shaderProgramID, name.c_str());
    glUniform3f(myLoc, v1, v2, v3);
}








