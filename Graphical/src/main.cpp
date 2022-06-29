#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "ShaderHelper.h"
#include "Utilities.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "BufferUtils.h"
#include "Shader.h"

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
	
	///////////////////////////////////////////////////////////////////////////////////////////////////

    Shader s;
    s.PassShader(GL_VERTEX_SHADER, "Triangle.vertex.txt");
    s.PassShader(GL_FRAGMENT_SHADER, "Yellow.fragment.txt");
    s.CreateShaderProgram();

    Shader b;
    b.PassShader(GL_VERTEX_SHADER, "Triangle.vertex.txt");
    b.PassShader(GL_FRAGMENT_SHADER, "Blue.fragment.txt");
    b.CreateShaderProgram();

    Shader red;
    red.PassShader(GL_VERTEX_SHADER, "Red.vertex.txt");
    red.PassShader(GL_FRAGMENT_SHADER, "Red.fragment.txt");
    red.CreateShaderProgram();


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
    
    float triangle1[] = {
		// first triangle
		-0.9f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // left 
		-0.0f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// right
		-0.45f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // top 
	};

    unsigned int triangle1Inices[] = {
        0, 1, 2,
        2, 3, 4
    };
    
    float triangle2[] = {
		// second triangle
		 0.0f, -0.5f, 0.0f,  // left
		 0.9f, -0.5f, 0.0f,  // right
		 0.45f, 0.5f, 0.0f   // top 
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    unsigned int VAOs[2];
    //ElementBuffer ebo;
    VertexBuffer vbo[2];
    glGenVertexArrays(2, VAOs);
    
    glBindVertexArray(VAOs[0]);

    vbo[0].Bind();
    BufferUtils::LoadVertexData(triangle1);

	/*ebo.Bind();
	BufferUtils::LoadElementData(triangle1Inices)*/;
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    

    vbo[0].Unbind();
    //ebo.Unbind();

    glBindVertexArray(0);

    glBindVertexArray(VAOs[1]);
    vbo[1].Bind();
    BufferUtils::LoadVertexData(triangle2);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

    vbo[1].Unbind();
    glBindVertexArray(0);


    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    float timeValue;
    float greenValue;
    int vertexColorLocation;
    float offset = .01f;
    int vertexOffsetLocation;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        Graphical::GraphicalUtilities::processInput(window);

        /* Render here */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        timeValue = glfwGetTime();
        greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        //vertexColorLocation = glGetUniformLocation(redTriangle, "vertexColor");
        vertexOffsetLocation = glGetUniformLocation(red.GetShader(), "offset");
        red.UseShader();
        //glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        glUniform1f(vertexOffsetLocation, offset);
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        b.UseShader();
		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        offset += .001f;
    }
    glfwTerminate();
    return 0;
}