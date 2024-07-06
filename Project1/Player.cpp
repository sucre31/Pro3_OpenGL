#include <complex>
#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Player.h"
#include "SystemMain.h"

Player::Player() : x(0.0), y(0.0), z(0.0),velY(0.0), angleY(-M_PI / 2), speed(0.0), speedMax(0.8), accel(0.01), brake(0.02), handling(0.2 * M_PI / 360), handleAngle(0.0), handleAngleMax(8 * M_PI / 360) {

}

void Player::draw() {
    glPushMatrix(); {
        GLfloat mat0ambi[] = { 0.329412,  0.223529, 0.027451, 1.0 };//真鍮
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //環境光の反射率を設定
        GLfloat mat0diff[] = { 0.780392,  0.568627, 0.113725, 1.0 };//真鍮
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //拡散光の反射率を設定
        GLfloat mat0spec[] = { 0.992157,  0.941176, 0.807843, 1.0 };//真鍮
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //鏡面光の反射率を設定
        GLfloat mat0shine[] = { 27.89743616 };//真鍮
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
        //自機の描画
        glTranslatef(x, y, z); //位置変数をもとに移動
        glRotatef(angleY * (180 / M_PI) + 1.5 * handleAngle * (180 / M_PI), 0.0, 1.0, 0.0);  //Y軸まわりにangleY(ラジアン)回転 handleAngleも考慮
        glutSolidTeapot(1.0);            //自機はティーポット(笑)
    }glPopMatrix();
}

void Player::drawInfo() {
    shiftLever.draw();
    drawHandle();
    drawAccel();
    drawBrake();
    drawSpeed();
}

void Player::drawHandle() {
    glPushMatrix(); {       //ハンドル
        GLfloat mat0ambi[] = { 0.1,  0.1, 0.1, 1.0 };//黒皮
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //環境光の反射率を設定
        GLfloat mat0diff[] = { 0.1,  0.1, 0.1, 1.0 };//黒皮
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //拡散光の反射率を設定
        GLfloat mat0spec[] = { 0.1,  0.1, 0.1, 1.0 };//黒皮
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //鏡面光の反射率を設定
        GLfloat mat0shine[] = { 27.89743616 };//黒皮
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
        //ハンドルの描画
        glPushMatrix(); {
            //glTranslatef(x - 5 * cos(angleY), y + 0.5, z + 5 * sin(angleY)); //位置変数をもとに移動
            glTranslatef(0.0f, -2.1f, 0.0f);
            glPushMatrix(); {
                //glRotatef(angleY * (180 / M_PI) + 90, 0.0, 1.0, 0.0);  //Y軸周りにangleY(ラジアン)回転
                glRotatef(HandelRate * -handleAngle * (180 / M_PI), 0.0, 0.0, 1.0);  //Z軸周りにangleY(ラジアン)回転
                glutSolidTorus(0.1, 0.6, 5, 40);            //ハンドルの外側
                glPushMatrix(); {
                    glTranslatef(0.3 * cos(M_PI / 2), 0.3 * sin(M_PI / 2), 0.0); //ハンドルの中身1
                    glRotatef(90, 0.0, 0.0, 1.0);
                    glScalef(0.6, 0.2, 0.2);
                    glutSolidCube(0.8);
                }glPopMatrix();
                glPushMatrix(); {
                    glTranslatef(0.3 * cos(7 * M_PI / 6), 0.3 * sin(7 * M_PI / 6), 0.0); //ハンドルの中身2
                    glRotatef(210, 0.0, 0.0, 1.0);
                    glScalef(0.6, 0.2, 0.2);
                    glutSolidCube(0.8);
                }glPopMatrix();
                glPushMatrix(); {
                    glTranslatef(0.3 * cos(11 * M_PI / 6), 0.3 * sin(11 * M_PI / 6), 0.0); //ハンドルの中身2
                    glRotatef(330, 0.0, 0.0, 1.0);
                    glScalef(0.6, 0.2, 0.2);
                    glutSolidCube(0.8);
                }glPopMatrix();
                glutSolidTorus(0.2, 0.0, 5, 10);            //ハンドルの中心
            }glPopMatrix();
        }glPopMatrix();
    }glPopMatrix();
}

