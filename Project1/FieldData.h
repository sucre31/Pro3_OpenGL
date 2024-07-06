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
	void setGridSize(double size) { GridSize = size; }
	static const int fieldSizeX = 30;
	static const int fieldSizeZ = 30;
private:
	Plate plate;
	double GridSize;
	const double brank = 8.0;
	int field[fieldSizeX][fieldSizeZ];				// î’ñ èÓïÒ
	double randValue[fieldSizeX][fieldSizeZ][2];        //Ç†Ç∆Ç≈ÇØÇ∑
	double randValueVel[fieldSizeX][fieldSizeZ][2];
};

