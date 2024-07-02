#pragma once
class Key
{
public:
	unsigned char getC() const { return c; }
	int getX() const { return x; }
	int getY() const { return y; }
	void setC(unsigned char c) { this->c = c; }
	void setX(unsigned char x) { this->x = x; }
	void setY(unsigned char y) { this->y = y; }
	void specialKey(int key, int x, int y);
private:
	unsigned char c;
	int x, y;
};

