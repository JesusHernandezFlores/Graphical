#include "VertexArray.h"
#include <GL/glew.h>

namespace Graphical 
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &VAO);
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(VAO);
	}

	void VertexArray::Unbind()
	{
		glBindVertexArray(0);
	}
}