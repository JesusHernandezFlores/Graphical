#pragma once

#include <fstream>
#include <sstream>
#include <tuple>
#include <iostream>
#include "Shader.h"
#include <GL/glew.h>
#include "ShaderUtilities.h"

namespace ShaderUtils = Utilities::ShaderUtilities;

namespace Graphical
{
	Shader::Shader()
	{
		shaderID = glCreateProgram();
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	}

	Shader::~Shader()
	{
		glDeleteProgram(shaderID);
	}

	void Shader::UseShader()
	{
		glUseProgram(shaderID);
	}

	unsigned int Shader::GetShader()
	{
		return shaderID;
	}

	void Shader::PassShader(unsigned int type, const std::string& sourcePath)
	{
		std::string parcedShader = ParseShader(sourcePath);
		const char* shaderSource = parcedShader.c_str();
		
		if (type == GL_VERTEX_SHADER)
		{
			glShaderSource(vertexShader, 1, &shaderSource, NULL);
			glCompileShader(vertexShader);
			ShaderSuccess(vertexShader);
		}
		else if (type == GL_FRAGMENT_SHADER)
		{
			glShaderSource(fragmentShader, 1, &shaderSource, NULL);
			glCompileShader(fragmentShader);
			ShaderSuccess(fragmentShader);
		}
		
	}

	void Shader::CreateShaderProgram()
	{
		glAttachShader(shaderID, vertexShader);
		glAttachShader(shaderID, fragmentShader);
		glLinkProgram(shaderID);

		int success;
		char infoLog[512];
		glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderID, 512, NULL, infoLog);
			std::cout << "ERROR: Shader Program Failed to link with error message: \n" << infoLog << std::endl;
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	std::string Shader::ParseShader(const std::string& path)
	{
		std::ifstream shaderSourceFile(path);
		std::stringstream shaderSource;

		std::string line;


		while (std::getline(shaderSourceFile, line))
		{
			shaderSource << line << '\n';
		}

		return shaderSource.str();
	}

	void Shader::ShaderSuccess(unsigned int shader)
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
}