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

		void SetFloat(char* varName, float a);
		void SetFloat(char* varName, float a, float b);
		void SetFloat(char* varName, float a, float b, float c);
		void SetFloat(char* varName, float a, float b, float c, float d);
		
		void SetInt(char* varName, int a);
		void SetInt(char* varName, int a, int b);
		void SetInt(char* varName, int a, int b, int c);
		void SetInt(char* varName, int a, int b, int c, int d);
		
		void SetUInt(char* varName, unsigned int a);
		void SetUInt(char* varName, unsigned int a, unsigned int b);
		void SetUInt(char* varName, unsigned int a, unsigned int b, unsigned int c);
		void SetUInt(char* varName, unsigned int a, unsigned int b, unsigned int c, unsigned int d);

		void SetMatrix(char* varName, unsigned int count, bool transpose, const float* value);
	};
}