#pragma once
#include <string>

namespace Graphical
{
	class Shader
	{
	public:
		Shader();
		~Shader();

		void PassShader(const std::string& sourcePath);
		void CreateShaderProgram();
		void UseShader();

		unsigned int GetShader();
	
	private:
		unsigned int shaderID;
		unsigned int vertexShader;
		unsigned int fragmentShader;

	private:
		static std::string ParseShader(const std::string& path);
		static void ShaderSuccess(unsigned int shader);
	};
}