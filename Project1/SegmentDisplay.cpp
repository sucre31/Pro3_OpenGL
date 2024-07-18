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
@brief ランプの数字を設定
@param lapmpNum 設定するランプ番号
@param setNum 設定する数字
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
@brief 7セグメントディスプレイの描画
@param x x座標
@param y y座標
@param state 7segのランプが描画関数上から順に下位のビットに対応 
*/
void SegmentDisplay::draw7Seg(double x, double y, int state) {
	double z = -30;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix(); {
		//　左上
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
		// 左下
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
		// 下
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
		// 右下
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
		// 右上
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
		// 上
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
		// 中
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
		glNormal3d(0.0, 0.0, 1.0);	//法線
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
	//オレンジ
	GLfloat matasambi[] = { 0.9,  0.3, 0.0, 1.0 };
	GLfloat matasdiff[] = { 0.9,  0.3, 0.0, 1.0 };
	GLfloat matasspec[] = { 0.0,  0.0, 0.0, 1.0 };
	GLfloat matasshine[] = { 27.89743616 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matasambi); //環境光の反射率を設定
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matasdiff); //拡散光の反射率を設定
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matasspec); //鏡面光の反射率を設定
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matasshine);
}

void SegmentDisplay::setMatGrey() {
	//グレー
	GLfloat matasambi[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat matasdiff[] = { 0.2,  0.2, 0.2, 1.0 };
	GLfloat matasspec[] = { 0.2,  0.2, 0.2, 1.0 };
	GLfloat matasshine[] = { 17.89743616 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matasambi); //環境光の反射率を設定
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matasdiff); //拡散光の反射率を設定
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matasspec); //鏡面光の反射率を設定
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matasshine);
}