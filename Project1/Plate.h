#pragma once
class Plate
{
public:
	Plate() = default;
	virtual ~Plate() = default;
	void draw();
	void drawFloor(double, double, double, double);
};

