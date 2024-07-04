#include <glut.h>
#include "ShiftLever.h"
#include "SystemMain.h"

void ShiftLever::draw() {
	glPushMatrix(); {
		glRotatef(15 + shiftAngle, 1.0, 0.0, 0.0);
		glTranslatef(0.0f, 0.0f, -2.0f);
		glPushMatrix(); {
			glTranslatef(1.5f, -2.0f, 1.0f);
			glScalef(0.1, 0.1, 2.0);
			glutSolidCube(0.8);
		}glPopMatrix();
		glPushMatrix(); {
			glTranslatef(1.5f, -2.0f, 0.0f);
			glutSolidSphere(0.20, 40, 40);
		}glPopMatrix();
	}glPopMatrix();
}

void ShiftLever::update() {
	if (SystemMain::getIns()->key.getKeyZON()) {
		shiftAngle -= 0.5;
		if (shiftAngle < -10.0) {
			shiftAngle = -10.0;
		}
	}
	else {
		shiftAngle += 0.5;
		if (shiftAngle > 2.0) {
			shiftAngle = 2.0;
		}
	}
}