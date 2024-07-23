#pragma once
class BackGround
{
public:
	BackGround() = default;
	virtual ~BackGround() = default;
	void draw();
	void drawSquare(int x, int y);
	void Circle2DFill(float radius, int x, int y);
private:
	const int squareSize = 40;
	const int fieldX1 = 215 * 2;
	const int fieldX2 = 425 * 2;
	const int fieldY1 = 43 * 2;
	const int fieldY2 = 463 * 2;
};