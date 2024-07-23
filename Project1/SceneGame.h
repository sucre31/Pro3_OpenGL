#pragma once
#include "FieldManipulator.h"
#include "BackGround.h"
#include "Player.h"
#include "JudgeLap.h"
#include "Camera.h"
#include "InfoView.h"

class SceneGame
{
public:
	SceneGame();
	BackGround backGround;				// �e�C���X�^���X�̏���
	FieldManipulator field;
	Player player;
	Camera camera;
	InfoView info;
	JudgeLap judgeLap;
	void Init();
	void update();
	void draw();
private:
	const GLfloat lightPosition[4] = { 0.0, 5.0, 0.0, 1.0 }; //�����̈ʒu
	const GLfloat light_ambient[4] = { 0.1, 0.1, 0.1, 1.0f };    //����
	const GLfloat  light_diffuse[4] = { 0.8f, 0.8f, 0.8f, 1.0f };      //�g�U��
	const GLfloat  light_specular[4] = { 0.81f, 0.81f, 0.81f, 1.0f };     //���ʌ�
};

