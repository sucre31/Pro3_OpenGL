#pragma once
class MapData
{
public:
	MapData() = default;
	virtual ~MapData() = default;
	void draw();
	void update();
	void drawSquare(int x, int y);
	void Circle2DFill(float radius, int x, int y);
	void setPlayerX(int x) { playerX = x; }
	void setPlayerZ(int z) { playerZ = z; }
private:
	const int squareSize = 8;
	const double posX = 200, posY = 550;
	int playerX, playerZ;
};

