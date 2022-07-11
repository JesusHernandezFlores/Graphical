#pragma once
#include <gl/glew.h>
#include <iostream>

namespace Graphical
{
	namespace BufferUtils
	{
		enum class BufferTypes
		{
			ARRAY = GL_ARRAY_BUFFER, ELEMENT_ARRAY = GL_ELEMENT_ARRAY_BUFFER
		};

		template<typename T, size_t N>
		void LoadVertexData(const T(&data)[N])
		{
			std::cout << "Received array of size " << N << std::endl;
			glBufferData(GL_ARRAY_BUFFER, N * sizeof(data[0]), data, GL_STATIC_DRAW);
		}
		
		template<typename T, size_t N>
		void LoadElementData(const T(&data)[N])
		{
			std::cout << "Received array of size " << N << std::endl;
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, N * sizeof(data[0]), data, GL_STATIC_DRAW);
		}
	}
}