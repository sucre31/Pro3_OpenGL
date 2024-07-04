#include <glut.h>
#include "Plate.h"

void Plate::draw() {
    glPushMatrix(); {
        GLfloat mat0ambi[] = { 0.329412,  0.329412, 0.329412, 1.0 };//
        GLfloat mat0diff[] = { 0.780392,  0.780392, 0.780392, 1.0 };//
        GLfloat mat0spec[] = { 0.292157,  0.292157, 0.292157, 1.0 };//
        GLfloat mat0shine[] = { 27.89743616 };//真鍮的なかがやき
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //環境光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //拡散光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //鏡面光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
        //地面の描画
        glTranslatef(40, -1.5, 90); //中心位置を決める必要あり
        glScalef(1.0, 0.01, 2.0);
        glutSolidCube(100.0);
    }glPopMatrix();
}