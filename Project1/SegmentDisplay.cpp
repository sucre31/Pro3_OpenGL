#include <glut.h>
#include "SegmentDisplay.h"

SegmentDisplay::SegmentDisplay() {
	int i;
	for (i = 0; i < amountOfLamp; i++) {
		setLampState(i, i);
	}
}

void SegmentDisplay::draw() {
	int i;
	for (i = 0; i < 8; i++) {
		draw7Seg(10.0 + 0.5 * i, -7.0, lampState[i]);
	}
}

/*
@brief �����v�̐�����ݒ�
@param lapmpNum �ݒ肷�郉���v�ԍ�
@param setNum �ݒ肷�鐔��
*/
void SegmentDisplay::setLampState(int lampNum, int setNum) {
	if (lampNum < amountOfLamp) {
		switch (setNum) {
		case 0:
			lampState[lampNum] = 0b0111111;
			break;
		case 1:
			lampState[lampNum] = 0b0011000;
			break;
		case 2:
			lampState[lampNum] = 0b1110110;
			break;
		case 3:
			lampState[lampNum] = 0b1111100;
			break;
		case 4:
			lampState[lampNum] = 0b1011001;
			break;
		case 5:
			lampState[lampNum] = 0b1101101;
			break;
		case 6:
			lampState[lampNum] = 0b1101111;
			break;
		case 7:
			lampState[lampNum] = 0b0111000;
			break;
		case 8:
			lampState[lampNum] = 0b1111111;
			break;
		case 9:
			lampState[lampNum] = 0b1111101;
			break;
		}
	}
}


/*
@brief 7�Z�O�����g�f�B�X�v���C�̕`��
@param x x���W
@param y y���W
@param state 7seg�̃����v���`��֐��ォ�珇�ɉ��ʂ̃r�b�g�ɑΉ� 
*/
void SegmentDisplay::draw7Seg(double x, double y, int state) {
	double z = -30;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix(); {
		//�@����
		glPushMatrix(); {
			if ((state & 0b0000001) != 0) {
				setMatOrange();
			}
			else {
				setMatGrey();
			}
			glTranslatef(x, y, z);
			glTranslatef(0.0, 0.3, 0.0);
			drawLamp();
		}glPopMatrix();
		// ����
		glPushMatrix(); {
			if ((state & 0b0000010) == 0b0000010) {
				setMatOrange();
			}
			else {
				setMatGrey();
			}
			glTranslatef(x, y, z);
			drawLamp();
		}glPopMatrix();
		// ��
		glPushMatrix(); {
			if ((state & 0b0000100) == 0b0000100) {
				setMatOrange();
			}
			else {
				setMatGrey();
			}
			glTranslatef(x, y, z);
			glTranslatef(0.075, -0.225, 0.0);
			glPushMatrix();
			glRotated(90, 0.0, 0.0, 1.0);
			drawLamp();
			glPopMatrix();
		}glPopMatrix();
		// �E��
		glPushMatrix(); {
			if ((state & 0b0001000) == 0b0001000) {
				setMatOrange();
			}
			else {
				setMatGrey();
			}
			glTranslatef(x, y, z);
			glTranslatef(0.36, 0.0, 0.0);
			drawLamp();
		}glPopMatrix();
		// �E��
		glPushMatrix(); {
			if ((state & 0b0010000) == 0b0010000) {
				setMatOrange();
			}
			else {
				setMatGrey();
			}
			glTranslatef(x, y, z);
			glTranslatef(0.36, 0.3, 0.0);
			drawLamp();
		}glPopMatrix();
		// ��
		if ((state & 0b0100000) == 0b0100000) {
			setMatOrange();
		}
		else {
			setMatGrey();
		}
		glPushMatrix(); {
			glTranslatef(x, y, z);
			glTranslatef(0.075, 0.375, 0.0);
			glPushMatrix();
			glRotated(90, 0.0, 0.0, 1.0);
			drawLamp();
			glPopMatrix();
		}glPopMatrix();
		// ��
		glPushMatrix(); {
			if ((state & 0b1000000) == 0b1000000) {
				setMatOrange();
			}
			else {
				setMatGrey();
			}
			glTranslatef(x, y, z);
			glTranslatef(0.075, 0.075, 0.0);
			glPushMatrix();
			glRotated(90, 0.0, 0.0, 1.0);
			drawLamp();
			glPopMatrix();
		}glPopMatrix();
	}glPopMatrix();
}

void SegmentDisplay::drawLamp() {
	glPushMatrix();
	//glTranslatef(1.0, 0.0, 0.0);
	glScaled(0.1, 0.12, 0.1);
	glPushMatrix(); {
		glNormal3d(0.0, 0.0, 1.0);	//�@��
		glBegin(GL_QUADS);
		glVertex3d(0.0, 0.5, 0.0);
		glVertex3d(-0.5, 0.0, 0.0);
		glVertex3d(-0.5, -1.5, 0.0);
		glVertex3d(0.5, 0.0, 0.0);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3d(0.0, -2.0, 0.0);
		glVertex3d(0.5, -1.5, 0.0);
		glVertex3d(0.5, 0.0, 0.0);
		glVertex3d(-0.5, -1.5, 0.0);
		glEnd();
	}glPopMatrix();
	glPopMatrix();
}

void SegmentDisplay::setMatOrange() {
	//�I�����W
	GLfloat matasambi[] = { 0.9,  0.3, 0.0, 1.0 };
	GLfloat matasdiff[] = { 0.9,  0.3, 0.0, 1.0 };
	GLfloat matasspec[] = { 0.0,  0.0, 0.0, 1.0 };
	GLfloat matasshine[] = { 27.89743616 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matasambi); //�����̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matasdiff); //�g�U���̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matasspec); //���ʌ��̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matasshine);
}

void SegmentDisplay::setMatGrey() {
	//�O���[
	GLfloat matasambi[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat matasdiff[] = { 0.2,  0.2, 0.2, 1.0 };
	GLfloat matasspec[] = { 0.2,  0.2, 0.2, 1.0 };
	GLfloat matasshine[] = { 17.89743616 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matasambi); //�����̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matasdiff); //�g�U���̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matasspec); //���ʌ��̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matasshine);
}