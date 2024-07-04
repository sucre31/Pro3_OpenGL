#pragma once
class ShiftLever
{
public:
	ShiftLever() : shiftAngle(2.0) {};
	virtual ~ShiftLever() = default;
	void draw();
	void update();
private:
	double shiftMove;	//シフトレバーの動きをアニメーションするための変数
	double shiftAngle;
};

