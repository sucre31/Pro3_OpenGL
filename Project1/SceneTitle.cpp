#include <stdlib.h>
#include "SceneTitle.h"
#include "SystemMain.h"

SceneTitle::SceneTitle() {
	cursorPos = 0;
	keyPushedDown = false;
	keyPushedUp = false;
}

void SceneTitle::draw() {
	int i;
	SystemMain::getIns()->view2D();
	backGround.draw();

	glViewport(0, 0, SystemMain::getIns()->winW, SystemMain::getIns()->winH); //ビューポートを調整
	SystemMain::getIns()->view3D();
	gluLookAt(0.0, 0.0, -5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix(); {
		glTranslatef(2.0, cursorPos, 0.0);
		glRotated(rota, 0.0, 1.0, 0.0);
		glutSolidTeapot(0.2);
	}glPopMatrix();
	for (i = 0; i < 3; i++) {
		glPushMatrix(); {
			glTranslatef(1.0, 0.0 - i * 0.5, 0.0);
			glScaled(4.0, 1.0, 0.01);
			glutSolidCube(0.3);
		}glPopMatrix();
	}
}

void SceneTitle::update() {
	if (SystemMain::getIns()->key.getKeyZON() == 1) {
		switch (select) {
		case 0:
			SystemMain::getIns()->changeScene(1);
			break;
		case 1:
			break;
		case 2:
			exit(0);
			break;
		}
	}
	if (SystemMain::getIns()->key.getKeyDownON()) {
		if (!keyPushedDown) {
			select += 1;
			keyPushedDown = true;
		}
	}
	else {
		keyPushedDown = false;
	}
	if (SystemMain::getIns()->key.getKeyUpON()) {
		if (!keyPushedUp) {
			select += 2;
			keyPushedUp = true;
		}
	}
	else {
		keyPushedUp = false;
	}
	switch (select) {
	case 0:
		cursorPos = 0.0;
		break;
	case 1:
		cursorPos = -0.5;
		break;
	case 2:
		cursorPos = -1.0;
		break;
	}
	select = select % 3;
	rota += 3.3;
}