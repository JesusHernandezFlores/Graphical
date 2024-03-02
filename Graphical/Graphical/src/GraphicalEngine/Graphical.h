#include <glad/glad.h>
#include <GLFW/glfw3.h>
#pragma once
class Graphical
{
protected:
	Graphical();

	static Graphical* instance;

public:
	Graphical(Graphical& other) = delete;
	void operator=(const Graphical&) = delete;

	static Graphical* GetInstance();
	GLFWwindow* GetWindow();

private:
	void InitGLFW();
	void InitGLAD();
	void CreateWindow();

	GLFWwindow* window;
};