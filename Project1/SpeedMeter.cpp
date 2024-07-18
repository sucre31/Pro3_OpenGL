#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <glut.h>
#include "SpeedMeter.h"
#include "Texture.h"

SpeedMeter::SpeedMeter() {
	speedRate = 0;
}

void SpeedMeter::draw() {
	double tmpSpeed;	//�X�s�[�h���}�C�i�X�ɂ��Ȃ��悤��
	glPushMatrix();
	glPushMatrix(); {       //�X�s�[�h���[�^�[
		GLfloat mat0ambi[] = { 0.59225,  0.19225, 0.19225, 1.0 };//��
		GLfloat mat0diff[] = { 0.60754,  0.20754, 0.20754, 1.0 };
		GLfloat mat0spec[] = { 0.608273,  0.208273, 0.208273, 1.0 };
		GLfloat mat0shine[] = { 51.2 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //�����̔��˗���ݒ�
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //�g�U���̔��˗���ݒ�
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //���ʌ��̔��˗���ݒ�
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);

		// �`��
		tmpSpeed = abs(speed);
		glTranslatef(0.3 * -cos((150 * speedRate - 225) * (M_PI / 180)), 0.3 * -sin((150 * speedRate - 225) * (M_PI / 180)), 0.0);
		glPushMatrix(); {
			glTranslatef(-2.0, -2.0f, 0.0);
			glRotatef(150 * speedRate - 135, 0.0, 0.0, 1.0);
			glScalef(0.01, 0.5, 0.01);
			glPushMatrix(); {
				glutSolidCube(1.0);
			}glPopMatrix();
		}glPopMatrix();
	}glPopMatrix();

	GLfloat matasambi[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat matasdiff[] = { 1.0,  1.0, 1.0, 1.0 };
	GLfloat matasspec[] = { 1.1,  1.1, 1.1, 1.0 };
	GLfloat matasshine[] = { 27.89743616 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matasambi); //�����̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matasdiff); //�g�U���̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matasspec); //���ʌ��̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matasshine);
	//�P���̂S�p�`��`��
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	Texture::getIns()->setTexture(Texture::getIns()->SPEEDMETER);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-2.0, -2.0, 0.0);
	glPushMatrix(); {
		double size = 0.6;
		glEnable(GL_TEXTURE_2D);
		glNormal3d(0.0, 0.0, 1.0);	//�@��
		glBegin(GL_QUADS);
		glTexCoord2d(0.0, 1.0); //���_�̃e�N�X�`�����W
		glVertex3d(-size, -size, 0.0);
		glTexCoord2d(0.125, 1.0);
		glVertex3d(size, -size, 0.0);
		glTexCoord2d(0.125, 0.0);
		glVertex3d(size, size, 0.0);
		glTexCoord2d(0.0, 0.0);
		glVertex3d(-size, size, 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}glPopMatrix();
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
}

void SpeedMeter::update() {
	// �j���u�Ԉړ����Ȃ��悤�ɂ���
	double tmpSpeed; //�ڕW�̐j�̓��슄��
	double rateLimit = 0.05;
	tmpSpeed = abs(speed) / speedMax;
	if (abs(speedRate - tmpSpeed) > rateLimit) {
		if (speedRate > tmpSpeed) {
			speedRate -= rateLimit;
			if (speedRate < tmpSpeed) {
				speedRate = tmpSpeed;
			}
		}
		else {
			speedRate += rateLimit;
			if (speedRate > tmpSpeed) {
				speedRate = tmpSpeed;
			}
		}
	}
	else {
		speedRate = tmpSpeed;
	}
}