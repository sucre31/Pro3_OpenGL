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
	int lampState[amountOfLamp];	//7seg�̕`��֐����̏ォ�珇�ɉ��ʂ̃r�b�g�ɑΉ�
	int lampBState[amountOfLampB];
	int lampTimeState[amountOfLampTime];
};

