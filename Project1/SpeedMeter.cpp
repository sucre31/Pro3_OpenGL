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
	double tmpSpeed;	//ƒXƒs[ƒh‚ðƒ}ƒCƒiƒX‚É‚µ‚È‚¢‚æ‚¤‚É
	glPushMatrix();
	glPushMatrix(); {       //ƒXƒs[ƒhƒ[ƒ^[
		GLfloat mat0ambi[] = { 0.59225,  0.19225, 0.19225, 1.0 };//Ô
		GLfloat mat0diff[] = { 0.60754,  0.20754, 0.20754, 1.0 };
		GLfloat mat0spec[] = { 0.608273,  0.208273, 0.208273, 1.0 };
		GLfloat mat0shine[] = { 51.2 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //ŠÂ‹«Œõ‚Ì”½ŽË—¦‚ðÝ’è
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //ŠgŽUŒõ‚Ì”½ŽË—¦‚ðÝ’è
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //‹¾–ÊŒõ‚Ì”½ŽË—¦‚ðÝ’è
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);

		// •`‰æ
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
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matasambi); //ŠÂ‹«Œõ‚Ì”½ŽË—¦‚ðÝ’è
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matasdiff); //ŠgŽUŒõ‚Ì”½ŽË—¦‚ðÝ’è
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matasspec); //‹¾–ÊŒõ‚Ì”½ŽË—¦‚ðÝ’è
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matasshine);
	//‚P–‡‚Ì‚SŠpŒ`‚ð•`‚­
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	Texture::getIns()->setTexture(Texture::getIns()->SPEEDMETER);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-2.0, -2.0, 0.0);
	glPushMatrix(); {
		double size = 0.6;
		glEnable(GL_TEXTURE_2D);
		glNormal3d(0.0, 0.0, 1.0);	//–@ü
		glBegin(GL_QUADS);
		glTexCoord2d(0.0, 1.0); //’¸“_‚ÌƒeƒNƒXƒ`ƒƒÀ•W
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
	// j‚ªuŠÔˆÚ“®‚µ‚È‚¢‚æ‚¤‚É‚·‚é
	double tmpSpeed; //–Ú•W‚Ìj‚Ì“®ìŠ„‡
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