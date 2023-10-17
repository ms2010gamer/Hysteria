#pragma once

#include "Vendor/GLAD/glad.h"

typedef struct Texture
{
    unsigned int id;
    const void* data;
} Texture;
Texture CreateTexture(const char* path);

void BindTexture(Texture texture, int slot);
void UnBindTexture();
void RemoveTexture(Texture texture);