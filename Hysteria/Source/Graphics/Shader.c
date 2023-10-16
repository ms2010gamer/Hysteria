#include "Graphics/Shader.h"

Shader CreateShader(const char* vsS, const char* fsS)
{
    Shader shader;
	shader.vsS = vsS;
	shader.fsS = fsS;
	
	shader.vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader.vs, 1, &shader.vsS, 0);
	glCompileShader(shader.vs);

	shader.fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader.fs, 1, &shader.fsS, 0);
	glCompileShader(shader.fs);

	shader.id = glCreateProgram();
	glAttachShader(shader.id, shader.vs);
	glAttachShader(shader.id, shader.fs);
	glLinkProgram(shader.id);
	glValidateProgram(shader.id);

    return shader;
}

void UseShader(Shader shader)
{
	glUseProgram(shader.id);
}

void RemoveShader(Shader shader)
{
	glDeleteProgram(shader.id);
}