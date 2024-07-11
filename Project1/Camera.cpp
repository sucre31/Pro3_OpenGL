#include <glut.h>
#include "Camera.h"


void Camera::setLookAt() {
	gluLookAt(x, y, z, x2, y2 + 2, z2, 0.0, 1.0, 0.0);
}