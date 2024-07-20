#include <windows.h>
#include <stdlib.h>
#include "SceneTitle.h"
#include "SystemMain.h"
#include "Texture.h"
#include "Sound.h"

SceneTitle::SceneTitle() {
	cursorPos = 0;
	keyPushedDown = false;
	keyPushedUp = false;
	Sound::getIns()->playSubBGM();
}

void SceneTitle::draw() {
	int i;
	SystemMain::getIns()->view2D();
	backGround.draw();

	glViewport(0, 0, SystemMain::getIns()->winW, SystemMain::getIns()->winH); //ビューポートを調整
	SystemMain::getIns()->view3DForUI();
	gluLookAt(0.0, 0.0, -5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	GLfloat mat0ambi[] = { 0.329412,  0.223529, 0.027451, 1.0 };//真鍮
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //環境光の反射率を設定
	GLfloat mat0diff[] = { 0.780392,  0.568627, 0.113725, 1.0 };//真鍮
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //拡散光の反射率を設定
	GLfloat mat0spec[] = { 0.992157,  0.941176, 0.807843, 1.0 };//真鍮
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //鏡面光の反射率を設定
	GLfloat mat0shine[] = { 27.89743616 };//真鍮
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
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
	
	// 文字列の描画
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRasterPos3f(-0.8f, -0.015f, -3.0f);
	const char* strA = "MAIN GAME";
	while (*strA) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *strA);
		++strA;
	}
	glRasterPos3f(-0.8f, -0.315f, -3.0f);
	const char* strB = "OPTION";
	while (*strB) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *strB);
		++strB;
	}
	glRasterPos3f(-0.8f, -0.615f, -3.0f);
	const char* strC = "QUIT";
	while (*strC) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *strC);
		++strC;
	}
}

void SceneTitle::update() {
	if (SystemMain::getIns()->key.getKeyZON() == 1) {
		switch (select) {
		case 0:
			SystemMain::getIns()->changeScene(1);
			Sound::getIns()->pauseSub();
			Sound::getIns()->playMainBGM();
			break;
		case 1:
			Texture::getIns()->setResolution(1);
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
			Sound::getIns()->playSE6();
		}
	}
	else {
		keyPushedDown = false;
	}
	if (SystemMain::getIns()->key.getKeyUpON()) {
		if (!keyPushedUp) {
			select += 2;
			keyPushedUp = true;
			Sound::getIns()->playSE6();
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