#include <glut.h>
#include "InfoView.h"

/*
@brief �n���h���\���p�l���Ƃ��X�R�A�Ƃ�
*/
void InfoView::draw() {
    glColor4f(0.1f, 0.2f, 0.2f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(0, 720);
    glVertex2i(1280, 720);
    glVertex2i(1280, 960);
    glVertex2i(0, 960);
    glEnd();
}