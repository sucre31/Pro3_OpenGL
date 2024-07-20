#include "Sound.h"
#include <windows.h>
#include <digitalv.h>

// includeが上手くいかないのでここだけグローバル変数を使用する
static MCI_OPEN_PARMS mciOpenParam[8];

Sound::Sound() {
	soundCount = 7;
	mciOpenParam[0].lpstrDeviceType
		= (LPCTSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;  // メディアの種類
	mciOpenParam[0].lpstrElementName = TEXT("Assets/music/FreeBird.wav");;    // ファイル名
	// mciデバイスのオープン
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE |
		MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT,
		(DWORD_PTR)&mciOpenParam[0]);

	mciOpenParam[6].lpstrDeviceType
		= (LPCTSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;  // メディアの種類
	mciOpenParam[6].lpstrElementName = TEXT("Assets/music/Local.wav");;    // ファイル名
	// mciデバイスのオープン
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE |
		MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT,
		(DWORD_PTR)&mciOpenParam[6]);

	mciOpenParam[1].lpstrDeviceType
		= (LPCTSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;  // メディアの種類
	mciOpenParam[1].lpstrElementName = TEXT("Assets/music/engine5.wav");;    // 減速
	// mciデバイスのオープン
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE |
		MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT,
		(DWORD_PTR)&mciOpenParam[1]);

	mciOpenParam[2].lpstrDeviceType
		= (LPCTSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;  // メディアの種類
	mciOpenParam[2].lpstrElementName = TEXT("Assets/music/switch2.wav");;    // ライトスイッチ
	// mciデバイスのオープン
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE |
		MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT,
		(DWORD_PTR)&mciOpenParam[2]);

	mciOpenParam[3].lpstrDeviceType
		= (LPCTSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;  // メディアの種類
	mciOpenParam[3].lpstrElementName = TEXT("Assets/music/idle.wav");;    // アイドル
	// mciデバイスのオープン
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE |
		MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT,
		(DWORD_PTR)&mciOpenParam[3]);

	mciOpenParam[4].lpstrDeviceType
		= (LPCTSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;  // メディアの種類
	mciOpenParam[4].lpstrElementName = TEXT("Assets/music/engine2.wav");;    // 加速
	// mciデバイスのオープン
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE |
		MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT,
		(DWORD_PTR)&mciOpenParam[4]);

	mciOpenParam[5].lpstrDeviceType
		= (LPCTSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;  // メディアの種類
	mciOpenParam[5].lpstrElementName = TEXT("Assets/music/engine3.wav");;    // 走行
	// mciデバイスのオープン
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE |
		MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT,
		(DWORD_PTR)&mciOpenParam[5]);

	mciOpenParam[7].lpstrDeviceType
		= (LPCTSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;  // メディアの種類
	mciOpenParam[7].lpstrElementName = TEXT("Assets/music/Switch.wav");;    // スイッチ
	// mciデバイスのオープン
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE |
		MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT,
		(DWORD_PTR)&mciOpenParam[7]);
}

void Sound::playMainBGM() {
	//現在の場所から再生なので，何度も繰り返して鳴らす時は先に巻き戻す
	mciSendCommand(mciOpenParam[0].wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, 0);
	mciSendCommand(mciOpenParam[0].wDeviceID, MCI_PLAY, 0, 0);
}

void Sound::playSubBGM() {
	//現在の場所から再生なので，何度も繰り返して鳴らす時は先に巻き戻す
	mciSendCommand(mciOpenParam[6].wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, 0);
	mciSendCommand(mciOpenParam[6].wDeviceID, MCI_PLAY, 0, 0);
}


void Sound::playSE1() {
	//現在の場所から再生なので，何度も繰り返して鳴らす時は先に巻き戻す
	mciSendCommand(mciOpenParam[1].wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, 0);
	mciSendCommand(mciOpenParam[1].wDeviceID, MCI_PLAY, 0, 0);
}

void Sound::playSE2() {
	//現在の場所から再生なので，何度も繰り返して鳴らす時は先に巻き戻す
	mciSendCommand(mciOpenParam[2].wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, 0);
	mciSendCommand(mciOpenParam[2].wDeviceID, MCI_PLAY, 0, 0);
}

void Sound::playSE3() {
	//現在の場所から再生なので，何度も繰り返して鳴らす時は先に巻き戻す
	mciSendCommand(mciOpenParam[3].wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, 0);
	mciSendCommand(mciOpenParam[3].wDeviceID, MCI_PLAY, 0, 0);
}

void Sound::playSE4() {
	//現在の場所から再生なので，何度も繰り返して鳴らす時は先に巻き戻す
	mciSendCommand(mciOpenParam[4].wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, 0);
	mciSendCommand(mciOpenParam[4].wDeviceID, MCI_PLAY, 0, 0);
}

void Sound::playSE5() {
	//現在の場所から再生なので，何度も繰り返して鳴らす時は先に巻き戻す
	mciSendCommand(mciOpenParam[5].wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, 0);
	mciSendCommand(mciOpenParam[5].wDeviceID, MCI_PLAY, 0, 0);
}

void Sound::playSE6() {
	//現在の場所から再生なので，何度も繰り返して鳴らす時は先に巻き戻す
	mciSendCommand(mciOpenParam[7].wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, 0);
	mciSendCommand(mciOpenParam[7].wDeviceID, MCI_PLAY, 0, 0);
}

void Sound::pauseMain() {
	mciSendCommand(mciOpenParam[0].wDeviceID, MCI_PAUSE, 0, 0);
}

void Sound::pauseSub() {
	mciSendCommand(mciOpenParam[6].wDeviceID, MCI_PAUSE, 0, 0);
}

void Sound::pauseSE1() {
	mciSendCommand(mciOpenParam[1].wDeviceID, MCI_PAUSE, 0, 0);
}

void Sound::pauseSE2() {
	mciSendCommand(mciOpenParam[2].wDeviceID, MCI_PAUSE, 0, 0);
}

void Sound::pauseSE3() {
	mciSendCommand(mciOpenParam[3].wDeviceID, MCI_PAUSE, 0, 0);
}

void Sound::pauseSE4() {
	mciSendCommand(mciOpenParam[4].wDeviceID, MCI_PAUSE, 0, 0);
}

void Sound::pauseSE5() {
	mciSendCommand(mciOpenParam[5].wDeviceID, MCI_PAUSE, 0, 0);
}

void Sound::pauseSE(int i) {
	if (i < soundCount) {
		mciSendCommand(mciOpenParam[i].wDeviceID, MCI_PAUSE, 0, 0);
	}
}