void Player::drawAccel() {
    const double angle = 30;
    glPushMatrix(); {       //ハンドル
        GLfloat mat0ambi[] = { 0.19225,  0.19225, 0.19225, 1.0 };//銀
        GLfloat mat0diff[] = { 0.50754,  0.50754, 0.50754, 1.0 };
        GLfloat mat0spec[] = { 0.508273,  0.508273, 0.508273, 1.0 };
        GLfloat mat0shine[] = { 51.2 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //環境光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //拡散光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //鏡面光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);

        // 描画
        glPushMatrix(); {
            glTranslatef(-1.0, -2.6f, 0.0);
            glRotatef(speed * (angle / speedMax) + 50, 1.0, 0.0, 0.0);
            glScalef(0.3, 0.8, 0.1);
            glPushMatrix(); {
                glutSolidCube(1.0);
            }glPopMatrix();
        }glPopMatrix();
    }glPopMatrix();
}

void Player::drawBrake() {
    const double angle = 30;
    glPushMatrix(); {       //ブレーキ
        GLfloat mat0ambi[] = { 0.19225,  0.19225, 0.19225, 1.0 };//銀
        GLfloat mat0diff[] = { 0.50754,  0.50754, 0.50754, 1.0 };
        GLfloat mat0spec[] = { 0.508273,  0.508273, 0.508273, 1.0 };
        GLfloat mat0shine[] = { 51.2 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //環境光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //拡散光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //鏡面光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);

        // 描画
        glPushMatrix(); {
            glTranslatef(1.0, -2.6f, 0.0);
            glRotatef(speed * (angle / speedMax) + 50, 1.0, 0.0, 0.0);
            glScalef(0.3, 0.4, 0.1);
            glPushMatrix(); {
                glutSolidCube(1.0);
            }glPopMatrix();
        }glPopMatrix();
    }glPopMatrix();
}

void Player::drawSpeed() {
    glPushMatrix(); {       //スピードメーター
        GLfloat mat0ambi[] = { 0.59225,  0.19225, 0.19225, 1.0 };//銀
        GLfloat mat0diff[] = { 0.60754,  0.50754, 0.50754, 1.0 };
        GLfloat mat0spec[] = { 0.608273,  0.508273, 0.508273, 1.0 };
        GLfloat mat0shine[] = { 51.2 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //環境光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //拡散光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //鏡面光の反射率を設定
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);

        // 描画
        glTranslatef(0.3 * -cos(( 90 * (speed / speedMax) - 135) * (M_PI / 180)), 0.3 * -sin((90 * (speed / speedMax) - 135) * (M_PI / 180)), 0.0);
        glPushMatrix(); {
            glTranslatef(-2.0, -2.5f, 0.0);
            glRotatef((speed / speedMax) * 90 - 45, 0.0, 0.0, 1.0);
            glScalef(0.01, 0.5, 0.01);
            glPushMatrix(); {
                glutSolidCube(1.0);
            }glPopMatrix();
        }glPopMatrix();
    }glPopMatrix();
}


void Player::update() {
    //ハンドル回転
    if (SystemMain::getIns()->key.getKeyLeftON()) {
        handleAngle += handling;
    }
    else if (SystemMain::getIns()->key.getKeyRightON()) {
        handleAngle -= handling;
    }
    else {              // ハンドル持ってない (左右同時押しこれでいいかは検討)
        handleAngle -= (5.0 * handleAngle) * M_PI / 360;
    }
    if (handleAngle > handleAngleMax) {
        handleAngle = handleAngleMax;
    }
    if (handleAngle < -handleAngleMax) {
        handleAngle = -handleAngleMax;
    }
    //アクセル
    if (SystemMain::getIns()->key.getKeyUpON()) {
        speed += accel;
    }
    if (SystemMain::getIns()->key.getKeyDownON()) {     // ブレーキ
        speed -= brake;
    } 
    else {
        //speed += 0.001;             //クリープ現象
    }
    speed -= 0.004;       //何もしなくても速度は減る
    if (speed > speedMax) { //って思ったらスピード制限
        speed = speedMax;
    }
    if (speed < 0) {
        speed = 0;
    }
    if (speed == 0) {       //速度が0のときだけシフト判定
        if (SystemMain::getIns()->key.getKeyZON()) {
            shift = 1;
        }
        else {
            shift = 0;
        }
    }
    if (speed > 0) {
        if (shift == 0) {
            angleY += speed * handleAngle;
            x += speed * cos(angleY);
            z += speed * -sin(angleY);
        } 
        else if (shift == 1){
            angleY -= speed * handleAngle;
            x -= speed * cos(angleY);
            z -= speed * -sin(angleY);
        }
    }
    y += velY;      //y方向の速度を元に更新

    if (SystemMain::getIns()->field.checkFieldValue(FieldX, FieldZ) == 0) {
        velY -= 0.1;
    }
    else {
        if (y < -0.5 || y > 0) {
            velY -= 0.1;
        }
        else {
            y = 0;
            velY = 0;
        }
    }
    if (y < -100) {
        x = 0;
        z = 0;
        y = 5;
        velY = 0;
        angleY = -M_PI / 2;
    }

    //グリッド座標を更新
    FieldX = SystemMain::getIns()->field.getFieldX(x);
    FieldZ = SystemMain::getIns()->field.getFieldZ(z);

    //カメラ位置の更新
    SystemMain::getIns()->camera.setX(x - 18 * cos(angleY));
    SystemMain::getIns()->camera.setY(y + 4.5);
    SystemMain::getIns()->camera.setZ(z + 18 * sin(angleY));

    //シフトレバーの更新
    shiftLever.update();
}