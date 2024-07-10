#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "SpeedMeter.h"

void SpeedMeter::draw() {
	glPushMatrix(); {       //ƒXƒs[ƒhƒ[ƒ^[
		GLfloat mat0ambi[] = { 0.59225,  0.19225, 0.19225, 1.0 };//Ô
		GLfloat mat0diff[] = { 0.60754,  0.50754, 0.50754, 1.0 };
		GLfloat mat0spec[] = { 0.608273,  0.508273, 0.508273, 1.0 };
		GLfloat mat0shine[] = { 51.2 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //ŠÂ‹«Œõ‚Ì”½Ë—¦‚ğİ’è
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //ŠgUŒõ‚Ì”½Ë—¦‚ğİ’è
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //‹¾–ÊŒõ‚Ì”½Ë—¦‚ğİ’è
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);

		// •`‰æ
		glTranslatef(0.3 * -cos((150 * (speed / speedMax) - 225) * (M_PI / 180)), 0.3 * -sin((150 * (speed / speedMax) - 225) * (M_PI / 180)), 0.0);
		glPushMatrix(); {
			glTranslatef(-2.0, -2.0f, 0.0);
			glRotatef(150 * (speed / speedMax) - 135, 0.0, 0.0, 1.0);
			glScalef(0.01, 0.5, 0.01);
			glPushMatrix(); {
				glutSolidCube(1.0);
			}glPopMatrix();
		}glPopMatrix();
	}glPopMatrix();

	GLfloat matasambi[] = { 1.0, 1.0, 1.0, 1.0 };//•”ç
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matasambi); //ŠÂ‹«Œõ‚Ì”½Ë—¦‚ğİ’è
	GLfloat matasdiff[] = { 1.0,  1.0, 1.0, 1.0 };//•”ç
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matasdiff); //ŠgUŒõ‚Ì”½Ë—¦‚ğİ’è
	GLfloat matasspec[] = { 1.1,  1.1, 1.1, 1.0 };//•”ç
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matasspec); //‹¾–ÊŒõ‚Ì”½Ë—¦‚ğİ’è
	GLfloat matasshine[] = { 27.89743616 };//•”ç
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matasshine);
	//‚P–‡‚Ì‚SŠpŒ`‚ğ•`‚­
	glDisable(GL_ALPHA_TEST);
	glTranslatef(-2.0, -2.0, 0.0);
	glPushMatrix(); {
		double size = 0.6;
		glEnable(GL_TEXTURE_2D);
		glNormal3d(0.0, 0.0, 1.0);	//–@ü
		glBegin(GL_QUADS);
		glTexCoord2d(0.0, 1.0);
		glVertex3d(-size, -size, 0.0);
		glTexCoord2d(1.0, 1.0);
		glVertex3d(size, -size, 0.0);
		glTexCoord2d(1.0, 0.0);
		glVertex3d(size, size, 0.0);
		glTexCoord2d(0.0, 0.0);
		glVertex3d(-size, size, 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}glPopMatrix();
}