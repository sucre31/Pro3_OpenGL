#pragma once
class SpeedMeter
{
public:
	SpeedMeter();
	~SpeedMeter() = default;
	void draw();
	void update();
	void setMaxSpeed(double value) { speedMax = value; }
	void setSpeed(double value) { speed = value; }
private:
	double speedRate;	// 針の動きの割合
	double speedMax;
	double speed;
};

