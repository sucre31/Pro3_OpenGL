#pragma once
#include "Singleton.h"
#include "Key.h"
#include "FieldManipulator.h"
#include "MapData.h"
#include "Player.h"
#include "Camera.h"
#include "InfoView.h"
#include "ShiftLever.h"

class SystemMain final : public Singleton<SystemMain>
{
public:
	Key key;						//キー入力を保持
	MapData backGround;				// 各インスタンスの所持
	FieldManipulator field;
	Player player;
	Camera camera;
	InfoView info;
	SystemMain();
	virtual ~SystemMain() = default;
	void lightInit();
	void textureInit();
	static void display();			// コールバックするために静的関数にしている
	static void reshape(int, int);
	static void timerFunc(int);		
	static void keyboard(unsigned char, int, int);
	static void keyboardUp(unsigned char, int, int);
	static void specialKey(int, int, int);
	static void specialKeyUp(int, int, int);
private:
	int winH, winW;					// ウィンドウサイズを保持
	void view2D();					// 描画を2Dに
	void view3D();					// 描画を3Dに
	void reshapeFunc(int, int);
	void draw();					// 描画用の処理
	void update();					// 毎フレーム(?)行われる処理
	void keyboardCall(unsigned char, int, int);	// キーボードイベントの処理
	void keyboardUpCall(unsigned char, int, int);	// キーボードイベントの処理
	void keyCall(int, int, int);	// キーボードイベントの処理
	void keyCallUp(int, int, int);	// キーボードイベントの処理
};

