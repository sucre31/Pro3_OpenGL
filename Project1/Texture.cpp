#pragma warning(disable: 4996)
#include <stdio.h>
#include "Texture.h"

Texture::Texture() {
    textureResolution = 0;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    if (textureResolution == 0) {
        loadTexture("Assets/texture/Circle.data", SPEEDMETER);
        loadTexture("Assets/texture/ConcreteWall.data", CONCRETE);
        loadTexture("Assets/texture/ConcreteFloor.data", FLOOR);
        loadTexture("Assets/texture/Car.data", CAR);
        loadTexture("Assets/texture/alpha.data", ALPHA);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEXWIDTH * 8, TEXHEIGHT,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandle[CONCRETE]);
        glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTH * 6, 0, TEXWIDTH, TEXHEIGHT,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandle[CAR]);
        glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTH * 7, 0, TEXWIDTH, TEXHEIGHT,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandle[ALPHA]);
    }
    else if (textureResolution == 1) {
        loadTextureMiddle("Assets/texture/middle/Circle.data", SPEEDMETER);
        loadTextureMiddle("Assets/texture/middle/ConcreteWall.data", CONCRETE);
        loadTextureMiddle("Assets/texture/middle/ConcreteFloor.data", FLOOR);
        loadTextureMiddle("Assets/texture/middle/Car.data", CAR);
        loadTextureMiddle("Assets/texture/middle/alpha.data", ALPHA);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEXWIDTHMIDDLE * 8, TEXHEIGHTMIDDLE,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandleMiddle[CONCRETE]);
        glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTHMIDDLE * 6, 0, TEXWIDTHMIDDLE, TEXHEIGHTMIDDLE,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandleMiddle[CAR]);
        glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTHMIDDLE * 7, 0, TEXWIDTHMIDDLE, TEXHEIGHTMIDDLE,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandleMiddle[ALPHA]);
    }
}

void Texture::setResolution(int num) {
    textureResolution = num;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    if (textureResolution == 0) {
        loadTexture("Assets/texture/Circle.data", SPEEDMETER);
        loadTexture("Assets/texture/ConcreteWall.data", CONCRETE);
        loadTexture("Assets/texture/ConcreteFloor.data", FLOOR);
        loadTexture("Assets/texture/Car.data", CAR);
        loadTexture("Assets/texture/alpha.data", ALPHA);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEXWIDTH * 8, TEXHEIGHT,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandle[CONCRETE]);
        glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTH * 6, 0, TEXWIDTH, TEXHEIGHT,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandle[CAR]);
        glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTH * 7, 0, TEXWIDTH, TEXHEIGHT,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandle[ALPHA]);
    }
    else if (textureResolution == 1) {
        loadTextureMiddle("Assets/texture/middle/Circle.data", SPEEDMETER);
        loadTextureMiddle("Assets/texture/middle/ConcreteWall.data", CONCRETE);
        loadTextureMiddle("Assets/texture/middle/ConcreteFloor.data", FLOOR);
        loadTextureMiddle("Assets/texture/middle/Car.data", CAR);
        loadTextureMiddle("Assets/texture/middle/alpha.data", ALPHA);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEXWIDTHMIDDLE * 8, TEXHEIGHTMIDDLE,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandleMiddle[CONCRETE]);
        glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTHMIDDLE * 6, 0, TEXWIDTHMIDDLE, TEXHEIGHTMIDDLE,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandleMiddle[CAR]);
        glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTHMIDDLE * 7, 0, TEXWIDTHMIDDLE, TEXHEIGHTMIDDLE,
            GL_RGBA, GL_UNSIGNED_BYTE, textureHandleMiddle[ALPHA]);
    }
}

