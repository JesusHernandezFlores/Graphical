#include "ShaderProgramCompiler.h"

#include <fstream>
#include <iostream>

namespace Graphical
{
    const char* const ShaderProgramCompiler::ReadShaderSource(std::string& shaderFilePath)
    {
        std::ifstream shaderSource;
        std::string shaderProgram;

        shaderSource.open(shaderFilePath);
        if (shaderSource.is_open())
        {
            shaderProgram = std::string((std::istreambuf_iterator<char>(shaderSource)), std::istreambuf_iterator<char>());
        }
        else
        {
            std::cout << "Unable to open file, returning empty string." << std::endl;
        }
        return shaderProgram.c_str();
    }
}
