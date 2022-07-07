#pragma once

#include <gl/glew.h>




#include <string>
#include <iostream>
namespace Graphical
{
	enum class TexCoords
	{
		S = 0, T, R
	};

	enum class WrapType
	{
		Repeat = GL_REPEAT, MirrredRepeat = GL_MIRRORED_REPEAT, ClampToEdge = GL_CLAMP_TO_EDGE, ClampToBorder = GL_CLAMP_TO_BORDER
	};

	class Texture2D
	{
	public:
		

		Texture2D();
		void Bind();
		void SetWrapType(const TexCoords axis, const WrapType type) const;
		void SetTextureImage(std::string path);

		static void SetActiveTexture(unsigned int textureIndex);


	private:
		unsigned int texture;
	};

}