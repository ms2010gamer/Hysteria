#include "Graphics/Buffer.h"

// Vertex buffer

VertexBuffer CreateVertexBuffer(const void* data, size_t size)
{
    VertexBuffer buffer;

    buffer.data = data;
    buffer.size = size;

    glGenBuffers(1, &buffer.buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer.buffer);
    glBufferData(GL_ARRAY_BUFFER, buffer.size, buffer.data, GL_STATIC_DRAW);

    return buffer;
}
void BindVertexBuffer(VertexBuffer buffer)
{
    glBindBuffer(GL_ARRAY_BUFFER, buffer.buffer);
}
void UnBindVertexBuffer()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void RemoveVertexBuffer(VertexBuffer buffer)
{
    glDeleteBuffers(1, &buffer.buffer);
}

// Index buffer

ElementBuffer CreateElementBuffer(const void* data, size_t size)
{
    ElementBuffer buffer;

    buffer.data = data;
    buffer.size = size;

    glGenBuffers(1, &buffer.buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, buffer.size, buffer.data, GL_STATIC_DRAW);

    return buffer;
}
void BindElementBuffer(ElementBuffer buffer)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.buffer);
}
void UnBindElementBuffer()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void RemoveElementBuffer(ElementBuffer buffer)
{
    glDeleteBuffers(1, &buffer.buffer);
}