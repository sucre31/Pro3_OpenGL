#include "JudgeLap.h"
#include "Sound.h"

void JudgeLap::update() {
	// ���񔻒�
	int currentPlayerFieldX = player->getFieldX();
	int currentPlayerFieldZ = player->getFieldZ();
	if (field->getFieldData(playerFieldX, playerFieldZ) == 2 && field->getFieldData(currentPlayerFieldX, currentPlayerFieldZ) == 3) { //����i��
		lapNumber++;
		Sound::getIns()->playSE8();
	}
	if (field->getFieldData(playerFieldX, playerFieldZ) == 3 && field->getFieldData(currentPlayerFieldX, currentPlayerFieldZ) == 2) { //����߂�
		lapNumber--;
	}
	playerFieldX = currentPlayerFieldX;
	playerFieldZ = currentPlayerFieldZ;
	player->setLapNumber(lapNumber);
}