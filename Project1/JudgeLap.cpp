#include "JudgeLap.h"
#include "Sound.h"

void JudgeLap::update() {
	// ü‰ñ”»’è
	int currentPlayerFieldX = player->getFieldX();
	int currentPlayerFieldZ = player->getFieldZ();
	if (field->getFieldData(playerFieldX, playerFieldZ) == 2 && field->getFieldData(currentPlayerFieldX, currentPlayerFieldZ) == 3) { //ˆêüi‚Ş
		lapNumber++;
		Sound::getIns()->playSE8();
	}
	if (field->getFieldData(playerFieldX, playerFieldZ) == 3 && field->getFieldData(currentPlayerFieldX, currentPlayerFieldZ) == 2) { //ˆêü–ß‚·
		lapNumber--;
	}
	playerFieldX = currentPlayerFieldX;
	playerFieldZ = currentPlayerFieldZ;
	player->setLapNumber(lapNumber);
}