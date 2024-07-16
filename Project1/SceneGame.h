#pragma once
#include "FieldManipulator.h"
#include "BackGround.h"
#include "Player.h"
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
	void update();
	void draw();
};

