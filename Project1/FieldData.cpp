#include <time.h>
#include <stdlib.h>
#include <glut.h>
#include "FieldData.h"
#include "SystemMain.h"

FieldData::FieldData() {
	int i, j;
    bool valid = false;     // �z�u���邩?
    srand((unsigned int)time(NULL));        // �ՖʂɃf�[�^��ݒu
	for (i = 0; i < fieldSizeX; i++) {               // �Ֆʂ̏�����
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

            //���̓���
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
    /*���ꂼ��̔Ֆʂ̏�Ԃ��󂯎��`��*/
    GLfloat mat0ambi[] = { 0.59225,  0.19225, 0.19225, 1.0 };//��
    GLfloat mat0diff[] = { 0.60754,  0.50754, 0.50754, 1.0 };
    GLfloat mat0spec[] = { 0.608273,  0.508273, 0.508273, 1.0 };
    GLfloat mat0shine[] = { 51.2 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //�����̔��˗���ݒ�
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //�g�U���̔��˗���ݒ�
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //���ʌ��̔��˗���ݒ�
    for (i = 0; i < fieldSizeX; i++) {
        for (j = 0; j < fieldSizeZ; j++) {
            switch (field[i][j]) {
            case 0:
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
                valid = true;
                break;
            case 1://�ԃJ�v�Z��
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
                valid = false;
                break;
            case 2://���J�v�Z��
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, yellow);
                valid = false;
                break;
            case 3://�J�v�Z��
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
                valid = false;
                break;
            default:
                break;
            }
            // ��
            if (valid) {
                glPushMatrix(); {
                    //glEnable(GL_TEXTURE_2D);        //�e�L�X�`���}�b�s���O�J�n

                    ///* �e�N�X�`�����W�̎���������L���ɂ��� */
                    //glEnable(GL_TEXTURE_GEN_S);
                    //glEnable(GL_TEXTURE_GEN_T);

                    glTranslatef((i * GridSize + randValue[i][j][0]), 0, (j * GridSize + randValue[i][j][1]));
                    glutSolidSphere(0.90, 15, 15);              // ��

                    ///* �e�N�X�`�����W�̎��������𖳌��ɂ��� */
                    //glDisable(GL_TEXTURE_GEN_S);
                    //glDisable(GL_TEXTURE_GEN_T);

                    //glDisable(GL_TEXTURE_2D);
                }glPopMatrix();
            }
            // ��
            if (field[i][j] != 0) {
                //GLfloat mat0diff[] = { 0.780392,  0.780392, 0.780392, 1.0 };
                //glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff);
                plate.drawFloor((i * GridSize), -1.0, (j * GridSize), GridSize);
            }
        }
    }
}