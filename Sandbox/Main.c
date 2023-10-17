#include "Core/Window.h"

#include "Graphics/Shader.h"
#include "Graphics/Buffer.h"
#include "Graphics/VertexArray.h"
#include "Graphics/Texture.h"

int main()
{
    Window window = CreateWindow(800, 600, "Sandbox");
    InitGL();

    const char* vsS = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "out vec2 TexCoord;\n"
    "void main(){\n"
        "gl_Position = vec4(aPos, 1.0f);\n"
        "TexCoord = aTexCoord;\n"
    "}\n";
    const char* fsS = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec2 TexCoord;\n"
    "uniform sampler2D texture1;\n"
    "void main(){\n"
        "FragColor = texture(texture1, TexCoord);\n"
    "}\n";

    Shader shader = CreateShader(vsS, fsS);
    UseShader(shader);

    float vertices[] = {
        // positions          // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f    // top left 
    };
	unsigned int indices[] = {  // note that we start from 0!
	    0, 1, 3,   // first triangle
	    1, 2, 3    // second triangle
	};

    Texture texture = CreateTexture("Textures/boy.png");

    VertexArray vao = CreateVertexArray();
    BindVertexArray(vao);
    VertexBuffer vbo = CreateVertexBuffer(vertices, sizeof(vertices));
    ElementBuffer ebo = CreateElementBuffer(indices, sizeof(indices));

    VertexArrayData(0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
    VertexArrayData(1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));

    while (!glfwWindowShouldClose(window.window))
    {
        ClearWindow();
        glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

        UseShader(shader);
/*
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture.id);
        glUniform1i(glGetUniformLocation(shader.id, "texture1"), 0);
*/
        BindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        SwapWindowBuffers(window);
        PollEvents();
    }

    return 0;
}