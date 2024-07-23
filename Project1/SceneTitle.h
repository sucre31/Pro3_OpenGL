#pragma once
#include "BackGround.h"
class SceneTitle
{
public:
	SceneTitle();
	void update();
	void draw();
private:
	BackGround backGround;
	double rota;
	int select;		//オプションの選択
	double cursorPos;
	bool keyPushedDown;	// 押されたフレームのみ動かすため
	bool keyPushedUp;	// ホントはkey側で実装したい
};

