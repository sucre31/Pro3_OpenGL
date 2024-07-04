#pragma once

class Player
{
public:
	Player();
	virtual ~Player() = default;
	void update();
	void draw();
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
private:
	const int HandelRate = 130;		//見かけ上のハンドルの回転速度
	double accel;			// アクセル(加速度)
	double speed;			// 速さ
	double speedMax;		// 最大速度
	double handling;		// ハンドル回転スピード
	double x, y, z;
	double angleY;			// Y軸の回転量(ラジアン)
	double handleAngle;		// ハンドルの回転量
	double handleAngleMax;	// ハンドルの最大回転角
};

