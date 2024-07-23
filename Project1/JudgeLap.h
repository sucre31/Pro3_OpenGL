#pragma once
#include "Player.h"
#include "FieldManipulator.h"
class JudgeLap
{
public:
	JudgeLap() { lapNumber = 0; }
	void setPlayerIns(Player* playerIns) { player = playerIns; }
	void setFieldIns(FieldManipulator* fieldIns) { field = fieldIns; }
	void update();
private:
	Player* player;
	FieldManipulator* field;
	int playerFieldX;
	int playerFieldZ;
	int lapNumber;
};

