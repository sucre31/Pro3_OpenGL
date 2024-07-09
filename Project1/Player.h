#pragma once

#include "ShiftLever.h"
#include "HeadLight.h"
#include "Pedal.h"
#include "MapData.h"
#include "FuelMeter.h"

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
	void setX(double xIn) { x = xIn; }
	void setY(double yIn) { y = yIn; }
	void setZ(double zIn) { z = zIn; }
	void setDefX(double xIn) { defX = xIn; }
	void setDefY(double yIn) { defY = yIn; }
	void setDefZ(double zIn) { defZ = zIn; }
private:
	ShiftLever shiftLever;
	HeadLight headLight;
	Pedal pedalAccel;
	Pedal pedalBrake;
	MapData carNavi;
	FuelMeter fuelMeter;
	const int HandelRate = 140;		//見かけ上のハンドルの回転速度
	int shift;				// シフトレバーの状態 0:ドライブ, 1:リバース, 2:ニュートラル
	int FieldX, FieldZ;		// グリッド座標変換
	double accel;			// アクセル(加速度)
	double brake;			// ブレーキ(加速度)
	double speed;			// 速さ
	double speedMax;		// 最大速度
	double handling;		// ハンドル回転スピード
	double x, y, z;			// 位置
	double defX, defY, defZ;// 初期位置
	double velY;			// Y方向の速度
	double angleY;			// Y軸の回転量(ラジアン)
	double handleAngle;		// ハンドルの回転量
	double handleAngleMax;	// ハンドルの最大回転角
	double fuel, fuelMax;
	void drawHandle();
	void drawSpeed();
};

