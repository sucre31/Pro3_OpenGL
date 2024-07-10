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
	void setLightValid(bool isValid) { lightOn = isValid; }
private:
	GLfloat lightPosition[4]; //光源の位置
	GLfloat spotDirrection[3];//スポットライトを向ける方向
	const GLfloat light_ambient_normal[4] = { 0.09, 0.09, 0.09, 1.0f };    //環境光
	const GLfloat  light_diffuse_normal[4] = { 1.0f, 1.0f, 0.2, 1.0f };      //拡散光
	const GLfloat  light_specular_normal[4] = { 0.8f, 0.8f, 0.8f, 1.0f };     //鏡面光
	const GLfloat light_ambient_off[4] = { 0.00, 0.00, 0.00, 1.0f };    //環境光
	const GLfloat  light_diffuse_off[4] = { 0.0f, 0.0f, 0.0f, 1.0f };      //拡散光
	const GLfloat  light_specular_off[4] = { 0.0f, 0.0f, 0.0f, 1.0f };     //鏡面光
	GLfloat mat0emis[4];
	int lightNumber;		// 何番目のライトを使うか
	double x, y, z;
	double angle;
	bool lightOn;
};

