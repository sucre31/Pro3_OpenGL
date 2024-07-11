#pragma once
#include <glut.h>
#include "Singleton.h"
class Texture final : public Singleton<Texture>
{
public:
	Texture();
	~Texture() = default; 
	enum TextureName {     
		//列挙子の定義
		SPEEDMETER,
		CONCRETE,
	};
	void initTexture();
	void loadTexture(const char texture1[], int Number);
	void setTexture(int textureNumber);
private:
	static const int TEXHEIGHT = 512;
	static const int TEXWIDTH = 512;
	static const int TEXHEIGHTSMALL = 128;
	static const int TEXWIDTHSMALL = 128;
	const double genfunc[4][4] = {   /* テクスチャ生成関数のパラメータ */
		{ 1.0, 0.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0, 0.0 },
		{ 0.0, 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 0.0, 1.0 },
	};
	GLubyte *textureHandle[5][TEXHEIGHT][TEXWIDTH][4];
	GLubyte* loadPng(const char fp[]);
	//GLubyte texture[TEXHEIGHT][TEXWIDTH][4];
};

