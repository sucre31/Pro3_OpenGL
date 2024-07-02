#pragma once
#include "Singleton.h"
#include "Key.h"
#include "FieldData.h"
#include "BackGround.h"

class SystemMain final : public Singleton<SystemMain>
{
public:
	SystemMain() = default;
	virtual ~SystemMain() = default;
	void lightInit();
	static void display();			// コールバックするために静的関数にしている
	static void reshape(int, int);
	static void timerFunc(int);		
	static void specialKey(int, int, int);
private:
	Key key;						//キー入力を保持
	FieldData fieldData;
	BackGround backGround;
	int winH, winW;					// ウィンドウサイズを保持
	void view2D();					// 描画を2Dに
	void view3D();					// 描画を3Dに
	void update();					// 毎フレーム(?)行われる処理
	void reshapeFunc(int, int);
	void draw();					// 描画用の処理
	void keyCall(int, int, int);	// キーボードイベントの処理
};

