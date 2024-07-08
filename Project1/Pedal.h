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
	int checkKey;		// �ǂ̃L�[�Ńy�_���������� 0:�� 1:��
	bool pedalOn;
	double moveRate;		// �ǂꂾ���y�_���������Ă��邩
	double pedalSpeed;		// �y�_���𓥂ނƂ��̓��쑬�x
	double pedalReturnSpeed;	// �y�_���̗������Ƃ��̓��쑬�x
	const double angle;
	GLfloat matAmbi[4];
	GLfloat matDiff[4];
	GLfloat matSpec[4];
	GLfloat matShine[1];
	double posX, posY, scaleX, scaleY;
};

