#pragma once
class Key
{
public:
	bool getKeyUpON() const { return keyUpON; }
	bool getKeyDownON() const { return keyDownON; }
	bool getKeyLeftON() const { return keyLeftON; }
	bool getKeyRightON() const { return keyRightON; }
	int getX() const { return x; }
	int getY() const { return y; }
	void setC(unsigned char c) { this->c = c; }
	void setX(unsigned char x) { this->x = x; }
	void setY(unsigned char y) { this->y = y; }
	void specialKey(int key, int x, int y);
	void specialKeyUp(int key, int x, int y);
private:
	unsigned char c;
	int x, y;
	bool keyUpON = false;	// 矢印キーの状態フラグ
	bool keyDownON = false;	// 矢印キーの状態フラグ
	bool keyLeftON = false;	// 矢印キーの状態フラグ
	bool keyRightON = false;	// 矢印キーの状態フラグ
};

