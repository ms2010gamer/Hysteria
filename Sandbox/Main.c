#include "Core/Window.h"

#include "Graphics/Shader.h"
#include "Graphics/Buffer.h"
#include "Graphics/VertexArray.h"

int main()
{
    Window window = CreateWindow(800, 600, "Sandbox");
    InitGL();

    const char* vsS = "#version 330 core\n"
    "layout (location = 0) in vec3 Pos;\n"
    "void main(){\n"
        "gl_Position = vec4(Pos, 1.0f);\n"
    "}\n";
    const char* fsS = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main(){\n"
        "FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
    "}\n";

    Shader shader = CreateShader(vsS, fsS);
    UseShader(shader);

    float vertices[] = {
		// positions
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
	};
	unsigned int indices[] = {  // note that we start from 0!
	    0, 1, 3,   // first triangle
	    1, 2, 3    // second triangle
	};

    VertexArray vao = CreateVertexArray();
    VertexBuffer vbo = CreateVertexBuffer(vertices, sizeof(vertices));
    ElementBuffer ebo = CreateElementBuffer(indices, sizeof(indices));

    VertexArrayData(0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);

    while (!glfwWindowShouldClose(window.window))
    {
        ClearWindow();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        SwapWindowBuffers(window);
        PollEvents();
    }

    return 0;
}