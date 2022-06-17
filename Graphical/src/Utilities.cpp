#include "Utilities.h"
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

 void Graphical::GraphicalUtilities::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

 void Graphical::GraphicalUtilities::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

 int Graphical::GraphicalUtilities::GLFWSetup()
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return 0;
}



 int Graphical::GraphicalUtilities::GLEWSetup()
{
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }
    return 0;
}

 GLFWwindow* Graphical::GraphicalUtilities::CreateGLFWwindow(int height, int width)
{
    GLFWwindow* window = glfwCreateWindow(height, width, "Graphical", NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    return window;
}