void Texture::initTexture() {
    /* 頂点のオブジェクト空間における座標値をテクスチャ座標に使う */
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

    /* テクスチャ座標生成関数の設定 */
    glTexGendv(GL_S, GL_OBJECT_PLANE, genfunc[0]);
    glTexGendv(GL_T, GL_OBJECT_PLANE, genfunc[1]);
    glTexGendv(GL_R, GL_OBJECT_PLANE, genfunc[2]);
    glTexGendv(GL_Q, GL_OBJECT_PLANE, genfunc[3]);

    glEnable(GL_DEPTH_TEST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glAlphaFunc(GL_GREATER, 0.5); //アルファ値による透過処理
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR); // テクスチャの拡大設定
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // テクスチャの縮小設定
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
}

void Texture::loadTexture(const char texture1[], int Number) {
    /* テクスチャの読み込みに使う配列 */
    FILE* fp;

    /* テクスチャ画像の読み込み */
    if ((fp = fopen(texture1, "rb")) != NULL) {
        fread(textureHandle[Number], sizeof textureHandle[Number], 1, fp);
        fclose(fp);
    }
    else {
        perror(texture1);
    }
}

void Texture::loadTextureMiddle(const char texture1[], int Number) {
    /* テクスチャの読み込みに使う配列 */
    FILE* fp;

    /* テクスチャ画像の読み込み */
    if ((fp = fopen(texture1, "rb")) != NULL) {
        fread(textureHandleMiddle[Number], sizeof textureHandleMiddle[Number], 1, fp);
        fclose(fp);
    }
    else {
        perror(texture1);
    }
}

void Texture::setTexture(int textureNumber) {
    int i;
    switch (textureNumber) {
    case SPEEDMETER:
        if (textureResolution == 0) {
            glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, TEXWIDTH, TEXHEIGHT,
                GL_RGBA, GL_UNSIGNED_BYTE, textureHandle[SPEEDMETER]);
        }
        else if (textureResolution == 1) {
            glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, TEXWIDTHMIDDLE, TEXHEIGHTMIDDLE,
                GL_RGBA, GL_UNSIGNED_BYTE, textureHandleMiddle[SPEEDMETER]);
        }
        break;
    case CONCRETE:
        if (textureResolution == 0) {
            for (i = 0; i < 6; i++) {   // 6面入れ替え
                glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTH * i, 0, TEXWIDTH, TEXHEIGHT,
                    GL_RGBA, GL_UNSIGNED_BYTE, textureHandle[CONCRETE]);
            }
        }
        else if (textureResolution == 1) {
            for (i = 0; i < 6; i++) {   // 6面入れ替え
                glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTHMIDDLE * i, 0, TEXWIDTHMIDDLE, TEXHEIGHTMIDDLE,
                    GL_RGBA, GL_UNSIGNED_BYTE, textureHandleMiddle[CONCRETE]);
            }
        }
        break;
    case FLOOR:
        if (textureResolution == 0) {
            for (i = 0; i < 6; i++) {   // 6面入れ替え
                glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTH * i, 0, TEXWIDTH, TEXHEIGHT,
                    GL_RGBA, GL_UNSIGNED_BYTE, textureHandle[FLOOR]);
            }
        }
        else if (textureResolution == 1) {
            for (i = 0; i < 6; i++) {   // 6面入れ替え
                glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTHMIDDLE * i, 0, TEXWIDTHMIDDLE, TEXHEIGHTMIDDLE,
                    GL_RGBA, GL_UNSIGNED_BYTE, textureHandleMiddle[FLOOR]);
            }
        }
        break;
    case CAR:
        // 7枚目のテクスチャ位置を使う
        if (textureResolution == 0) {
            glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTH * 6, 0, TEXWIDTH, TEXHEIGHT,
                GL_RGBA, GL_UNSIGNED_BYTE, textureHandle[CAR]);
        }
        else if (textureResolution == 1) {
            glTexSubImage2D(GL_TEXTURE_2D, 0, TEXWIDTHMIDDLE * 6, 0, TEXWIDTHMIDDLE, TEXHEIGHTMIDDLE,
                GL_RGBA, GL_UNSIGNED_BYTE, textureHandleMiddle[CAR]);
        }

        break;
    }
}

GLubyte* Texture::loadPng(const char fp[]) {
	GLubyte* handle = nullptr;
	return handle;
}