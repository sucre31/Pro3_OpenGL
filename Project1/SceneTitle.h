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
	int select;		//�I�v�V�����̑I��
	double cursorPos;
	bool keyPushedDown;	// �����ꂽ�t���[���̂ݓ���������
	bool keyPushedUp;	// �z���g��key���Ŏ���������
};

