#pragma once
#include <iostream>
#include <string>

namespace Graphical
{
	class ShaderProgramCompiler
	{
	public:

		static ShaderProgramCompiler& GetInstance()
		{
			static ShaderProgramCompiler instance;
			return instance;
		}

		ShaderProgramCompiler(const ShaderProgramCompiler&) = delete;

		
		//Takes in the path to a shader program and returns it as 
		//a const char*
		const char* const ReadShaderSource(std::string& shaderFilePath);
    private:
		ShaderProgramCompiler() { std::cout << "Initialized ShaderProgramCompiler" << std::endl; }
	};

	
}