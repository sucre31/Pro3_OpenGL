#pragma once
class Key
{
public:
	bool getKeyUpON() const { return keyUpON; }
	bool getKeyDownON() const { return keyDownON; }
	bool getKeyLeftON() const { return keyLeftON; }
	bool getKeyRightON() const { return keyRightON; }
	int getKeyZON() const { return keyZON; }
	int getKeyXON() const { return keyXON; }
	int getKeyEscON() const { return keyEscON; }
	int getX() const { return x; }
	int getY() const { return y; }
	void setC(unsigned char c) { this->c = c; }
	void setX(unsigned char x) { this->x = x; }
	void setY(unsigned char y) { this->y = y; }
	void keyboard(unsigned char key, int x, int y);
	void keyboardUp(unsigned char key, int x, int y);
	void specialKey(int key, int x, int y);
	void specialKeyUp(int key, int x, int y);
private:
	unsigned char c;
	int x, y;
	bool keyUpON = false;	// ���L�[�̏�ԃt���O
	bool keyDownON = false;	// ���L�[�̏�ԃt���O
	bool keyLeftON = false;	// ���L�[�̏�ԃt���O
	bool keyRightON = false;	// ���L�[�̏�ԃt���O
	bool keyZON;	//Z�L�[�̏�ԃt���O
	bool keyEscON;	//�G�X�P�[�v�L�[��
	int keyXON;	//X�L�[�̏�ԃt���O
};

