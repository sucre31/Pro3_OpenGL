#include<stdio.h>
#include <glut.h>
#include "Key.h"

void Key::keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'z':
		keyZON++;
		break;
	case 'x':
		keyXON++;
		break;
	case '\033':
		keyEscON = true;
		break;
	}

}

void Key::keyboardUp(unsigned char key, int x, int y)
{
	switch (key) {
	case 'z':
		keyZON = 0;
		break;
	case 'x':
		keyXON = 0;
		break;
	case '\033':
		keyEscON = false;
		break;
	}
}

void Key::specialKey(int key, int x, int y)
{
	//�L�[���͍͂\���̂Ɉꎞ�ۑ����Ă���
	this->x = x;	//�}�E�Xx
	this->y = y;	//�}�E�Xy

	switch (key) {
	case GLUT_KEY_UP:
		//printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		keyUpON = true;
		break;
	case GLUT_KEY_DOWN:
		//printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		keyDownON = true;
		break;
	case GLUT_KEY_LEFT:
		//printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		keyLeftON = true;
		break;
	case GLUT_KEY_RIGHT:
		//printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		keyRightON = true;
		break;
	}
}

void Key::specialKeyUp(int key, int x, int y)
{
	//�L�[���͍͂\���̂Ɉꎞ�ۑ����Ă���
	this->x = x;	//�}�E�Xx
	this->y = y;	//�}�E�Xy

	switch (key) {
	case GLUT_KEY_UP:
		//printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		keyUpON = false;
		break;
	case GLUT_KEY_DOWN:
		//printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		keyDownON = false;
		break;
	case GLUT_KEY_LEFT:
		//printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		keyLeftON = false;
		break;
	case GLUT_KEY_RIGHT:
		//printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		keyRightON = false;
		break;
	}
}