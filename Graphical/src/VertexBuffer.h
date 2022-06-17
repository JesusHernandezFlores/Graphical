#pragma once
#include <vector>

namespace Graphical
{
	class VertexBuffer
	{
	public:
		VertexBuffer();
		void Bind();
		void Unbind();

		void LoadData(void* data);
	private:
		unsigned int VBO;
	};
}