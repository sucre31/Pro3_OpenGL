#pragma once
class Camera
{
public:
	Camera() = default;
	virtual ~Camera() = default;
	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }
	float getTargetX() { return x2; }
	float getTargetY() { return y2; }
	float getTargetZ() { return z2; }
	void setX(float CameraX) { x = CameraX; }
	void setY(float CameraY) { y = CameraY; }
	void setZ(float CameraZ) { z = CameraZ; }
	void setTargetX(float CameraX) { x2 = CameraX; }
	void setTargetY(float CameraY) { y2 = CameraY; }
	void setTargetZ(float CameraZ) { z2 = CameraZ; }
private:
	float x, y, z;
	float x2, y2, z2;
};

