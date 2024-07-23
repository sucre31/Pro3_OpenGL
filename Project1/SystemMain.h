#pragma once
#include "Singleton.h"
#include "SceneGame.h"
#include "SceneTitle.h"
#include "Key.h"

class SystemMain final : public Singleton<SystemMain>
{
public:
	SceneTitle title;
	SceneGame game;
	Key key;						//�L�[���͂�ێ�
	int winH, winW;					// �E�B���h�E�T�C�Y��ێ�
	int SceneNum;
	SystemMain();
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
	void view2D();					// �`���2D��
	void view3D();					// �`���3D��
	void view3DForUI();					// �`���3D��
	void changeScene(int);
private:
	void reshapeFunc(int, int);
	void draw();					// �`��p�̏���
	void update();					// ���t���[��(?)�s���鏈��
	void keyboardCall(unsigned char, int, int);	// �L�[�{�[�h�C�x���g�̏���
	void keyboardUpCall(unsigned char, int, int);	// �L�[�{�[�h�C�x���g�̏���
	void keyCall(int, int, int);	// �L�[�{�[�h�C�x���g�̏���
	void keyCallUp(int, int, int);	// �L�[�{�[�h�C�x���g�̏���

};

