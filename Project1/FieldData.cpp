#include <time.h>
#include <stdlib.h>
#include <glut.h>
#include "FieldData.h"
#include "SystemMain.h"
#include "Texture.h"

FieldData::FieldData() {
    fieldSizeX = fieldGridNumber;
    fieldSizeZ = fieldGridNumber;
	int i, j;
    bool valid = true;     // 配置するか?
    srand((unsigned int)time(NULL));        // 盤面にデータを設置
	for (i = 0; i < fieldSizeX; i++) {               // 盤面の初期化
        valid = !valid;
		for (j = 0; j < fieldSizeZ; j++) {
            if (i == 0 || j == 0  || i == fieldSizeX - 1 || j == fieldSizeZ - 1) {
                field[i][j] = 0;
            }
            else if (valid) {
                field[i][j] = (rand() % 3) + 1;
            }
            else {
                if ((j == fieldSizeZ - 2 && ((i - 1) / 2) % 2 == 0) || (j == 1 && ((i - 1) / 2) % 2 == 1)) {
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
    field[1][1] = 1;
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
    static int maxVel = 0.04;
    static const GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    static const GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    static const GLfloat yellow[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    static const GLfloat blue[] = { 0.0f, 0.0f, 1.0f, 1.0f };
    GLfloat mat0ambi[] = { 0.59225,  0.19225, 0.19225, 1.0 };//銀
    GLfloat mat0diff[] = { 0.60754,  0.50754, 0.50754, 1.0 };
    GLfloat mat0spec[] = { 0.608273,  0.508273, 0.508273, 1.0 };
    GLfloat mat0shine[] = { 51.2 };
    /*それぞれの盤面の状態を受け取り描画*/
    Texture::getIns()->setTexture(Texture::getIns()->CONCRETE);
    glEnable(GL_TEXTURE_2D); // テクスチャマッピング開始
    glEnable(GL_TEXTURE_GEN_S); // テクスチャ座標の自動生成
    glEnable(GL_TEXTURE_GEN_T);
    glEnable(GL_TEXTURE_GEN_R);
    glEnable(GL_TEXTURE_GEN_Q);
    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();
    glTranslated(-0.5, -0.5, 0.0);
    glScaled(0.2, 0.2, 0.2);
    gluLookAt(0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    for (i = 0; i < fieldSizeX; i++) {
        for (j = 0; j < fieldSizeZ; j++) {
            const GLfloat* tmpColor = white;
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tmpColor); //環境光の反射率を設定
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tmpColor); //拡散光の反射率を設定
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tmpColor); //鏡面光の反射率を設定
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, tmpColor);
            // 壁

            if (field[i][j] == 0) {

                glPushMatrix(); {
                    glTranslatef((i * gridSize),1.0, (j * gridSize));
                    plate.drawBox(gridSize / 2, gridSize / 2, gridSize/ 2);             // 壁
                }glPopMatrix();
            }
            else if (field[i][j] != 0) { // 床
                glPushMatrix(); {
                    glTranslatef((i * gridSize), -(gridSize * (2.0 / 3.0)), (j * gridSize));
                    plate.drawBox(gridSize / 2, gridSize / 2, gridSize / 2);             // 床
                }glPopMatrix();
            }
        }
    }
    glDisable(GL_TEXTURE_GEN_S); // テクスチャマッピング終了
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_GEN_R);
    glDisable(GL_TEXTURE_GEN_Q);
    glDisable(GL_TEXTURE_2D);
}