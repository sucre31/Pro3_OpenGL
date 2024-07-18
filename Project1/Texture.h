#pragma once
#include <glut.h>
#include "Singleton.h"
class Texture final : public Singleton<Texture>
{
public:
	Texture();
	~Texture() = default; 
	enum TextureName {     
		//�񋓎q�̒�`
		SPEEDMETER,
		CONCRETE,
		CONCRETECUBE,
		FLOOR,
		CAR,
		ALPHA,
		BIKE
	};
	void initTexture();
	void loadTexture(const char texture1[], int Number);
	void loadTextureMiddle(const char texture1[], int Number);
	void setTexture(int textureNumber);
	void setResolution(int num);
private:
	int textureResolution;	// 0: 1024 1: 512 2: 256
	static const int TEXHEIGHT = 1024;
	static const int TEXWIDTH = 1024;
	static const int TEXHEIGHTMIDDLE = 512;
	static const int TEXWIDTHMIDDLE = 512;
	const double genfunc[4][4] = {   /* �e�N�X�`�������֐��̃p�����[�^ */
		{ 1.0, 0.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0, 0.0 },
		{ 0.0, 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 0.0, 1.0 },
	};
	GLubyte *textureHandle[7][TEXHEIGHT][TEXWIDTH][4];			// ���I�Ɋm�ۂ���悤�ɕύX������
	GLubyte* textureHandleMiddle[7][TEXHEIGHTMIDDLE][TEXWIDTHMIDDLE][4];
	GLubyte* loadPng(const char fp[]);
	//GLubyte texture[TEXHEIGHT][TEXWIDTH][4];
};

