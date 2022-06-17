#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace Graphical
{
	namespace GraphicalUtilities
	{
		 GLFWwindow * CreateGLFWwindow(int height, int width);

		 void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		 void processInput(GLFWwindow* window);

		 int GLFWSetup();

		 int GLEWSetup();
	}
}
