#pragma warning(disable: 4996)
#include <stdio.h>
#include "Texture.h"

Texture::Texture() {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    loadTexture("Assets/texture/Circle.data");
}

void Texture::loadTexture(const char texture1[]) {
    /* テクスチャの読み込みに使う配列 */
    FILE* fp;

    /* テクスチャ画像の読み込み */
    if ((fp = fopen(texture1, "rb")) != NULL) {
        fread(texture, sizeof texture, 1, fp);
        fclose(fp);
    }
    else {
        perror(texture1);
    }
}

void Texture::setTexture(int textureNumber) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEXWIDTH, TEXHEIGHT, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, texture);
    //gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEXWIDTH, TEXHEIGHT,
    //    GL_RGBA, GL_UNSIGNED_BYTE, texture);
}

GLubyte* Texture::loadPng(const char fp[]) {
	GLubyte* handle = nullptr;
	return handle;
}