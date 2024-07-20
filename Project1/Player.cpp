#include <complex>
#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Player.h"
#include "SystemMain.h"
#include "Texture.h"
#include "Sound.h"

Player::Player() : x(0.0), y(0.5), z(0.0),velY(0.0), angleY(-M_PI / 2), speed(0.0), speedMax(2.0), accel(0.01), brake(0.02), handling(0.2 * M_PI / 360), handleAngle(0.0), handleAngleMax(8 * M_PI / 360) {
    lightSwitch = true;
    lightChanged = false;
    inTheWall = false;
    brakeValid = false;
    fuel = 200;
    fuelMax = 200;
    fuelMeter.setFuel(fuel);
    fuelMeter.setFuelMax(fuelMax);
    speedMeter.setMaxSpeed(speedMax);
    speedMeter.setSpeed(speed);
    headLight.setLightNumber(1);
    pedalAccel.setCheckKey(0);
    pedalAccel.setX(-0.7);
    pedalAccel.setY(-2.6f);
    pedalAccel.setScaleX(0.3);
    pedalAccel.setScaleY(0.8);
    pedalBrake.setCheckKey(1);
    pedalBrake.setX(1.3);
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
        GLfloat materialEmission[] = { 0.2, 0.2, 0.2, 1.0 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialEmission);
        //自機の描画
        glTranslatef(x, y, z); //位置変数をもとに移動
        glRotatef(angleY * (180 / M_PI) - 90, 0.0, 1.0, 0.0);  //Y軸まわりにangleY(ラジアン)回転
        glPushMatrix(); {//モデルはコストが高いのでテクスチャで代用
            glEnable(GL_TEXTURE_2D); // テクスチャマッピング開始
            glEnable(GL_ALPHA_TEST);
            glTranslated(0.0, 1.5, 6.0);
            glRotatef(-90, 0.0, 0.0, 1.0);  //Z軸まわりに-90°回転
            glScaled(2.0, 2.0, 0.1);
            if (brakeValid) {
                Texture::getIns()->setTexture(Texture::getIns()->CARBRAKE); //7枚目のテクスチャは更新しない
            }
            else {
                Texture::getIns()->setTexture(Texture::getIns()->CAR); //7枚目のテクスチャは更新しない
            }
            glPushMatrix();
            glRotatef(-bodyAngle, 0.0, 0.0, 1.0);  // handleAngleも考慮
            plate.drawBoxPlayer(1.0, 1.0, 0.1);
            glPopMatrix();
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
    segment.draw();
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
        glTranslated(0.3, 0.0, 0.0);
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
        brakeValid = true;
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
        brakeValid = false;
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
            //衝突をここで判定
            double tmpX, tmpZ;
            int tmpGridX, tmpGridZ;
            tmpX = x + speed * cos(angleY);
            tmpZ = z + speed * -sin(angleY);
            tmpGridX = SystemMain::getIns()->game.field.getFieldX(tmpX);
            tmpGridZ = SystemMain::getIns()->game.field.getFieldX(tmpZ);
            if (SystemMain::getIns()->game.field.checkFieldValue(tmpGridX, tmpGridZ) == 0) {
                //衝突
                double e = 0.2; //反発係数
                speed = -speed * e - 0.2;      //浸透圧で抜けれるんだけど
            }
            x += speed * cos(angleY);
            z += speed * -sin(angleY);
        } 
        else if (shift == 1){
            angleY -= speed * handleAngle;
            //衝突をここで判定
            double tmpX, tmpZ;
            int tmpGridX, tmpGridZ;
            tmpX = x + speed * cos(angleY);
            tmpZ = z + speed * -sin(angleY);
            tmpGridX = SystemMain::getIns()->game.field.getFieldX(tmpX);
            tmpGridZ = SystemMain::getIns()->game.field.getFieldX(tmpZ);
            if (SystemMain::getIns()->game.field.checkFieldValue(tmpGridX, tmpGridZ) == 0) {
                //衝突
                double e = 0.2; //反発係数
                speed = -speed * e - 0.2;      //浸透圧で抜けれるんだけど
            }
            x -= speed * cos(angleY);
            z -= speed * -sin(angleY);
        }
    }
    if (SystemMain::getIns()->key.getKeyXON() > 0) {
        if (!lightChanged) {
            lightSwitch = !lightSwitch;
            lightChanged = true;        //連続で切り替わらないようにする
            Sound::getIns()->playSE2();
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
        fuel = 100;
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

    //車体の揺れ
    bodyAngle = 0.4 * abs(speed) * handleAngle * (180 / M_PI);
    //bodyAngle = -2.4 * abs(speed) * handleAngle * (180 / M_PI); //バイク用

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

    // 7セグの更新
    //タイマー
    timer = glutGet(GLUT_ELAPSED_TIME);
    int second, minute, conma;
    conma = timer / 10;
    second = timer / 1000;
    minute = second / 60;
    second = second % 60;
    minute = minute % 60;
    segment.setLampTimeState(5, conma % 10);
    segment.setLampTimeState(4, (conma / 10) % 10);
    segment.setLampTimeState(3, second % 10);
    segment.setLampTimeState(2, (second / 10) % 10);
    segment.setLampTimeState(1, minute % 10);
    segment.setLampTimeState(0, (minute / 10) % 10);



    /*
    ここから下はサウンド関連の処理 かなり無理矢理
    再生のたびに動作が停止する
    */

    static int brank = 6831;
    static int brankSE1 = 2631;
    static int brankSE4 = 3631;
    static int brankSE5 = 21631;
    static bool ValidSE1 = false; //減速
    static bool ValidSE3 = false; //アイドル
    static bool ValidSE4 = false; //加速中
    static bool ValidSE5 = false; //走行中
    static int tmpSound = 0;
    static int currentSound = -1;
    static double timerForSound;
    
    segment.setLampBState(0, currentSound);
    segment.setLampBState(1, tmpSound);

    if (currentSound != tmpSound) {
        //前の音を止める
        //Sound::getIns()->pauseSE(tmpSound);
        tmpSound = currentSound;
        soundChange = true;
        timerForSound = glutGet(GLUT_ELAPSED_TIME);
    }
    else {
        soundChange = false;
    }

    if ((currentSound == 1 || currentSound == 2 || currentSound == 4 )&& SystemMain::getIns()->key.getKeyDownON() && speed > 0) { //走行中のブレーキ
        currentSound = 4;
        Sound::getIns()->pauseSE4();
        Sound::getIns()->pauseSE5();
        if ((timer - timerForSound) - brankSE1 * (int)((timer - timerForSound) / brankSE1) < 1000) {  // 音のループを無理矢理ここでやる
            if (!ValidSE1) {
                Sound::getIns()->playSE1();
                ValidSE1 = true;
            }
        }
        else {
            ValidSE1 = false;
        }
    }
    else {
        if (speed > 0.6) {
            currentSound = 2;
            Sound::getIns()->pauseSE4();
            Sound::getIns()->pauseSE1();
            if ((timer - timerForSound) - brankSE5 * (int)((timer - timerForSound) / brankSE5) < 1000) {  // 音のループを無理矢理ここでやる
                if (!ValidSE5) {
                    Sound::getIns()->playSE5();
                    ValidSE5 = true;
                }
            }
            else {
                ValidSE5 = false;
            }
        }
        else if (speed > 0) {
            currentSound = 1;
            Sound::getIns()->pauseSE1();
            Sound::getIns()->pauseSE5();
            if ((timer - timerForSound) - brankSE4 * (int)((timer - timerForSound) / brankSE4) < 1000) {
                if (!ValidSE4) {
                    Sound::getIns()->playSE4();
                    ValidSE4 = true;
                }
            }
            else {
                ValidSE4 = false;
            }
        }
        else {
            currentSound = 0;
            Sound::getIns()->pauseSE1();
            Sound::getIns()->pauseSE4();
            Sound::getIns()->pauseSE5();
            if ((timer - timerForSound) - brank * (int)((timer - timerForSound) / brank) < 1000) {
                if (!ValidSE3) {
                    Sound::getIns()->playSE3();
                    ValidSE3 = true;
                }
            }
            else {
                ValidSE3 = false;
            }
        }
    }
}