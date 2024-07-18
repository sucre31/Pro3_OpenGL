#include <complex>
#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Player.h"
#include "SystemMain.h"
#include "Texture.h"

Player::Player() : x(0.0), y(0.5), z(0.0),velY(0.0), angleY(-M_PI / 2), speed(0.0), speedMax(2.0), accel(0.01), brake(0.02), handling(0.2 * M_PI / 360), handleAngle(0.0), handleAngleMax(8 * M_PI / 360) {
    lightSwitch = true;
    lightChanged = false;
    inTheWall = false;
    fuel = 200;
    fuelMax = 200;
    fuelMeter.setFuel(fuel);
    fuelMeter.setFuelMax(fuelMax);
    speedMeter.setMaxSpeed(speedMax);
    speedMeter.setSpeed(speed);
    headLight.setLightNumber(1);
    pedalAccel.setCheckKey(0);
    pedalAccel.setX(-1.0);
    pedalAccel.setY(-2.6f);
    pedalAccel.setScaleX(0.3);
    pedalAccel.setScaleY(0.8);
    pedalBrake.setCheckKey(1);
    pedalBrake.setX(1.0);
    pedalBrake.setY(-2.6f);
    pedalBrake.setScaleX(0.35);
    pedalBrake.setScaleY(0.5);
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
        GLfloat materialEmission[] = { 0.1, 0.1, 0.1, 1.0 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialEmission);
        //自機の描画
        glTranslatef(x, y, z); //位置変数をもとに移動
        glRotatef(angleY * (180 / M_PI) - 90, 0.0, 1.0, 0.0);  //Y軸まわりにangleY(ラジアン)回転
        glRotatef(0.3 * handleAngle * (180 / M_PI), 0.0, 0.0, 1.0);  //handleAngleも考慮
        glPushMatrix(); {//モデルはコストが高いのでテクスチャで代用
            glEnable(GL_TEXTURE_2D); // テクスチャマッピング開始
            glEnable(GL_ALPHA_TEST);
            glTranslated(0.0, 1.5, 6.0);
            glRotatef(-90, 0.0, 0.0, 1.0);  //Z軸まわりに-90°回転
            glScaled(2.0, 2.0, 0.1);
            //Texture::getIns()->setTexture(Texture::getIns()->CAR); //7枚目のテクスチャは更新しない
            plate.drawBoxPlayer(1.0, 1.0, 1.0);
            glDisable(GL_TEXTURE_2D); // テクスチャマッピング終了
            glDisable(GL_ALPHA_TEST);
        }glPopMatrix();
    }glPopMatrix();

    headLight.draw();
}

void Player::drawInfo() {
    shiftLever.draw();
    drawHandle();
    pedalAccel.draw();
    pedalBrake.draw();
    speedMeter.draw();
}

