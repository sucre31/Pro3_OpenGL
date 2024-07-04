#pragma once
#include "Singleton.h"
#include "Key.h"
#include "FieldData.h"
#include "BackGround.h"
#include "Player.h"
#include "Camera.h"
#include "Plate.h"
#include "InfoView.h"
#include "ShiftLever.h"

class SystemMain final : public Singleton<SystemMain>
{
public:
	Key key;						//�L�[���͂�ێ�
	FieldData fieldData;			// �e�C���X�^���X�̏���
	BackGround backGround;
	Player player;
	Camera camera;
	Plate plate;
	InfoView info;
	ShiftLever shiftLever;
	SystemMain() = default;
	virtual ~SystemMain() = default;
	void lightInit();
	static void display();			// �R�[���o�b�N���邽�߂ɐÓI�֐��ɂ��Ă���
	static void reshape(int, int);
	static void timerFunc(int);		
	static void specialKey(int, int, int);
	static void specialKeyUp(int, int, int);
private:
	//float CamaraX, CameraY, CameraZ;	// �N���X�ɂ��������������� ����
	int winH, winW;					// �E�B���h�E�T�C�Y��ێ�
	void view2D();					// �`���2D��
	void view3D();					// �`���3D��
	void update();					// ���t���[��(?)�s���鏈��
	void reshapeFunc(int, int);
	void draw();					// �`��p�̏���
	void keyCall(int, int, int);	// �L�[�{�[�h�C�x���g�̏���
	void keyCallUp(int, int, int);	// �L�[�{�[�h�C�x���g�̏���
};

