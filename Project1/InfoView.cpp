#include <glut.h>
#include "InfoView.h"
#include "Define.h"

/*
@brief �n���h���\���p�l���Ƃ��X�R�A�Ƃ�
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
    //�R���ƃ}�l�[
    glBegin(GL_QUADS);
    glVertex2i(Define::WIN_W * 5 / 7, Define::WIN_H * 3 / 4);
    glVertex2i(Define::WIN_W, Define::WIN_H * 3 / 4);
    glVertex2i(Define::WIN_W, Define::WIN_H);
    glVertex2i(Define::WIN_W * 5 / 7, Define::WIN_H);
    glEnd();
    glColor4f(0.000f, 0.00f, 0.30f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(Define::WIN_W * 5 / 7, Define::WIN_H * 7 / 8);
    glVertex2i(Define::WIN_W, Define::WIN_H * 7 / 8);
    glVertex2i(Define::WIN_W, Define::WIN_H);
    glVertex2i(Define::WIN_W * 5 / 7, Define::WIN_H);
    glEnd();
    //�}�b�v
    glBegin(GL_QUADS);
    glVertex2i(0, Define::WIN_H * 3 / 4);
    glVertex2i(Define::WIN_W * 2 / 7, Define::WIN_H * 3 / 4);
    glVertex2i(Define::WIN_W * 2 / 7, Define::WIN_H);
    glVertex2i(0, Define::WIN_H);
    glEnd();
    //���Ԃƃ��x��
    glColor4f(0.400f, 0.40f, 0.40f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(0, Define::WIN_H * 3 / 4);
    glVertex2i(Define::WIN_W * 1 / 7, Define::WIN_H * 3 / 4);
    glVertex2i(Define::WIN_W * 1 / 7, Define::WIN_H);
    glVertex2i(0, Define::WIN_H);
    glEnd();
    glColor4f(0.200f, 0.10f, 0.30f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(0, Define::WIN_H * 7 / 8);
    glVertex2i(Define::WIN_W * 1 / 7, Define::WIN_H * 7 / 8);
    glVertex2i(Define::WIN_W * 1 / 7, Define::WIN_H);
    glVertex2i(0, Define::WIN_H);
    glEnd();
}