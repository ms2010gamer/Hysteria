#include "Graphics/Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "Vendor/stb_image/stb_image.h"

Texture CreateTexture(const char* path)
{
    Texture texture;

    // Texture paramaters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glGenTextures(1, &texture.id);
    glBindTexture(GL_TEXTURE_2D, texture.id);

    stbi_set_flip_vertically_on_load(1);
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture\n");
    }
    stbi_image_free(data);
}

void BindTexture(Texture texture, int slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture.id);
}

void UnBindTexture()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void RemoveTexture(Texture texture)
{
    glDeleteTextures(1, &texture.id);
}