#include "VertexBuffer.h"
#include <iostream>
#include <GL/glew.h>

namespace Graphical
{
	VertexBuffer::VertexBuffer()
	{
		std::cout << "Generating Vertex Buffers" << std::endl;
		glGenBuffers(1, &VBO);
	}

	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
	}

	void VertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


}

