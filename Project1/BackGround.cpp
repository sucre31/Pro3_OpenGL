#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "BackGround.h"
#include "Define.h"

void BackGround::draw() {   //�w�i�̕`��
    // �s���͗l
    int i, j;
    int loopNum = 33;       //�c�E���̃}�X�̐�
    int count = 0;
    glColor4f(0.3f, 0.0f, 0.5f, 1.0f);
    for (i = 0; i < loopNum; i++) {
        for (j = 0; j < loopNum; j++) {
            if (count % 2 == 0) {       //2��Ɉ��l�p�`��`��
                drawSquare(i * squareSize, j * squareSize);
            }
            count++;
        }
        if (loopNum % 2 == 0) {
            count++;//����Ŏs���͗l�ɂȂ�
        }
    }
    //�t�B�[���h����
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(fieldX1, fieldY1);
    glVertex2i(fieldX2, fieldY1);
    glVertex2i(fieldX2, fieldY2);
    glVertex2i(fieldX1, fieldY2);
    glEnd();

    glColor4f(1.0f, 0.5f, 0.25f, 1.0f);  //�~
    Circle2DFill(200, Define::WIN_W / 2, Define::WIN_H / 2);
}

/*
@brief �����`��`�悷�邽�߂̊֐�
@param x �ʒux
@param y �ʒuy
*/
void BackGround::drawSquare(int x, int y) {
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + squareSize, y);
    glVertex2i(x + squareSize, y + squareSize);
    glVertex2i(x, y + squareSize);
    glEnd();
}

void BackGround::Circle2DFill(float radius, int x, int y)
{
    for (float th1 = 0.0; th1 <= 360.0; th1 = th1 + 1.0)
    {
        float th2 = th1 + 10.0;
        float th1_rad = th1 / 180.0 * M_PI;
        float th2_rad = th2 / 180.0 * M_PI;

        float x1 = radius * cos(th1_rad);
        float y1 = radius * sin(th1_rad);
        float x2 = radius * cos(th2_rad);
        float y2 = radius * sin(th2_rad);

        glBegin(GL_TRIANGLES);
        glVertex2f(x, y);
        glVertex2f(x1 + x, y1 + y);
        glVertex2f(x2 + x, y2 + y);
        glEnd();
    }
}