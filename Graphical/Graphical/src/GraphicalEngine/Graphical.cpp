#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Graphical.h"
static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
Graphical* Graphical::instance = nullptr;

Graphical::Graphical()
{
	InitGLFW();
	CreateWindow();
	InitGLAD();
}

Graphical* Graphical::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Graphical();
	}
	return instance;
}

void Graphical::InitGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void Graphical::InitGLAD()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}

void Graphical::CreateWindow()
{
	window = glfwCreateWindow(800, 600, "Graphical", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

GLFWwindow* Graphical::GetWindow()
{
	return window;
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}