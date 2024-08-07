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
	double tmpSpeed;	//スピードをマイナスにしないように
	glPushMatrix();
	glTranslated(0.6, 0.0, 0.0);
	glPushMatrix(); {       //スピードメーター
		GLfloat mat0ambi[] = { 0.59225,  0.19225, 0.19225, 1.0 };//赤
		GLfloat mat0diff[] = { 0.60754,  0.20754, 0.20754, 1.0 };
		GLfloat mat0spec[] = { 0.608273,  0.208273, 0.208273, 1.0 };
		GLfloat mat0shine[] = { 51.2 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //環境光の反射率を設定
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //拡散光の反射率を設定
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //鏡面光の反射率を設定
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);

		// 描画
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
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matasambi); //環境光の反射率を設定
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matasdiff); //拡散光の反射率を設定
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matasspec); //鏡面光の反射率を設定
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matasshine);
	//１枚の４角形を描く
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	Texture::getIns()->setTexture(Texture::getIns()->SPEEDMETER);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-2.0, -2.0, 0.0);
	glPushMatrix(); {
		double size = 0.6;
		glEnable(GL_TEXTURE_2D);
		glNormal3d(0.0, 0.0, 1.0);	//法線
		glBegin(GL_QUADS);
		glTexCoord2d(0.0, 1.0); //頂点のテクスチャ座標
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
	// 針が瞬間移動しないようにする
	double tmpSpeed; //目標の針の動作割合
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