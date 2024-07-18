#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "MapData.h"
#include "Define.h"
#include "SystemMain.h"

void MapData::draw() {   //背景の描画
    // カーナビ
    int i, j;
    double drawSquareSize = (squareSize * fieldRate);
    int loopNum = SystemMain::getIns()->game.field.getFieldGridNumber();       //縦・横のマスの数
    glColor4f(0.8f, 0.0f, 0.5f, 1.0f);
    for (i = 0; i < loopNum; i++) {
        for (j = 0; j < loopNum; j++) {
            glColor4f(0.4f, 0.4f, 0.4f, 1.0f);
            switch (SystemMain::getIns()->game.field.checkFieldValue(i, j)) {
            case 0:
                glColor4f(0.1f, 0.1f, 0.2f, 1.0f);
                break;
            case 1:
                //glColor4f(0.7f, 0.0f, 0.0f, 1.0f);
                break;
            case 2:
                //glColor4f(0.7f, 0.7f, 0.0f, 1.0f);
                break;
            case 3:
                //glColor4f(0.0f, 0.0f, 0.7f, 1.0f);
                break;
            }
            drawSquare((loopNum - i) * drawSquareSize + posX, (loopNum - j) * drawSquareSize + posY);
        }
    }
    for (i = 0; i < loopNum; i++) {
        for (j = 0; j < loopNum; j++) {
            if (i == playerX && j == playerZ) {
                glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
                Circle2DFill(
                    4.0 * fieldRate,
                    (loopNum - i) * drawSquareSize + posX - playerRemainderX * fieldRate + drawSquareSize / 2 + drawSquareSize,
                    (loopNum - j) * drawSquareSize + posY - playerRemainderZ * fieldRate + drawSquareSize / 2 + drawSquareSize);
            }
        }
    }
}

void MapData::update() {
    
}

/*
@brief 正方形を描画するための関数
@param x 位置x
@param y 位置y
*/
void MapData::drawSquare(int x, int y) {
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + squareSize, y);
    glVertex2i(x + squareSize, y + squareSize);
    glVertex2i(x, y + squareSize);
    glEnd();
}

void MapData::Circle2DFill(float radius, int x, int y)
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