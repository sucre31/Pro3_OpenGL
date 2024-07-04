#pragma once
#include "Singleton.h"
#include "Key.h"
#include "FieldData.h"
#include "BackGround.h"
#include "Player.h"
#include "Camera.h"
#include "Plate.h"
#include "InfoView.h"
#include "ShiftLever.h"

class SystemMain final : public Singleton<SystemMain>
{
public:
	Key key;						//キー入力を保持
	FieldData fieldData;			// 各インスタンスの所持
	BackGround backGround;
	Player player;
	Camera camera;
	Plate plate;
	InfoView info;
	ShiftLever shiftLever;
	SystemMain() = default;
	virtual ~SystemMain() = default;
	void lightInit();
	static void display();			// コールバックするために静的関数にしている
	static void reshape(int, int);
	static void timerFunc(int);		
	static void specialKey(int, int, int);
	static void specialKeyUp(int, int, int);
private:
	//float CamaraX, CameraY, CameraZ;	// クラスにした方がいいかも した
	int winH, winW;					// ウィンドウサイズを保持
	void view2D();					// 描画を2Dに
	void view3D();					// 描画を3Dに
	void update();					// 毎フレーム(?)行われる処理
	void reshapeFunc(int, int);
	void draw();					// 描画用の処理
	void keyCall(int, int, int);	// キーボードイベントの処理
	void keyCallUp(int, int, int);	// キーボードイベントの処理
};

