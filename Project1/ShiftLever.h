#pragma once
class ShiftLever
{
public:
	ShiftLever() : shiftAngle(2.0) {};
	virtual ~ShiftLever() = default;
	void draw();
	void update();
private:
	double shiftMove;	//�V�t�g���o�[�̓������A�j���[�V�������邽�߂̕ϐ�
	double shiftAngle;
};

