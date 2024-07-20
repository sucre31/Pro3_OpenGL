#pragma once
#include "Singleton.h"

/*
‘S‘Ì“I‚É“K“–‚È•”•ª‚ª‘½‚¢
*/
class Sound final : public Singleton<Sound>
{
public:
	Sound();
	void playMainBGM();
	void playSubBGM();
	void playSE1();
	void playSE2();
	void playSE3();
	void playSE4();
	void playSE5();
	void playSE6();
	void pauseMain();
	void pauseSub();
	void pauseSE1();
	void pauseSE2();
	void pauseSE3();
	void pauseSE4();
	void pauseSE5();
	void pauseSE(int);
private:
	int soundCount; //SE‚Ì”
};

