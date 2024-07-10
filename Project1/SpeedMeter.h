#pragma once
class SpeedMeter
{
public:
	SpeedMeter() = default;
	~SpeedMeter() = default;
	void draw();
	void setMaxSpeed(double value) { speedMax = value; }
	void setSpeed(double value) { speed = value; }
private:
	double speedMax;
	double speed;
};

