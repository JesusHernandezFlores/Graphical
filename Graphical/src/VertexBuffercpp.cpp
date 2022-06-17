#include "VertexBuffer.h"
#include <GL/glew.h>

namespace Graphical
{
	VertexBuffer::VertexBuffer()
	{
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

	void VertexBuffer::LoadData(void* data)
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	}
}

