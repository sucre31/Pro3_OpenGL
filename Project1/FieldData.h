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
	int field[fieldSizeX][fieldSizeZ];				// 盤面情報
	double randValue[fieldSizeX][fieldSizeZ][2];        //あとでけす
	double randValueVel[fieldSizeX][fieldSizeZ][2];
};

