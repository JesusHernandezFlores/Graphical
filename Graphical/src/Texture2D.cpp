#include "Texture2D.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Graphical
{
	Texture2D::Texture2D()
	{
		glGenTextures(1, &texture);
	}

	void Texture2D::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	void Texture2D::SetWrapType(const TexCoords axis, const WrapType type) const
	{
		if (axis == TexCoords::R)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, (unsigned int)type);
		}
		else if (axis == TexCoords::S)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (unsigned int)type);
		}
		else if (axis == TexCoords::T)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (unsigned int)type);
		}
		else
		{
			std::cout << "Error on function Texture2D::SetWrapType, please set a valid axis" << std::endl;
		}
	}

	void Texture2D::SetTextureImage(std::string path)
	{
		stbi_set_flip_vertically_on_load(true);
		int width, height, nrChannels;
		unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			unsigned int format = nrChannels == 4 ? GL_RGBA : GL_RGB;
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);
	}

	void Texture2D::SetActiveTexture(unsigned int textureIndex)
	{
		glActiveTexture(GL_TEXTURE0 + textureIndex);
	}
}