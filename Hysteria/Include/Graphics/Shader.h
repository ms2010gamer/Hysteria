#pragma once

#include "Vendor/GLAD/glad.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Shader
{
    const char* vsS;
    const char* fsS;
    unsigned int vs, fs;
    unsigned int id;
} Shader;

Shader CreateShader(const char* vsS, const char* fsS);

void UseShader(Shader shader);
void RemoveShader(Shader shader);