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
	BackGround backGround;				// 各インスタンスの所持
	FieldManipulator field;
	Player player;
	Camera camera;
	InfoView info;
	JudgeLap judgeLap;
	void Init();
	void update();
	void draw();
private:
	const GLfloat lightPosition[4] = { 0.0, 5.0, 0.0, 1.0 }; //光源の位置
	const GLfloat light_ambient[4] = { 0.1, 0.1, 0.1, 1.0f };    //環境光
	const GLfloat  light_diffuse[4] = { 0.8f, 0.8f, 0.8f, 1.0f };      //拡散光
	const GLfloat  light_specular[4] = { 0.81f, 0.81f, 0.81f, 1.0f };     //鏡面光
};

