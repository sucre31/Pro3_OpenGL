#pragma once

class Player
{
public:
	Player();
	virtual ~Player() = default;
	void update();
	void draw();
	void drawHandle();
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
private:
	const int HandelRate = 130;		//��������̃n���h���̉�]���x
	int shift;				// �V�t�g���o�[�̏�� 0:�h���C�u, 1:���o�[�X, 2:�j���[�g����
	int FieldX, FieldZ;		// �O���b�h���W�ϊ�
	double accel;			// �A�N�Z��(�����x)
	double brake;
	double speed;			// ����
	double speedMax;		// �ő呬�x
	double handling;		// �n���h����]�X�s�[�h
	double x, y, z;
	double velY;
	double angleY;			// Y���̉�]��(���W�A��)
	double handleAngle;		// �n���h���̉�]��
	double handleAngleMax;	// �n���h���̍ő��]�p
};

