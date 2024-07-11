#include <glut.h>
#include "Plate.h"

void Plate::draw() {
    glPushMatrix(); {
        GLfloat mat0ambi[] = { 0.329412,  0.329412, 0.329412, 1.0 };//
        GLfloat mat0diff[] = { 0.780392,  0.780392, 0.780392, 1.0 };//
        GLfloat mat0spec[] = { 0.292157,  0.292157, 0.292157, 1.0 };//
        GLfloat mat0shine[] = { 27.89743616 };//�^�J�I�Ȃ����₫
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //�����̔��˗���ݒ�
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //�g�U���̔��˗���ݒ�
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //���ʌ��̔��˗���ݒ�
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
        //�n�ʂ̕`��
        glTranslatef(40, -1.5, 90); //���S�ʒu�����߂�K�v����
        glScalef(1.0, 0.01, 2.0);
        glutSolidCube(100.0);
    }glPopMatrix();
}

/*
@brief ����ݒu(�g�U���̂ݎw�肷��)
*/
void Plate::drawFloor(double x, double y, double z, double rate) {
    glPushMatrix(); {
        GLfloat mat0ambi[] = { 0.329412,  0.229412, 0.229412, 1.0 };
        GLfloat mat0spec[] = { 0.292157,  0.292157, 0.292157, 1.0 };
        GLfloat mat0shine[] = { 27.89743616 };//�^�J�I�Ȃ����₫
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //���ʌ��̔��˗���ݒ�
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
        //�n�ʂ̕`��
        glTranslatef(x, y, z); //���S�ʒu�����߂�K�v����
        glScalef(1.0, 0.01, 1.0);
        glutSolidCube(rate);
    }glPopMatrix();
}

void Plate::drawBox(double x, double y, double z)
{
    /* ���_�̍��W�l */
    const GLdouble vertex[][4][3] = {
      {{ -x, -y, -z }, {  x, -y, -z }, {  x, -y,  z }, { -x, -y,  z }},
      {{ -x, -y, -z }, { -x,  y, -z }, {  x,  y, -z }, {  x, -y, -z }},
      {{  x, -y, -z }, {  x,  y, -z }, {  x,  y,  z }, {  x, -y,  z }},
      {{  x, -y,  z }, {  x,  y,  z }, { -x,  y,  z }, { -x, -y,  z }},
      {{ -x, -y,  z }, { -x,  y,  z }, { -x,  y, -z }, { -x, -y, -z }},
      {{ -x,  y,  z }, {  x,  y,  z }, {  x,  y, -z }, { -x,  y, -z }},
    };

    /* ���_�̃e�N�X�`�����W */
    static const GLdouble texcoord[][4][2] = {
    {{ 0.0,   1.0 }, { 0.125, 1.0 }, { 0.125, 0.0 }, { 0.0,   0.0 }},
    {{ 0.125, 1.0 }, { 0.25,  1.0 }, { 0.25,  0.0 }, { 0.125, 0.0 }},
    {{ 0.25,  1.0 }, { 0.375, 1.0 }, { 0.375, 0.0 }, { 0.25,  0.0 }},
    {{ 0.375, 1.0 }, { 0.5,   1.0 }, { 0.5,   0.0 }, { 0.375, 0.0 }},
    {{ 0.5,   1.0 }, { 0.625, 1.0 }, { 0.625, 0.0 }, { 0.5,   0.0 }},
    {{ 0.625, 1.0 }, { 0.75,  1.0 }, { 0.75,  0.0 }, { 0.625, 0.0 }},
    };

    /* �ʂ̖@���x�N�g�� */
    static const GLdouble normal[][3] = {
      {  0.0, -1.0,  0.0 },
      {  0.0,  0.0, -1.0 },
      {  1.0,  0.0,  0.0 },
      {  0.0,  0.0,  1.0 },
      { -1.0,  0.0,  0.0 },
      {  0.0,  1.0,  0.0 },
    };

    int i, j;

    /* �l�p�`�U���Ŕ���`�� */
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            /* �e�N�X�`�����W�̎w�� */
            glTexCoord2dv(texcoord[j][i]);
            /* �Ή����钸�_���W�̎w�� */
            glVertex3dv(vertex[j][i]);
        }
    }
    glEnd();
}
