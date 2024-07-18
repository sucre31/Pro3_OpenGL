#include "HeadLight.h"
#define _USE_MATH_DEFINES
#include <math.h>

HeadLight::HeadLight() {
	lightPosition[0] = 0.0;
	lightPosition[1] = 0.0;
	lightPosition[2] = 0.0;
	lightPosition[3] = 1.0;
	spotDirrection[0] = 3.0 * cos(0);
	spotDirrection[1] = -1.0;
	spotDirrection[2] = 3.0 * sin(0);
}

void HeadLight::setHeadLightPosX(double playerX) {
	x = playerX;
}

void HeadLight::setHeadLightPosY(double playerY) {
	y = playerY;
}

void HeadLight::setHeadLightPosZ(double playerZ) {
	z = playerZ;
}

void HeadLight::draw() {
	// ライトの再設定
	GLfloat matZero[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat0ambi[] = { 0.19225,  0.19225, 0.19225, 1.0 };//銀
	GLfloat mat0diff[] = { 0.50754,  0.50754, 0.50754, 1.0 };
	GLfloat mat0spec[] = { 0.508273,  0.508273, 0.508273, 1.0 };
	GLfloat mat0shine[] = { 51.2 };
	configLight();
	glPushMatrix(); {
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //環境光の反射率を設定
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //拡散光の反射率を設定
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //鏡面光の反射率を設定
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat0emis);
		glTranslatef(lightPosition[0], lightPosition[1] + 0.5, lightPosition[2]);
		glutSolidSphere(0.10, 15, 15);              // 球
	}glPopMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, matZero);
}

void HeadLight::update() {
	//ライト位置の更新
	lightPosition[0] = x - 18.0 * -cos(angle - 180 * (M_PI / 180));
	lightPosition[1] = y + 1.3;
	lightPosition[2] = z - 18.0 * sin(angle - 180 * (M_PI / 180));
	spotDirrection[0] = 3.0 * -cos(angle - 180 * (M_PI / 180));
	spotDirrection[1] = -1.0;
	spotDirrection[2] = 3.0 * sin(angle - 180 * (M_PI / 180));
}

void HeadLight::configLight(){
	switch (lightNumber) {
	case 1:
		//ヘッドライトの配置と設定
		glEnable(GL_LIGHT1);    //1番目の光源を有効にする(8個まで設定可能)
		glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient_normal);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse_normal);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular_normal);
		glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);   //光の一定減衰率
		glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.002);   //光の2次減衰率
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirrection); //スポットライトの向ける方向（デフォルト (0,0,-1.0)）
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 25.0);// スポットライトの絞り（デフォルト 180.0）
		glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.0005);// スポットライトの中心からの減衰の度合い（デフォルト 0）
		break;
	}
	if (!lightOn) {
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient_off);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse_off);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular_off);
		mat0emis[0] = 0.0;
		mat0emis[1] = 0.0;
		mat0emis[2] = 0.0;
	}
	else {
		mat0emis[0] = 0.4;
		mat0emis[1] = 0.4;
		mat0emis[2] = 0.2;
	}
}