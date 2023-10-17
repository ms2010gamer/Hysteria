#include "Graphics/VertexArray.h"

VertexArray CreateVertexArray()
{
    VertexArray vao;

    glGenVertexArrays(1, &vao.id);
}

void BindVertexArray(VertexArray vao)
{
    glBindVertexArray(vao.id);
}

void UnBindVertexArray()
{
    glBindVertexArray(0);
}

void RemoveVertexArray(VertexArray vao)
{
    glDeleteVertexArrays(1, &vao.id);
}

void VertexArrayData(int index, int size, GLenum type, size_t stride, const void* pointer)
{
    glVertexAttribPointer(index, size, type, GL_FALSE, stride, pointer);
    glEnableVertexAttribArray(index);
}