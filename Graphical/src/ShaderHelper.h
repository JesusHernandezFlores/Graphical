#pragma once
#include <string>
namespace Graphical
{
	class ShaderHelper
	{
	public:
		ShaderHelper(const ShaderHelper&) = delete;
		ShaderHelper operator=(ShaderHelper& other) = delete;

		static ShaderHelper& GetInstance()
		{
			static ShaderHelper s_Instance;
			return s_Instance;
		}

		unsigned int CompileShader(unsigned int shaderType, const std::string& shaderSource);
		unsigned int CreateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
		void DeleteShaders(unsigned int& s);

	private:
		void ShaderSuccess(unsigned int shader);
		static std::string ParseShader(const std::string& shaderSourcePath);

	private:
		ShaderHelper() {}
	};
}