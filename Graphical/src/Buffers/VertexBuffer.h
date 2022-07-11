#pragma once
#include <vector>
#include <gl/glew.h>

namespace Graphical
{
	class VertexBuffer
	{
	public:
		VertexBuffer();
		void Bind();
		void Unbind();

	private:
		unsigned int VBO;
	};
}