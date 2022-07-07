#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>



#include "ShaderHelper.h"
#include "Utilities.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "VertexArray.h"
#include "BufferUtils.h"
#include "Shader.h"
#include "Texture2D.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

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

    Shader triangleTex;
    triangleTex.PassShader("TriangleTex.vertex.txt");
    triangleTex.PassShader("TriangleTex.fragment.txt");
    triangleTex.CreateShaderProgram();
    
    float vertices[] = {
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };
    
    float triangle1[] = {
		// first triangle
		-0.9f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f, // left 
		-0.0f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,// right
		-0.45f, 0.5f, 0.0f,    0.0f, 0.0f, 1.0f // top 
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


    float texCoords[] = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        0.5f, 1.0f
    };

    /*float texTriangle[] = {
         0.5f,  0.5f, 0.0f,    1.0f, 0.0f, 0.0f,    1.0f, 1.0f,
         0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,    1.0f, 1.0f, 0.0f,    0.0f, 1.0f
    };*/

    float texTriangle[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,    
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,    
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,    
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,    
    - 0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

	glm::vec3 cubePositions[] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
	};

    VertexArray vao;
    ElementBuffer ebo;
    VertexBuffer vbo[2];

    vao.Bind();
   
    vbo[0].Bind();
    ebo.Bind();
    BufferUtils::LoadVertexData(texTriangle);
    BufferUtils::LoadElementData(indices);
   
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    Texture2D brickTex;
    brickTex.Bind();

    brickTex.SetWrapType(TexCoords::S, WrapType::Repeat);
    brickTex.SetWrapType(TexCoords::T, WrapType::Repeat);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    brickTex.SetTextureImage("container.jpg");

    
    Texture2D circuitTex;
    circuitTex.Bind();

	circuitTex.SetWrapType(TexCoords::S, WrapType::Repeat);
	circuitTex.SetWrapType(TexCoords::T, WrapType::Repeat);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    circuitTex.SetTextureImage("awesomeface.png");

    triangleTex.UseShader();
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glUniform1i(glGetUniformLocation(triangleTex.GetShader(), "texture1"), 0);
    glUniform1i(glGetUniformLocation(triangleTex.GetShader(), "texture2"), 1);

    glEnable(GL_DEPTH_TEST);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        Graphical::GraphicalUtilities::processInput(window);

        /* Render here */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //brickTex.Bind();

        Texture2D::SetActiveTexture(0);
        brickTex.Bind();
        Texture2D::SetActiveTexture(1);
        circuitTex.Bind();

        unsigned int modelLoc = glGetUniformLocation(triangleTex.GetShader(), "model");
        unsigned int viewLoc = glGetUniformLocation(triangleTex.GetShader(), "view");
        unsigned int projLoc = glGetUniformLocation(triangleTex.GetShader(), "projection");

        triangleTex.UseShader();
        vao.Bind();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));

        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glDrawArrays(GL_TRIANGLES, 0, 36);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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