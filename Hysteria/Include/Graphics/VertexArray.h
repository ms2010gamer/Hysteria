#pragma once

#include "Vendor/GLAD/glad.h"

typedef struct VertexArray
{
    unsigned int id;
} VertexArray;
VertexArray CreateVertexArray();

void BindVertexArray(VertexArray vao);
void UnBindVertexArray();
void RemoveVertexArray(VertexArray vao);

void VertexArrayData(int index, int size, GLenum type, size_t stride, const void* pointer);