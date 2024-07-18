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
	// ���C�g�̍Đݒ�
	GLfloat matZero[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat0ambi[] = { 0.19225,  0.19225, 0.19225, 1.0 };//��
	GLfloat mat0diff[] = { 0.50754,  0.50754, 0.50754, 1.0 };
	GLfloat mat0spec[] = { 0.508273,  0.508273, 0.508273, 1.0 };
	GLfloat mat0shine[] = { 51.2 };
	configLight();
	glPushMatrix(); {
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //�����̔��˗���ݒ�
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //�g�U���̔��˗���ݒ�
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //���ʌ��̔��˗���ݒ�
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat0emis);
		glTranslatef(lightPosition[0], lightPosition[1] + 0.5, lightPosition[2]);
		glutSolidSphere(0.10, 15, 15);              // ��
	}glPopMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, matZero);
}

void HeadLight::update() {
	//���C�g�ʒu�̍X�V
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
		//�w�b�h���C�g�̔z�u�Ɛݒ�
		glEnable(GL_LIGHT1);    //1�Ԗڂ̌�����L���ɂ���(8�܂Őݒ�\)
		glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient_normal);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse_normal);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular_normal);
		glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);   //���̈�茸����
		glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.002);   //����2��������
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirrection); //�X�|�b�g���C�g�̌���������i�f�t�H���g (0,0,-1.0)�j
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 25.0);// �X�|�b�g���C�g�̍i��i�f�t�H���g 180.0�j
		glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.0005);// �X�|�b�g���C�g�̒��S����̌����̓x�����i�f�t�H���g 0�j
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