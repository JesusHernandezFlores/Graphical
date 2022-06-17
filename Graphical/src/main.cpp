#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Utilities.h"
#include "VertexBuffer.h"

using namespace Graphical;

int main(void)
{
    //~~~~~Initial Setup~~~~~
    //GLFWSetup();
    Graphical::GraphicalUtilities::GLFWSetup();

    //set up window
    GLFWwindow* window = Graphical::GraphicalUtilities::CreateGLFWwindow(800, 600);
    glfwMakeContextCurrent(window);
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, Graphical::GraphicalUtilities::framebuffer_size_callback);

    Graphical::GraphicalUtilities::GLEWSetup();

	auto [vertexSource, fragmentSource] = Shader::GetInstance().ParseShader("shaderSource.txt");

	unsigned int vertexShader = Shader::GetInstance().CompileShader(GL_VERTEX_SHADER, vertexSource);
	unsigned int fragmentShader = Shader::GetInstance().CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

	unsigned int shaderProgram = Shader::GetInstance().CreateShaderProgram(vertexShader, fragmentShader);

    Shader::GetInstance().DeleteShaders(vertexShader, fragmentShader);

    /*float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };*/
    
    float vertices[] = {
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    unsigned int VAO, EBO;
    VertexBuffer vb;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);

    vb.Bind();
    vb.LoadData(&vertices);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    vb.Unbind();
    glBindVertexArray(0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        Graphical::GraphicalUtilities::processInput(window);
        /* Render here */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}