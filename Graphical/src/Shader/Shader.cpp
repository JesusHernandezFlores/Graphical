#pragma once

#include <fstream>
#include <sstream>
#include <tuple>
#include <iostream>
#include "Shader.h"
#include <GL/glew.h>

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

	void Shader::PassShader(const std::string& sourcePath)
	{
		std::string parcedShader = ParseShader(sourcePath);
		const char* shaderSource = parcedShader.c_str();
		
		if (sourcePath.find(".vertex") != std::string::npos)
		{
			glShaderSource(vertexShader, 1, &shaderSource, NULL);
			glCompileShader(vertexShader);
			ShaderSuccess(vertexShader);
		}
		else if (sourcePath.find(".fragment") != std::string::npos)
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

	void Shader::SetFloat(char* varName, float a)
	{
		glUniform1f(glGetUniformLocation(shaderID, varName), a);
	}

	void Shader::SetFloat(char* varName, float a, float b)
	{
		glUniform2f(glGetUniformLocation(shaderID, varName), a, b);
	}

	void Shader::SetFloat(char* varName, float a, float b, float c)
	{
		glUniform3f(glGetUniformLocation(shaderID, varName), a, b, c);
	}

	void Shader::SetFloat(char* varName, float a, float b, float c, float d)
	{
		glUniform4f(glGetUniformLocation(shaderID, varName), a, b, c, d);
	}

	void Shader::SetInt(char* varName, int a)
	{
		glUniform1i(glGetUniformLocation(shaderID, varName), a);
	}
	
	void Shader::SetInt(char* varName, int a, int b)
	{
		glUniform2i(glGetUniformLocation(shaderID, varName), a, b);
	}

	void Shader::SetInt(char* varName, int a, int b, int c)
	{
		glUniform3i(glGetUniformLocation(shaderID, varName), a, b, c);
	}

	void Shader::SetInt(char* varName, int a, int b, int c, int d)
	{
		glUniform4i(glGetUniformLocation(shaderID, varName), a, b, c, d);
	}

	void Shader::SetUInt(char* varName, unsigned int a)
	{
		glUniform1ui(glGetUniformLocation(shaderID, varName), a);
	}

	void Shader::SetUInt(char* varName, unsigned int a, unsigned int b)
	{
		glUniform2ui(glGetUniformLocation(shaderID, varName), a, b);
	}

	void Shader::SetUInt(char* varName, unsigned int a, unsigned int b, unsigned int c)
	{
		glUniform3ui(glGetUniformLocation(shaderID, varName), a, b, c);
	}

	void Shader::SetUInt(char* varName, unsigned int a, unsigned int b, unsigned int c, unsigned int d)
	{
		glUniform4ui(glGetUniformLocation(shaderID, varName), a, b, c, d);
	}

	void Shader::SetMatrix(char* varName, unsigned int count, bool transpose, const float* value)
	{
		glUniformMatrix4fv(glGetUniformLocation(shaderID, varName), count, transpose, value);
	}
}