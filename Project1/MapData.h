#pragma once
class MapData
{
public:
	MapData() = default;
	virtual ~MapData() = default;
	void draw();
	void update();
	void drawSquare(int x, int y);
	void setSquareSize(double rate) { fieldRate = rate; }
	void Circle2DFill(float radius, int x, int y);
	void setPlayerX(int x) { playerX = x; }
	void setPlayerZ(int z) { playerZ = z; }
	void setPlayerPosX(double x) { playerRemainderX = x; }
	void setPlayerPosZ(double z) { playerRemainderZ = z; }
private:
	const double squareSize = 8;
	double fieldRate;
	const double posX = 190, posY = 545;
	int playerX, playerZ;
	double playerRemainderX, playerRemainderZ;	//ƒOƒŠƒbƒh‚É’¼‚·‚Æ‚«‚Ì‚ ‚Ü‚è
};

