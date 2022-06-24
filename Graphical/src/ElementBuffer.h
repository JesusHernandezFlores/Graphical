#pragma once
#include <gl/glew.h>

namespace Graphical
{
	class ElementBuffer
	{
	public:
		ElementBuffer();
		void Bind();
		void Unbind();

	private:
		unsigned int EBO;
	};
}