#include <glut.h>
#include "InfoView.h"
#include "Define.h"

/*
@brief ハンドル表示パネルとかスコアとか
*/
void InfoView::draw() {
    glColor4f(0.301f, 0.12f, 0.19f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(0, Define::WIN_H * 3 / 4);
    glVertex2i(Define::WIN_W, Define::WIN_H * 3 / 4);
    glVertex2i(Define::WIN_W, Define::WIN_H);
    glVertex2i(0, Define::WIN_H);
    glEnd();
    glColor4f(0.000f, 0.00f, 0.00f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(Define::WIN_W * 4 / 5, Define::WIN_H * 3 / 4);
    glVertex2i(Define::WIN_W, Define::WIN_H * 3 / 4);
    glVertex2i(Define::WIN_W, Define::WIN_H);
    glVertex2i(Define::WIN_W * 4 / 5, Define::WIN_H);
    glEnd();
}