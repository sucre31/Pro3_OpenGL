#include<stdio.h>
#include <glut.h>
#include "Key.h"

void Key::specialKey(int key, int x, int y)
{
	//キー入力は構造体に一時保存しておく
	this->x = x;	//マウスx
	this->y = y;	//マウスy

	switch (key) {
	case GLUT_KEY_UP:
		//printf("(%3d,%3d)で[↑]が押されました\n", x, y);
		keyUpON = true;
		break;
	case GLUT_KEY_DOWN:
		//printf("(%3d,%3d)で[↓]が押されました\n", x, y);
		keyDownON = true;
		break;
	case GLUT_KEY_LEFT:
		//printf("(%3d,%3d)で[←]が押されました\n", x, y);
		keyLeftON = true;
		break;
	case GLUT_KEY_RIGHT:
		//printf("(%3d,%3d)で[→]が押されました\n", x, y);
		keyRightON = true;
		break;
	}
}

void Key::specialKeyUp(int key, int x, int y)
{
	//キー入力は構造体に一時保存しておく
	this->x = x;	//マウスx
	this->y = y;	//マウスy

	switch (key) {
	case GLUT_KEY_UP:
		//printf("(%3d,%3d)で[↑]が離されました\n", x, y);
		keyUpON = false;
		break;
	case GLUT_KEY_DOWN:
		//printf("(%3d,%3d)で[↓]が離されました\n", x, y);
		keyDownON = false;
		break;
	case GLUT_KEY_LEFT:
		//printf("(%3d,%3d)で[←]が離されました\n", x, y);
		keyLeftON = false;
		break;
	case GLUT_KEY_RIGHT:
		//printf("(%3d,%3d)で[→]が離されました\n", x, y);
		keyRightON = false;
		break;
	}
}