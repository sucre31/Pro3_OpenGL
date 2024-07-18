#pragma once
class SegmentDisplay
{
public:
	SegmentDisplay();
	void draw();
	void draw7Seg(double x, double y, int state);
	void setLampState(int , int);
private:
	static const int amountOfLamp = 8;
	void drawLamp();
	void setMatOrange();
	void setMatGrey();
	int lampState[amountOfLamp];	//7seg‚Ì•`‰æŠÖ”‡‚Ìã‚©‚ç‡‚É‰ºˆÊ‚Ìƒrƒbƒg‚É‘Î‰
};

