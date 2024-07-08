#pragma once
#include <glut.h>
class Pedal
{
public:
	Pedal();
	virtual ~Pedal() = default;
	void draw();
	void update();
	void setCheckKey(int number) { checkKey = number; }
	void setX(double setX) { posX = setX; }
	void setY(double setY) { posY = setY; }
	void setScaleX(double setX) { scaleX = setX; }
	void setScaleY(double setY) { scaleY = setY; }
private:
	int checkKey;		// どのキーでペダルが動くか 0:上 1:下
	bool pedalOn;
	double moveRate;		// どれだけペダルが動いているか
	double pedalSpeed;		// ペダルを踏むときの動作速度
	double pedalReturnSpeed;	// ペダルの離したときの動作速度
	const double angle;
	GLfloat matAmbi[4];
	GLfloat matDiff[4];
	GLfloat matSpec[4];
	GLfloat matShine[1];
	double posX, posY, scaleX, scaleY;
};

