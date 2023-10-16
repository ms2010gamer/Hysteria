#include "Core/Window.h"

Window CreateWindow(int width, int height, const char* title)
{
    if (!glfwInit())
    {
        printf("Failed to initialize GLFW!");
        glfwTerminate();
        exit(-1);
    }

    Window window;
    window.width = width;
    window.height = height;
    window.title = title;
    window.window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(window.window);

    return window;
}

bool WindowShouldClose(Window window)
{
    return window.shouldclose = glfwWindowShouldClose(window.window);
}

bool InitGL()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwTerminate();
        printf("Failed to initialize GLAD!");
        return -1;
    }
}

void SwapWindowBuffers(Window window)
{
    glfwSwapBuffers(window.window);
}

void PollEvents()
{
    glfwPollEvents();
}

void ClearWindow()
{
    glClear(GL_COLOR_BUFFER_BIT);
}