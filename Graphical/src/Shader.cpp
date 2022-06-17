#pragma once

#include <fstream>
#include <sstream>
#include <tuple>
#include <iostream>
#include "Shader.h"
#include <GL/glew.h>


std::tuple<const std::string, const std::string> Shader::ParseShader(const std::string& shaderSourcePath)
{
	enum class ShaderType
	{
		Error = -1, Vertex, Fragment
	};

	std::ifstream shaderSourceFile(shaderSourcePath);
	std::stringstream shaderSource[2];

	std::string line;

	ShaderType st = ShaderType::Error;
	while (std::getline(shaderSourceFile, line))
	{
		if (line.find("#type") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				st = ShaderType::Vertex;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				st = ShaderType::Fragment;
			}
		}
		else
		{
			shaderSource[(int)st] << line << '\n';
		}
	}

	//shaderSourceFile.close();
	return std::tuple<std::string, std::string>{shaderSource[0].str(), shaderSource[1].str()};
}

unsigned int Shader::CompileShader(unsigned int shaderType, const std::string& source)
{
	const char* sourceToChar = source.c_str();
	std::cout << sourceToChar << std::endl;
	unsigned int s = glCreateShader(shaderType);
	glShaderSource(s, 1, &sourceToChar, NULL);
	glCompileShader(s);

	ShaderSuccess(s);

	return s;
}

unsigned int Shader::CreateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader)
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

void Shader::DeleteShaders(unsigned int& s1, unsigned int& s2)
{
	glDeleteShader(s1);
	glDeleteShader(s2);
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