#pragma once
#include "GL/glew.h"
#include <string>

namespace Utilities
{
	namespace ShaderUtilities
	{
		enum ShaderTypes {
			Vertex = GL_VERTEX_SHADER, Fragment = GL_FRAGMENT_SHADER
		};

		unsigned int CompileShader(unsigned int shaderType, const std::string& path);
		unsigned int CreateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
		void DeleteShaders(unsigned int& s);

		void ShaderSuccess(unsigned int shader);
		static std::string ParseShader(const std::string& shaderSourcePath);
	}
}