#pragma once
#include <string>

class Shader
{
public:
	Shader(const Shader&) = delete;
	Shader operator=(Shader& other) = delete;


	static Shader& GetInstance()
	{
		static Shader s_Instance;
		return s_Instance;
	}

	unsigned int CompileShader(unsigned int shaderType, const std::string& shaderSource);
	unsigned int CreateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
	void DeleteShaders(unsigned int& s);

private:
	void ShaderSuccess(unsigned int shader);
	std::string ParseShader(const std::string& shaderSourcePath);

private:
	Shader() {}
};