#pragma once
class SegmentDisplay
{
public:
	SegmentDisplay();
	void draw();
	void draw7Seg(double x, double y, int state);
	void setLampState(int , int);
	void setLampBState(int, int);
	void setLampTimeState(int, int);
private:
	static const int amountOfLamp = 8;
	static const int amountOfLampB = 2;
	static const int amountOfLampTime = 6;
	void drawLamp();
	void setMatOrange();
	void setMatGrey();
	int lampState[amountOfLamp];	//7segの描画関数順の上から順に下位のビットに対応
	int lampBState[amountOfLampB];
	int lampTimeState[amountOfLampTime];
};

