#include <glut.h>
#include "FuelMeter.h"

void FuelMeter::draw() {
    glColor4f(1.0f, 0.56f, 0.3f, 1.0f);
    drawQuadrilateral(1060, 600, 200, 40);
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    drawQuadrilateral(1065, 605, 190 * fuel / fuelMax, 30);
}

void FuelMeter::drawQuadrilateral(int x, int y, double sizeX, double sizeY) {
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + sizeX, y);
    glVertex2i(x + sizeX, y + sizeY);
    glVertex2i(x, y + sizeY);
    glEnd();
}