void Player::drawInfo2D() {
    carNavi.draw();
    fuelMeter.draw();
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


void Player::update() {
    power = 0.005;  //電力の再計算
    //ハンドル回転
    if (SystemMain::getIns()->key.getKeyLeftON()) {
        handleAngle += handling;
    }
    else if (SystemMain::getIns()->key.getKeyRightON()) {
        handleAngle -= handling;
    }
    else {              // ハンドル持ってない (左右同時押しこれでいいかは検討)
        handleAngle -= (1.0 * handleAngle) * M_PI / 360;
    }
    if (handleAngle > handleAngleMax) {
        handleAngle = handleAngleMax;
    }
    if (handleAngle < -handleAngleMax) {
        handleAngle = -handleAngleMax;
    }
    //アクセル
    if (SystemMain::getIns()->key.getKeyUpON()) {
        if (fuel > 0) {
            speed += accel;
            power += 0.04;
        }
    }
    if (SystemMain::getIns()->key.getKeyDownON()) {     // ブレーキ
        if (speed < 0) {
            speed += brake;
            if (speed > 0) {
                speed = 0;
            }
        }
        else {
            speed -= brake;
            if (speed < 0) {
                speed = 0;
            }
        }
    } 
    else {
        //speed += 0.001;             //クリープ現象
    }
    if (speed < 0) {//何もしなくても速度は減る
        speed += 0.004;
        if (speed > 0) {
            speed = 0;
        }
    }
    else if (speed > 0) {
        speed -= 0.004;
        if (speed < 0) {
            speed = 0;
        }
    }
    if (speed > speedMax) { //って思ったらスピード制限
        speed = speedMax;
    }
    if (speed < 0) {
        //speed = 0;
    }
    if (speed == 0) {       //速度が0のときだけシフト判定
        if (SystemMain::getIns()->key.getKeyZON() > 0) {
            shift = 1;
        }
        else {
            shift = 0;
        }
    }
    if (speed > 0 || true) {
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
    if (SystemMain::getIns()->key.getKeyXON() > 0) {
        if (!lightChanged) {
            lightSwitch = !lightSwitch;
            lightChanged = true;        //連続で切り替わらないようにする
        }
    }
    else {
        lightChanged = false;
    }
    if (lightSwitch) {
        power += 0.01;
    }
    fuel -= power; // エンジン切らないと燃料減る あとライトとか
    if (fuel < 0 ) {
        fuel = 0;
    }

    //y方向の更新
    if (SystemMain::getIns()->game.field.checkFieldValue(FieldX, FieldZ) == 0) {
        //足場なし(真上から見て)
        if (!inTheWall) {
            double e = 0.2; //反発係数
            speed = -speed * e;      //浸透圧で抜けれるんだけど
            inTheWall = true;
        }
    }
    else {
        inTheWall = false;
        //足場あり
        if (y < -0.5) {
            velY -= 0.1;
            y += velY;
        }
        else if (y > 0.5) {
            velY -= 0.1;
            y += velY; 
            if (y < 0.5) {
                y = 0.5;
            }
        }
        else {
            // -0.5までなら落ちない
            y = 0.5;
            velY = 0;
        }


    }
    if (y < -100) {
        x = defX;
        z = defZ;
        y = 0.0;
        velY = 0;
        angleY = -M_PI / 2;
    }

    //グリッド座標を更新
    FieldX = SystemMain::getIns()->game.field.getFieldX(x);
    FieldZ = SystemMain::getIns()->game.field.getFieldZ(z);

    //カメラ位置の更新
    SystemMain::getIns()->game.camera.setX(x - 17 * cos(angleY));
    SystemMain::getIns()->game.camera.setY(y + 3.5);
    SystemMain::getIns()->game.camera.setZ(z + 17 * sin(angleY));
    SystemMain::getIns()->game.camera.setTargetX(x - 10 * cos(angleY + M_PI));
    SystemMain::getIns()->game.camera.setTargetY(1.0);
    SystemMain::getIns()->game.camera.setTargetZ(z + 10 * sin(angleY + M_PI));

    // ヘッドライト位置の更新
    headLight.setHeadLightPosX(x);
    headLight.setHeadLightPosY(y);
    headLight.setHeadLightPosZ(z);
    headLight.setAngle(angleY);
    headLight.setLightValid(isFuelRemaining() && lightSwitch);
    headLight.update();

    //シフトレバーの更新
    shiftLever.update();

    //アクセル・ブレーキの更新
    pedalAccel.update();
    pedalBrake.update();

    //カーナビの更新
    carNavi.setPlayerX(FieldX);
    carNavi.setPlayerZ(FieldZ);
    carNavi.setPlayerPosX(SystemMain::getIns()->game.field.getFieldRemainderX(x));
    carNavi.setPlayerPosZ(SystemMain::getIns()->game.field.getFieldRemainderZ(z));

    //スピードメーターの更新
    speedMeter.setSpeed(speed);
    speedMeter.update();

    //燃料の更新
    fuelMeter.setFuel(fuel);
}