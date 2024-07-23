#include <glut.h>
#include "SegmentDisplay.h"

SegmentDisplay::SegmentDisplay() {
	int i;
	for (i = 0; i < amountOfLamp; i++) {
		setLampState(i, i);
	}
	for (i = 0; i < amountOfLampB; i++) {
		setLampBState(i, i);
	}
	for (i = 0; i < amountOfLampTime; i++) {
		setLampTimeState(i, i);
	}
	//fuel
	lampCharBState[0] = 0b1100011;
	lampCharBState[1] = 0b0011111;
	lampCharBState[2] = 0b1100111;
	lampCharBState[3] = 0b0000111;
	//cash
	lampCharCState[0] = 0b0100111;
	lampCharCState[1] = 0b1111011;
	lampCharCState[2] = 0b1101101;
	lampCharCState[3] = 0b1011011;
	//LEVEL
	lampCharAState[0] = 0b0000111;
	lampCharAState[1] = 0b1100111;
	lampCharAState[2] = 0b0011111;
	lampCharAState[3] = 0b1100111;
	lampCharAState[4] = 0b0000111;
	lampCharAState[5] = 0b0011000;
}

void SegmentDisplay::draw() {
	int i;
	for (i = 0; i < amountOfLamp; i++) {
		draw7Seg(10.0 + 0.5 * i, -7.0, lampState[i], 2);
	}
	//for (i = 0; i < amountOfLampB; i++) {
	//	draw7Seg(10.0 + 0.5 * i, -5.0, lampBState[i]);
	//}
	for (i = 0; i < amountOfLampTime; i++) { // Time
		draw7Seg(-13.75 + 0.5 * i, -5.0, lampTimeState[i], 3);
	}
	for (i = 0; i < amountOfLampCharA; i++) { // Level
		draw7Seg(-13.75 + 0.5 * i, -7.0, lampCharAState[i], 1);
	}
	for (i = 0; i < amountOfLampCharB; i++) {	// Fuel
		draw7Seg(6.5 + 0.5 * i, -5.0, lampCharBState[i], 0);
	}
	for (i = 0; i < amountOfLampCharC; i++) {	//Cash
		draw7Seg(6.5 + 0.5 * i, -7.0, lampCharCState[i], 2);
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

void SegmentDisplay::setLampBState(int lampNum, int setNum) {
	if (lampNum < amountOfLampB) {
		switch (setNum) {
		case 0:
			lampBState[lampNum] = 0b0111111;
			break;
		case 1:
			lampBState[lampNum] = 0b0011000;
			break;
		case 2:
			lampBState[lampNum] = 0b1110110;
			break;
		case 3:
			lampBState[lampNum] = 0b1111100;
			break;
		case 4:
			lampBState[lampNum] = 0b1011001;
			break;
		case 5:
			lampBState[lampNum] = 0b1101101;
			break;
		case 6:
			lampBState[lampNum] = 0b1101111;
			break;
		case 7:
			lampBState[lampNum] = 0b0111000;
			break;
		case 8:
			lampBState[lampNum] = 0b1111111;
			break;
		case 9:
			lampBState[lampNum] = 0b1111101;
			break;
		}
	}
}


void SegmentDisplay::setLampTimeState(int lampNum, int setNum) {
	int tmpState = 0;
	if (lampNum < amountOfLampTime) {
		switch (setNum) {
		case 0:
			tmpState = 0b0111111;
			break;
		case 1:
			tmpState = 0b0011000;
			break;
		case 2:
			tmpState = 0b1110110;
			break;
		case 3:
			tmpState = 0b1111100;
			break;
		case 4:
			tmpState = 0b1011001;
			break;
		case 5:
			tmpState = 0b1101101;
			break;
		case 6:
			tmpState = 0b1101111;
			break;
		case 7:
			tmpState = 0b0111000;
			break;
		case 8:
			tmpState = 0b1111111;
			break;
		case 9:
			tmpState = 0b1111101;
			break;
		}
		lampTimeState[lampNum] = tmpState;
	}
}

void SegmentDisplay::setLampCharAState(int lampNum, int setNum) {
	int tmpState = 0;
	if (lampNum < amountOfLampCharA) {
		switch (setNum) {
		case 0:
			tmpState = 0b0111111;
			break;
		case 1:
			tmpState = 0b0011000;
			break;
		case 2:
			tmpState = 0b1110110;
			break;
		case 3:
			tmpState = 0b1111100;
			break;
		case 4:
			tmpState = 0b1011001;
			break;
		case 5:
			tmpState = 0b1101101;
			break;
		case 6:
			tmpState = 0b1101111;
			break;
		case 7:
			tmpState = 0b0111000;
			break;
		case 8:
			tmpState = 0b1111111;
			break;
		case 9:
			tmpState = 0b1111101;
			break;
		}
		lampCharAState[lampNum] = tmpState;
	}
}

void SegmentDisplay::setLampCharBState(int lampNum, int setNum) {
	int tmpState = 0;
	if (lampNum < amountOfLampCharB) {
		switch (setNum) {
		case 0:
			tmpState = 0b0111111;
			break;
		case 1:
			tmpState = 0b0011000;
			break;
		case 2:
			tmpState = 0b1110110;
			break;
		case 3:
			tmpState = 0b1111100;
			break;
		case 4:
			tmpState = 0b1011001;
			break;
		case 5:
			tmpState = 0b1101101;
			break;
		case 6:
			tmpState = 0b1101111;
			break;
		case 7:
			tmpState = 0b0111000;
			break;
		case 8:
			tmpState = 0b1111111;
			break;
		case 9:
			tmpState = 0b1111101;
			break;
		}
		lampCharBState[lampNum] = tmpState;
	}
}

void SegmentDisplay::setLampCharCState(int lampNum, int setNum) {
	int tmpState = 0;
	if (lampNum < amountOfLampCharC) {
		switch (setNum) {
		case 0:
			tmpState = 0b0111111;
			break;
		case 1:
			tmpState = 0b0011000;
			break;
		case 2:
			tmpState = 0b1110110;
			break;
		case 3:
			tmpState = 0b1111100;
			break;
		case 4:
			tmpState = 0b1011001;
			break;
		case 5:
			tmpState = 0b1101101;
			break;
		case 6:
			tmpState = 0b1101111;
			break;
		case 7:
			tmpState = 0b0111000;
			break;
		case 8:
			tmpState = 0b1111111;
			break;
		case 9:
			tmpState = 0b1111101;
			break;
		}
		lampCharCState[lampNum] = tmpState;
	}
}

/*
@brief 7�Z�O�����g�f�B�X�v���C�̕`��
@param x x���W
@param y y���W
@param state 7seg�̃����v���`��֐��ォ�珇�ɉ��ʂ̃r�b�g�ɑΉ� 
*/
void SegmentDisplay::draw7Seg(double x, double y, int state, int color) {
	double z = -30;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix(); {
		//�@����
		glPushMatrix(); {
			if ((state & 0b0000001) != 0) {
				setMaterial(color);
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
				setMaterial(color);
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
				setMaterial(color);
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
				setMaterial(color);
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
				setMaterial(color);
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
			setMaterial(color);
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
				setMaterial(color);
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

void SegmentDisplay::setMatGreen(){
	//�O���[��
	GLfloat matasambi[] = { 0.3,  1.0, 0.1, 1.0 };
	GLfloat matasdiff[] = { 0.3,  1.0, 0.1, 1.0 };
	GLfloat matasspec[] = { 0.0,  0.0, 0.0, 1.0 };
	GLfloat matasshine[] = { 27.89743616 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matasambi); //�����̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matasdiff); //�g�U���̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matasspec); //���ʌ��̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matasshine);
}

void SegmentDisplay::setMatYellow() {
	//�C�G���[
	GLfloat matasambi[] = { 0.9,  0.9, 0.2, 1.0 };
	GLfloat matasdiff[] = { 0.9,  0.9, 0.2, 1.0 };
	GLfloat matasspec[] = { 0.0,  0.0, 0.0, 1.0 };
	GLfloat matasshine[] = { 27.89743616 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matasambi); //�����̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matasdiff); //�g�U���̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matasspec); //���ʌ��̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matasshine);
}

void SegmentDisplay::setMatBlue(){
	//�u���[
	GLfloat matasambi[] = { 0.1,  0.8, 1.0, 1.0 };
	GLfloat matasdiff[] = { 0.1,  0.8, 1.0, 1.0 };
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
	GLfloat matasdiff[] = { 0.1,  0.1, 0.1, 1.0 };
	GLfloat matasspec[] = { 0.0,  0.0, 0.0, 1.0 };
	GLfloat matasshine[] = { 17.89743616 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matasambi); //�����̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matasdiff); //�g�U���̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matasspec); //���ʌ��̔��˗���ݒ�
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matasshine);
}

void SegmentDisplay::setMaterial(int num) {
	switch (num) {
	case 0:
		setMatOrange();
		break;
	case 1:
		setMatGreen();
		break;
	case 2:
		setMatYellow();
		break;
	case 3:
		setMatBlue();
	}
}