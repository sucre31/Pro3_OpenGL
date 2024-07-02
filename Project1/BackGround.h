#pragma once
class BackGround
{
public:
	BackGround() = default;
	virtual ~BackGround() = default;
	void draw();
	void drawSquare(int x, int y);
private:
	const int squareSize = 20;
	const int fieldX1 = 215;
	const int fieldX2 = 425;
	const int fieldY1 = 43;
	const int fieldY2 = 463;
};

