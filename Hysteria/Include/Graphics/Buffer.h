#pragma once

#include "Vendor/GLAD/glad.h"

typedef struct VertexBuffer
{
    unsigned int buffer;
    const void* data;
    size_t size;
} VertexBuffer;
VertexBuffer CreateVertexBuffer(const void* data, size_t size);
void BindVertexBuffer(VertexBuffer buffer);
void UnBindVertexBuffer();

typedef struct ElementBuffer
{
    unsigned int buffer;
    const void* data;
    size_t size;
} ElementBuffer;
ElementBuffer CreateElementBuffer(const void* data, size_t size);
void BindElementBuffer(ElementBuffer buffer);
void UnBindElementBuffer();