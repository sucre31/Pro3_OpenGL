#pragma once
class HeadLight
{
public:
	void setLightNumber(int num) { lightNumber = num; }
private:
	int lightNumber;		// 何番目のライトを使うか
	double x, y, z;
};

