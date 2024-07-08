#include "Pedal.h"
#include "SystemMain.h"

Pedal::Pedal() : angle(40) {
	pedalOn = false;
	moveRate = 0.0;
	pedalSpeed = 0.3;
	pedalReturnSpeed = 0.5;
	matAmbi[0] = 0.19225;//‹â
	matAmbi[1] = 0.19225;
	matAmbi[2] = 0.19225;
	matAmbi[3] = 1.0;
	matDiff[0] = 0.50754;
	matDiff[1] = 0.50754;
	matDiff[2] = 0.50754;
	matDiff[3] = 1.0 ;
	matSpec[0] = 0.508273;
	matSpec[1] = 0.508273;
	matSpec[2] = 0.508273;
	matSpec[3] = 1.0;
	matShine[0] = 51.2;
}

void Pedal::draw() {
	// •`‰æ
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbi); //ŠÂ‹«Œõ‚Ì”½ŽË—¦‚ðÝ’è
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiff); //ŠgŽUŒõ‚Ì”½ŽË—¦‚ðÝ’è
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec); //‹¾–ÊŒõ‚Ì”½ŽË—¦‚ðÝ’è
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShine);
	glPushMatrix(); {
		glTranslatef(posX, posY, 0.0);
		glRotatef(angle * moveRate + 50, 1.0, 0.0, 0.0);
		glScalef(scaleX, scaleY, 0.1);
		glPushMatrix(); {
			glutSolidCube(1.0);
		}glPopMatrix();
	}glPopMatrix();
}

void Pedal::update() {
	switch (checkKey) {
	case 0:
		if (SystemMain::getIns()->key.getKeyUpON()) {
			moveRate += pedalSpeed;
		}
		else {
			moveRate -= pedalReturnSpeed;
		}
		break;
	case 1:
		if (SystemMain::getIns()->key.getKeyDownON()) {
			moveRate += pedalSpeed;
		}
		else {
			moveRate -= pedalReturnSpeed;
		}
		break;
	}
	if (moveRate < 0.0) {
		moveRate = 0.0;
	}
	if (moveRate > 1.0) {
		moveRate = 1.0;
	}
}
