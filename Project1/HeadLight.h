#pragma once
#include <glut.h>
class HeadLight
{
public:
	HeadLight();
	virtual ~HeadLight() = default;
	void draw();
	void update();
	void setHeadLightPosX(double playerX);
	void setHeadLightPosY(double playerY);
	void setHeadLightPosZ(double playerZ);
	void setAngle(double playerAngle) { angle = playerAngle; }
	void setLightNumber(int num) { lightNumber = num; }
	void configLight();
private:
	GLfloat lightPosition[4]; //�����̈ʒu
	GLfloat spotDirrection[3];//�X�|�b�g���C�g�����������
	const GLfloat light_ambient_normal[4] = { 0.09, 0.09, 0.09, 1.0f };    //����
	const GLfloat  light_diffuse_normal[4] = { 1.0f, 1.0f, 0.8f, 1.0f };      //�g�U��
	const GLfloat  light_specular_normal[4] = { 0.8f, 0.8f, 0.8f, 1.0f };     //���ʌ�
	int lightNumber;		// ���Ԗڂ̃��C�g���g����
	double x, y, z;
	double angle;
};

