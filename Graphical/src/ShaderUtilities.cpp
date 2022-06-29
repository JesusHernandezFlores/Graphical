#include "ShaderUtilities.h"
#include <iostream>
#include <sstream>
#include <fstream>

namespace Utilities
{
	namespace ShaderUtilities
	{
		unsigned int CompileShader(unsigned int shaderType, const std::string& path)
		{
			std::string parcedShader = ParseShader(path);
			const char* shaderSource = parcedShader.c_str();
			//const char* sourceToChar = source.c_str();
			std::cout << shaderSource << std::endl;
			unsigned int s = glCreateShader(shaderType);
			glShaderSource(s, 1, &shaderSource, NULL);
			glCompileShader(s);

			ShaderSuccess(s);

			return s;
		}

		unsigned int CreateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader)
		{
			unsigned int s;
			s = glCreateProgram();
			glAttachShader(s, vertexShader);
			glAttachShader(s, fragmentShader);
			glLinkProgram(s);

			int success;
			char infoLog[512];
			glGetProgramiv(s, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(s, 512, NULL, infoLog);
				std::cout << "ERROR: Shader Program Failed to link with error message: \n" << infoLog << std::endl;
			}

			return s;
		}

		void DeleteShaders(unsigned int& s)
		{
			glDeleteShader(s);
		}

		void ShaderSuccess(unsigned int shader)
		{
			int success;
			char infoLog[512];
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				std::cout << "Shader Compile Error: " << infoLog << std::endl;
			}
		}
		static std::string ParseShader(const std::string& shaderSourcePath)
		{
			std::ifstream shaderSourceFile(shaderSourcePath);
			std::stringstream shaderSource;

			std::string line;


			while (std::getline(shaderSourceFile, line))
			{
				shaderSource << line << '\n';
			}

			//shaderSourceFile.close();
			return shaderSource.str();
		}

	}
}
