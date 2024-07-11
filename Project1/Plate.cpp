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

/*
@brief 床を設置(拡散光のみ指定する)
*/
void Plate::drawFloor(double x, double y, double z, double rate) {
    glPushMatrix(); {
        GLfloat mat0ambi[] = { 0.329412,  0.229412, 0.229412, 1.0 };
        GLfloat mat0spec[] = { 0.292157,  0.292157, 0.292157, 1.0 };
        GLfloat mat0shine[] = { 27.89743616 };//真鍮的なかがやき
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //鏡面光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
        //地面の描画
        glTranslatef(x, y, z); //中心位置を決める必要あり
        glScalef(1.0, 0.01, 1.0);
        glutSolidCube(rate);
    }glPopMatrix();
}

void Plate::drawBox(double x, double y, double z)
{
    /* 頂点の座標値 */
    const GLdouble vertex[][4][3] = {
      {{ -x, -y, -z }, {  x, -y, -z }, {  x, -y,  z }, { -x, -y,  z }},
      {{ -x, -y, -z }, { -x,  y, -z }, {  x,  y, -z }, {  x, -y, -z }},
      {{  x, -y, -z }, {  x,  y, -z }, {  x,  y,  z }, {  x, -y,  z }},
      {{  x, -y,  z }, {  x,  y,  z }, { -x,  y,  z }, { -x, -y,  z }},
      {{ -x, -y,  z }, { -x,  y,  z }, { -x,  y, -z }, { -x, -y, -z }},
      {{ -x,  y,  z }, {  x,  y,  z }, {  x,  y, -z }, { -x,  y, -z }},
    };

    /* 頂点のテクスチャ座標 */
    static const GLdouble texcoord[][4][2] = {
    {{ 0.0,   1.0 }, { 0.125, 1.0 }, { 0.125, 0.0 }, { 0.0,   0.0 }},
    {{ 0.125, 1.0 }, { 0.25,  1.0 }, { 0.25,  0.0 }, { 0.125, 0.0 }},
    {{ 0.25,  1.0 }, { 0.375, 1.0 }, { 0.375, 0.0 }, { 0.25,  0.0 }},
    {{ 0.375, 1.0 }, { 0.5,   1.0 }, { 0.5,   0.0 }, { 0.375, 0.0 }},
    {{ 0.5,   1.0 }, { 0.625, 1.0 }, { 0.625, 0.0 }, { 0.5,   0.0 }},
    {{ 0.625, 1.0 }, { 0.75,  1.0 }, { 0.75,  0.0 }, { 0.625, 0.0 }},
    };

    /* 面の法線ベクトル */
    static const GLdouble normal[][3] = {
      {  0.0, -1.0,  0.0 },
      {  0.0,  0.0, -1.0 },
      {  1.0,  0.0,  0.0 },
      {  0.0,  0.0,  1.0 },
      { -1.0,  0.0,  0.0 },
      {  0.0,  1.0,  0.0 },
    };

    int i, j;

    /* 四角形６枚で箱を描く */
    glBegin(GL_QUADS);
    for (j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]);
        for (i = 0; i < 4; ++i) {
            /* テクスチャ座標の指定 */
            glTexCoord2dv(texcoord[j][i]);
            /* 対応する頂点座標の指定 */
            glVertex3dv(vertex[j][i]);
        }
    }
    glEnd();
}
