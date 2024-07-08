#pragma once

#include "ShiftLever.h"
#include "HeadLight.h"
#include "Pedal.h"

class Player
{
public:
	Player();
	virtual ~Player() = default;
	void update();
	void draw();
	void drawInfo();	// �C���^�t�F�[�X���̏������܂Ƃ߂�
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
	void setX(double xIn) { x = xIn; }
	void setY(double yIn) { y = yIn; }
	void setZ(double zIn) { z = zIn; }
	void setDefX(double xIn) { defX = xIn; }
	void setDefY(double yIn) { defY = yIn; }
	void setDefZ(double zIn) { defZ = zIn; }
private:
	ShiftLever shiftLever;
	HeadLight headLight;
	Pedal pedalAccel;
	Pedal pedalBrake;
	const int HandelRate = 140;		//��������̃n���h���̉�]���x
	int shift;				// �V�t�g���o�[�̏�� 0:�h���C�u, 1:���o�[�X, 2:�j���[�g����
	int FieldX, FieldZ;		// �O���b�h���W�ϊ�
	double accel;			// �A�N�Z��(�����x)
	double brake;
	double speed;			// ����
	double speedMax;		// �ő呬�x
	double handling;		// �n���h����]�X�s�[�h
	double x, y, z;
	double defX, defY, defZ;
	double velY;
	double angleY;			// Y���̉�]��(���W�A��)
	double handleAngle;		// �n���h���̉�]��
	double handleAngleMax;	// �n���h���̍ő��]�p
	void drawHandle();
	void drawSpeed();
};

