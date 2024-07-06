#include <time.h>
#include <stdlib.h>
#include <glut.h>
#include "FieldData.h"
#include "SystemMain.h"

FieldData::FieldData() {
	int i, j;
    bool valid = false;     // 配置するか?
    srand((unsigned int)time(NULL));        // 盤面にデータを設置
	for (i = 0; i < fieldSizeX; i++) {               // 盤面の初期化
        valid = !valid;
		for (j = 0; j < fieldSizeZ; j++) {
            if (valid) {
                field[i][j] = (rand() % 3) + 1;
            }
            else {
                if ((j == fieldSizeZ - 1 && (i / 2) % 2 == 0) || (j == 0 && (i / 2) % 2 == 1)) {
                    field[i][j] = (rand() % 3) + 1;
                }
                else {
                    field[i][j] = 0;
                }
            }

            //球の動き
            randValue[i][j][0] = 0;
            randValue[i][j][1] = 0;
            randValueVel[i][j][1] = 0;
            randValueVel[i][j][1] = 0;
		}
	}
    field[0][0] = 1;
}

void FieldData::update() {
    int i, j;
    static int maxVel = 0.04;
    for (i = 0; i < fieldSizeX; i++) {
        for (j = 0; j < fieldSizeZ; j++) {
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
        }
    }
}

void FieldData::draw() {
    int i, j;
    bool valid = false;
    static int maxVel = 0.04;
    static const GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    static const GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    static const GLfloat yellow[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    static const GLfloat blue[] = { 0.0f, 0.0f, 1.0f, 1.0f };
    /*それぞれの盤面の状態を受け取り描画*/
    for (i = 0; i < fieldSizeX; i++) {
        for (j = 0; j < fieldSizeZ; j++) {
            switch (field[i][j]) {
            case 0:
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
                valid = true;
                break;
            case 1://赤カプセル
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
                valid = false;
                break;
            case 2://黄カプセル
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, yellow);
                valid = false;
                break;
            case 3://青カプセル
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
                valid = false;
                break;
            default:
                break;
            }
            // 球
            if (valid) {
                glPushMatrix(); {
                    //図形の色 (赤)
                    static const GLfloat red[] = { 0.8, 0.2, 0.2, 1.0 };

                    glEnable(GL_TEXTURE_2D);        //テキスチャマッピング開始

                    /* テクスチャ座標の自動生成を有効にする */
                    glEnable(GL_TEXTURE_GEN_S);
                    glEnable(GL_TEXTURE_GEN_T);

                    glTranslatef((i * GridSize + randValue[i][j][0]), 0, (j * GridSize + randValue[i][j][1]));
                    glutSolidSphere(0.90, 15, 15);              // 球

                    /* テクスチャ座標の自動生成を無効にする */
                    glDisable(GL_TEXTURE_GEN_S);
                    glDisable(GL_TEXTURE_GEN_T);

                    glDisable(GL_TEXTURE_2D);
                }glPopMatrix();
            }
            // 床
            if (field[i][j] != 0) {
                //GLfloat mat0diff[] = { 0.780392,  0.780392, 0.780392, 1.0 };
                //glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff);
                plate.drawFloor((i * GridSize), -1.0, (j * GridSize), GridSize);
            }
        }
    }
}