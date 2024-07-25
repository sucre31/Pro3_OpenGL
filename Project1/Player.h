#pragma once

#include "ShiftLever.h"
#include "HeadLight.h"
#include "Pedal.h"
#include "MapData.h"
#include "FuelMeter.h"
#include "SpeedMeter.h"
#include "Plate.h"
#include "SegmentDisplay.h"

class Player
{
public:
	Player();
	virtual ~Player() = default;
	void update();
	void draw();
	void drawInfo();	// インタフェース側の処理をまとめる
	void drawInfo2D();
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
	int getFieldX() { return FieldX; }
	int getFieldZ() { return FieldZ; }
	void setX(double xIn) { x = xIn; }
	void setY(double yIn) { y = yIn; }
	void setZ(double zIn) { z = zIn; }
	void setDefX(double xIn) { defX = xIn; }
	void setDefY(double yIn) { defY = yIn; }
	void setDefZ(double zIn) { defZ = zIn; }
	void setLapNumber(int Num) { lapNumber = Num; }
	bool isFuelRemaining() { return (fuel > 0); };
	void setTimer() { timerStart = glutGet(GLUT_ELAPSED_TIME); }
	void setMapSize() { carNavi.setSquareSize((20 / fieldNumber)); }
	double fieldNumber;	// マップに渡すだけ
private:
	ShiftLever shiftLever;
	HeadLight headLight;
	Pedal pedalAccel;
	Pedal pedalBrake;
	MapData carNavi;
	FuelMeter fuelMeter;
	SpeedMeter speedMeter;
	Plate plate;
	SegmentDisplay segment;
	double timer;			//経過時間を保持
	const int HandelRate = 140;		//見かけ上のハンドルの回転速度
	int shift;				// シフトレバーの状態 0:ドライブ, 1:リバース, 2:ニュートラル
	int FieldX, FieldZ;		// グリッド座標変換
	bool lightSwitch;		// ヘッドライトをつけるか
	bool lightChanged;		// ほんとはキー入力側で対応すべき
	bool inTheWall; //あとでけす
	bool soundChange;
	double power;			// 電力
	double accel;			// アクセル(加速度)
	double brake;			// ブレーキ(加速度)
	double speed;			// 速さ
	double speedMax;		// 最大速度
	double handling;		// ハンドル回転スピード
	double x, y, z;			// 位置
	double collisionX1, collisionX2, collisionX3, collisionX4;
	double collisionZ1, collisionZ2, collisionZ3, collisionZ4;
	double defX, defY, defZ;// 初期位置
	double velY;			// Y方向の速度
	double angleY;			// Y軸の回転量(ラジアン)
	double handleAngle;		// ハンドルの回転量
	double handleAngleMax;	// ハンドルの最大回転角
	double bodyAngle;		// 車体の揺れ
	double fuel, fuelMax;
	double timerStart;
	double carLengthX;		// 車の幅
	double carLengthX2;		// 車の幅
	double carLengthZ;		// 車の長さ
	int money;				// 所持金
	int lapNumber;
	void drawHandle();
	bool brakeValid;		// ブレーキ踏んでるかs
};
