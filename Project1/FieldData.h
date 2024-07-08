#pragma once
#include "Plate.h"
class FieldData
{
public:
	FieldData();
	virtual ~FieldData() = default;
	void draw();
	void update();
	void setField(int x, int y, int value) { field[x][y] = value; }
	int getField(int x, int y) { return field[x][y]; }
	void setGridSize(double size) { gridSize = size; }
	static const int fieldSizeX = 20;
	static const int fieldSizeZ = 20;
private:
	Plate plate;
	double gridSize;
	const double brank = 8.0;
	int field[fieldSizeX][fieldSizeZ];				// î’ñ èÓïÒ
	double randValue[fieldSizeX][fieldSizeZ][2];        //Ç†Ç∆Ç≈ÇØÇ∑
	double randValueVel[fieldSizeX][fieldSizeZ][2];
};

