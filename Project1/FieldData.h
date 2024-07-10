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
	int getFieldGridNum() { return fieldGridNumber; }
	void setGridSize(double size) { gridSize = size; }
	static const int fieldGridNumber = 20;
private:
	int fieldSizeX;
	int fieldSizeZ;
	Plate plate;
	double gridSize;
	const double brank = 8.0;
	int field[fieldGridNumber][fieldGridNumber];				// î’ñ èÓïÒ
	double randValue[fieldGridNumber][fieldGridNumber][2];        //Ç†Ç∆Ç≈ÇØÇ∑
	double randValueVel[fieldGridNumber][fieldGridNumber][2];
};

