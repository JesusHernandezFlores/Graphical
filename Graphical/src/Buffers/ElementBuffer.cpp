#include "ElementBuffer.h"
#include <iostream>
#include <GL/glew.h>

namespace Graphical
{
	ElementBuffer::ElementBuffer()
	{
		std::cout << "Generating Element Buffer" << std::endl;
		glGenBuffers(1, &EBO);
	}

	void ElementBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	}

	void ElementBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}