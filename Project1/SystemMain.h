#pragma once
#include "Singleton.h"
#include "SceneGame.h"
#include "SceneTitle.h"
#include "Key.h"

class SystemMain final : public Singleton<SystemMain>
{
public:
	SceneTitle title;
	SceneGame game;
	Key key;						//キー入力を保持
	int winH, winW;					// ウィンドウサイズを保持
	int SceneNum;
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
	void view2D();					// 描画を2Dに
	void view3D();					// 描画を3Dに
	void view3DForUI();					// 描画を3Dに
	void changeScene(int);
private:
	void reshapeFunc(int, int);
	void draw();					// 描画用の処理
	void update();					// 毎フレーム(?)行われる処理
	void keyboardCall(unsigned char, int, int);	// キーボードイベントの処理
	void keyboardUpCall(unsigned char, int, int);	// キーボードイベントの処理
	void keyCall(int, int, int);	// キーボードイベントの処理
	void keyCallUp(int, int, int);	// キーボードイベントの処理

};

