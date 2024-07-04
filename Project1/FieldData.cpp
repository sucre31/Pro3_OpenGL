#include <time.h>
#include <stdlib.h>
#include <glut.h>
#include "FieldData.h"
#include "SystemMain.h"

FieldData::FieldData() {
	int i, j;
    srand((unsigned int)time(NULL));        // 盤面にデータをランダムで設置
	for (i = 0; i < 8; i++) {               // 盤面の初期化
		for (j = 0; j < 16; j++) {
            if (j >= 8) {
                field[i][j] = 0;
            }
            else {
                field[i][j] = (rand() % 4);
            }
            randValue[i][j][0] = 0;
            randValue[i][j][1] = 0;
            randValueVel[i][j][1] = 0;
            randValueVel[i][j][1] = 0;
		}
	}
}

void FieldData::draw() {
    int i, j;
    int tmpX, tmpY;
    static int maxVel = 0.04;
    static const GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    static const GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    static const GLfloat yellow[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    static const GLfloat blue[] = { 0.0f, 0.0f, 1.0f, 1.0f };
    /*それぞれの盤面の状態を受け取り描画*/
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 16; j++) {
            switch (field[i][j]) {
            case 0:
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
                break;
            case 1://赤カプセル
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
                break;
            case 2://黄カプセル
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, yellow);
                break;
            case 3://青カプセル
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
                break;
            default:
                break;
            }
            glPushMatrix(); {
                //図形の色 (赤)
                static const GLfloat red[] = { 0.8, 0.2, 0.2, 1.0 };
                randValueVel[i][j][0] += 0.0004 * ((rand() % 11) - 5);
                randValueVel[i][j][1] += 0.0004 * ((rand() % 11) - 5);
                randValue[i][j][0] += randValueVel[i][j][0];
                randValue[i][j][1] += randValueVel[i][j][1];
                if (randValueVel[i][j][0] > maxVel) {
                    randValueVel[i][j][0] = maxVel;
                }
                if (randValueVel[i][j][1] > maxVel) {
                    randValueVel[i][j][1] = maxVel;
                }
                if (randValueVel[i][j][0] < -maxVel) {
                    randValueVel[i][j][0] = -maxVel;
                }
                if (randValueVel[i][j][1] < -maxVel) {
                    randValueVel[i][j][1] = -maxVel;
                }
                if (randValue[i][j][0] > 0.2) {
                    randValue[i][j][0] = 0.2;
                }
                if (randValue[i][j][1] > 0.2) {
                    randValue[i][j][1] = 0.2;
                }
                if (randValue[i][j][0] < -0.2) {
                    randValue[i][j][0] = -0.2;
                }
                if (randValue[i][j][1] < -0.2) {
                    randValue[i][j][1] = -0.2;
                }


                glTranslatef((i * 8 + randValue[i][j][0]), 0, (j * 8 + randValue[i][j][1]));
                glutSolidSphere(0.90, 50, 50);
            }glPopMatrix();
        }
    }
}