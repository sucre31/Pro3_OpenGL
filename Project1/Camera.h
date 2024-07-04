#pragma once
class Camera
{
public:
	Camera() = default;
	virtual ~Camera() = default;
	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }
	void setX(float CameraX) { x = CameraX; }
	void setY(float CameraY) { y = CameraY; }
	void setZ(float CameraZ) { z = CameraZ; }
private:
	float x, y, z;
};

