#include <glut.h>
#include "BackGround.h"
#include "Define.h"

void BackGround::draw() {   //背景の描画
    // 市松模様
    int i, j;
    int loopNum = 33;       //縦・横のマスの数
    int count = 0;
    glColor4f(0.3f, 0.0f, 0.5f, 1.0f);
    for (i = 0; i < loopNum; i++) {
        for (j = 0; j < loopNum; j++) {
            if (count % 2 == 0) {       //2回に一回四角形を描画
                drawSquare(i * squareSize, j * squareSize);
            }
            count++;
        }
        if (loopNum % 2 == 0) {
            count++;//これで市松模様になる
        }
    }
    //フィールド部分
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(fieldX1, fieldY1);
    glVertex2i(fieldX2, fieldY1);
    glVertex2i(fieldX2, fieldY2);
    glVertex2i(fieldX1, fieldY2);
    glEnd();
}

/*
@brief 正方形を描画するための関数
@param x 位置x
@param y 位置y
*/
void BackGround::drawSquare(int x, int y) {
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + squareSize, y);
    glVertex2i(x + squareSize, y + squareSize);
    glVertex2i(x, y + squareSize);
    glEnd();
}