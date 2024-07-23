#include <glut.h>
#include "ShiftLever.h"
#include "SystemMain.h"

void ShiftLever::draw() {
	GLfloat mat0ambi[] = { 0.1,  0.1, 0.1, 1.0 };//•”ç
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //ŠÂ‹«Œõ‚Ì”½ŽË—¦‚ðÝ’è
	GLfloat mat0diff[] = { 0.1,  0.1, 0.1, 1.0 };//•”ç
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //ŠgŽUŒõ‚Ì”½ŽË—¦‚ðÝ’è
	GLfloat mat0spec[] = { 0.1,  0.1, 0.1, 1.0 };//•”ç
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //‹¾–ÊŒõ‚Ì”½ŽË—¦‚ðÝ’è
	GLfloat mat0shine[] = { 27.89743616 };//•”ç
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
	glPushMatrix(); {
		glRotatef(15 + shiftAngle, 1.0, 0.0, 0.0);
		glTranslatef(0.30f, 0.0f, -2.0f);
		glPushMatrix(); {
			glTranslatef(1.0f, -2.0f, 1.0f);
			glScalef(0.1, 0.1, 2.0);
			glutSolidCube(0.8);
		}glPopMatrix();
		glPushMatrix(); {
			glTranslatef(1.0f, -2.0f, 0.0f);
			glutSolidSphere(0.20, 40, 40);
		}glPopMatrix();
	}glPopMatrix();
}

void ShiftLever::update() {
	if (SystemMain::getIns()->key.getKeyZON() > 0) {
		shiftAngle -= 0.9;
		if (shiftAngle < -10.0) {
			shiftAngle = -10.0;
		}
	}
	else {
		shiftAngle += 0.9;
		if (shiftAngle > 2.0) {
			shiftAngle = 2.0;
		}
	}
}