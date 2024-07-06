#pragma once
#include "Singleton.h"
#include "Key.h"
#include "FieldManipulator.h"
#include "BackGround.h"
#include "Player.h"
#include "Camera.h"
#include "InfoView.h"
#include "ShiftLever.h"

class SystemMain final : public Singleton<SystemMain>
{
public:
	Key key;						//�L�[���͂�ێ�
	FieldData fieldData;			// �e�C���X�^���X�̏���
	BackGround backGround;
	FieldManipulator field;
	Player player;
	Camera camera;
	InfoView info;
	ShiftLever shiftLever;
	SystemMain() = default;
	virtual ~SystemMain() = default;
	void lightInit();
	void textureInit();
	static void display();			// �R�[���o�b�N���邽�߂ɐÓI�֐��ɂ��Ă���
	static void reshape(int, int);
	static void timerFunc(int);		
	static void keyboard(unsigned char, int, int);
	static void keyboardUp(unsigned char, int, int);
	static void specialKey(int, int, int);
	static void specialKeyUp(int, int, int);
private:
	//float CamaraX, CameraY, CameraZ;	// �N���X�ɂ��������������� ����
	int winH, winW;					// �E�B���h�E�T�C�Y��ێ�
	void view2D();					// �`���2D��
	void view3D();					// �`���3D��
	void reshapeFunc(int, int);
	void draw();					// �`��p�̏���
	void update();					// ���t���[��(?)�s���鏈��
	void keyboardCall(unsigned char, int, int);	// �L�[�{�[�h�C�x���g�̏���
	void keyboardUpCall(unsigned char, int, int);	// �L�[�{�[�h�C�x���g�̏���
	void keyCall(int, int, int);	// �L�[�{�[�h�C�x���g�̏���
	void keyCallUp(int, int, int);	// �L�[�{�[�h�C�x���g�̏���
};

