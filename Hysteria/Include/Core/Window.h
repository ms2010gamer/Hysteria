#pragma once

#include "Vendor/GLAD/glad.h"
#include "Vendor/GLFW/glfw3.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Window
{
    GLFWwindow* window;
    const char* title;
    int width, height;
    bool shouldclose;
} Window;

Window CreateWindow(int width, int height, const char* title);
bool WindowShouldClose(Window window);

bool InitGL();

void SwapWindowBuffers(Window window);
void PollEvents();
void ClearWindow();