#pragma once
#include <glut.h>
#include "Singleton.h"
class Texture final : public Singleton<Texture>
{
public:
	Texture();
	~Texture() = default; 
	void loadTexture(const char texture1[]);
	void setTexture(int textureNumber);
private:
	static const int TEXHEIGHT = 256;
	static const int TEXWIDTH = 256;
	GLubyte *textureHandle[5];
	GLubyte* loadPng(const char fp[]);
	GLubyte texture[TEXHEIGHT][TEXWIDTH][4];
};

