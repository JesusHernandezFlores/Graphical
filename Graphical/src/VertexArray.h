#pragma once
namespace Graphical
{
	class VertexArray
	{
	public:
		VertexArray();
		void Bind();
		void Unbind();

	private:
		unsigned int VAO;
	};
}