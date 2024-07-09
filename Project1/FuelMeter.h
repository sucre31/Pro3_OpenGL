#pragma once
class FuelMeter
{
public:
	FuelMeter() = default;
	virtual ~FuelMeter() = default;
	void draw();
	void drawQuadrilateral(int x, int y, double sizeX, double sizeY);
	void setFuel(double value) { fuel = value; }
	void setFuelMax(double value) { fuelMax = value; }
private:
	double fuel, fuelMax;
};

