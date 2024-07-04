#pragma once
class FieldData
{
public:
	FieldData();
	virtual ~FieldData() = default;
	void draw();
	void setField(int x, int y, int value) { field[x][y] = value; }
	int getField(int x, int y) { return field[x][y]; }
private:
	const double brank = 8.0;
	int field[8][16];				// ”Õ–Êî•ñ
	double randValue[8][16][2];        //‚ ‚Æ‚Å‚¯‚·
	double randValueVel[8][16][2];
};

