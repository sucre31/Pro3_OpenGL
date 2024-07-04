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