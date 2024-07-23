#pragma once
class SegmentDisplay
{
public:
	SegmentDisplay();
	void draw();
	void draw7Seg(double x, double y, int state, int color);
	void setLampState(int , int);
	void setLampBState(int, int);
	void setLampTimeState(int, int);
	void setLampCharAState(int, int);
	void setLampCharBState(int, int);
	void setLampCharCState(int, int);
private:
	static const int amountOfLamp = 8;
	static const int amountOfLampB = 2;
	static const int amountOfLampTime = 6;
	static const int amountOfLampCharA = 6;
	static const int amountOfLampCharB = 4;
	static const int amountOfLampCharC = 4;
	void drawLamp();
	void setMatOrange();
	void setMatGrey();
	void setMatGreen();
	void setMatYellow();
	void setMatBlue();
	void setMaterial(int);
	int lampState[amountOfLamp];	//7seg‚Ì•`‰æŠÖ”‡‚Ìã‚©‚ç‡‚É‰ºˆÊ‚Ìƒrƒbƒg‚É‘Î‰
	int lampBState[amountOfLampB];
	int lampTimeState[amountOfLampTime];
	int lampCharAState[amountOfLampCharA];
	int lampCharBState[amountOfLampCharB];
	int lampCharCState[amountOfLampCharC];
};

