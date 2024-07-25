#include <complex>
#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Player.h"
#include "SystemMain.h"
#include "Texture.h"
#include "Sound.h"

Player::Player() : x(0.0), y(0.5), z(0.0),velY(0.0), angleY(-M_PI / 2), speed(0.0), speedMax(2.0), accel(0.01), brake(0.02), handling(0.2 * M_PI / 360), handleAngle(0.0), handleAngleMax(8 * M_PI / 360) {
    carLengthX = 3.0; 
    carLengthX2 = 2.5;
    carLengthZ = 3.5;
    lightSwitch = true;
    lightChanged = false;
    inTheWall = false;
    brakeValid = false;
    fuel = 100;
    fuelMax = 100;
    fuelMeter.setFuel(fuel);
    fuelMeter.setFuelMax(fuelMax);
    money = 250000;
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
        GLfloat mat0ambi[] = { 0.329412,  0.223529, 0.027451, 1.0 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //�����̔��˗���ݒ�
        GLfloat mat0diff[] = { 0.780392,  0.568627, 0.113725, 1.0 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //�g�U���̔��˗���ݒ�
        GLfloat mat0spec[] = { 0.992157,  0.941176, 0.807843, 1.0 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //���ʌ��̔��˗���ݒ�
        GLfloat mat0shine[] = { 27.89743616 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
        GLfloat materialEmission[] = { 0.2, 0.2, 0.2, 1.0 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialEmission);
        //���@�̕`��
        glTranslatef(x, y, z); //�ʒu�ϐ������ƂɈړ�
        glRotatef(angleY * (180 / M_PI) - 90, 0.0, 1.0, 0.0);  //Y���܂���angleY(���W�A��)��]
        glPushMatrix(); {//���f���̓R�X�g�������̂Ńe�N�X�`���ő�p
            glEnable(GL_TEXTURE_2D); // �e�N�X�`���}�b�s���O�J�n
            glEnable(GL_ALPHA_TEST);
            glTranslated(0.0, 1.5, 1.0);
            glRotatef(-90, 0.0, 0.0, 1.0);  //Z���܂���-90����]
            glScaled(2.0, 2.0, 0.1);
            if (brakeValid) {
                Texture::getIns()->setTexture(Texture::getIns()->CARBRAKE); //7���ڂ̃e�N�X�`���͍X�V���Ȃ�
            }
            else {
                Texture::getIns()->setTexture(Texture::getIns()->CAR); //7���ڂ̃e�N�X�`���͍X�V���Ȃ�
            }
            glPushMatrix();
            glRotatef(-bodyAngle, 0.0, 0.0, 1.0);  // handleAngle���l��
            plate.drawBoxPlayer(1.0, 1.0, 0.1);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D); // �e�N�X�`���}�b�s���O�I��
            glDisable(GL_ALPHA_TEST);
        }glPopMatrix();
    }glPopMatrix();

    glPushMatrix(); { //  �Փ˔���
        //glPushMatrix(); {
        //    glTranslatef(collisionX1, 2.0, collisionZ1); //�ʒu�ϐ������ƂɈړ�
        //    glutSolidSphere(0.1, 10, 10);
        //}glPopMatrix();
        //glPushMatrix(); {
        //    glTranslatef(collisionX2, 2.0, collisionZ2); //�ʒu�ϐ������ƂɈړ�
        //    glutSolidSphere(0.1, 10, 10);
        //}glPopMatrix();
        //glPushMatrix(); {
        //    glTranslatef(collisionX3, 2.0, collisionZ3); //�ʒu�ϐ������ƂɈړ�
        //    glutSolidSphere(0.1, 10, 10);
        //}glPopMatrix();
        //glPushMatrix(); {
        //    glTranslatef(collisionX4, 2.0, collisionZ4); //�ʒu�ϐ������ƂɈړ�
        //    glutSolidSphere(0.1, 10, 10);
        //}glPopMatrix();
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
    glPushMatrix(); {       //�n���h��
        GLfloat mat0ambi[] = { 0.1,  0.1, 0.1, 1.0 };//����
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //�����̔��˗���ݒ�
        GLfloat mat0diff[] = { 0.1,  0.1, 0.1, 1.0 };//����
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //�g�U���̔��˗���ݒ�
        GLfloat mat0spec[] = { 0.1,  0.1, 0.1, 1.0 };//����
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //���ʌ��̔��˗���ݒ�
        GLfloat mat0shine[] = { 27.89743616 };//����
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
        //�n���h���̕`��
        glTranslated(0.3, 0.0, 0.0);
        glPushMatrix(); {
            //glTranslatef(x - 5 * cos(angleY), y + 0.5, z + 5 * sin(angleY)); //�ʒu�ϐ������ƂɈړ�
            glTranslatef(0.0f, -2.1f, 0.0f);
            glPushMatrix(); {
                //glRotatef(angleY * (180 / M_PI) + 90, 0.0, 1.0, 0.0);  //Y�������angleY(���W�A��)��]
                glRotatef(HandelRate * -handleAngle * (180 / M_PI), 0.0, 0.0, 1.0);  //Z�������angleY(���W�A��)��]
                glutSolidTorus(0.1, 0.6, 5, 40);            //�n���h���̊O��
                glPushMatrix(); {
                    glTranslatef(0.3 * cos(M_PI / 2), 0.3 * sin(M_PI / 2), 0.0); //�n���h���̒��g1
                    glRotatef(90, 0.0, 0.0, 1.0);
                    glScalef(0.6, 0.2, 0.2);
                    glutSolidCube(0.8);
                }glPopMatrix();
                glPushMatrix(); {
                    glTranslatef(0.3 * cos(7 * M_PI / 6), 0.3 * sin(7 * M_PI / 6), 0.0); //�n���h���̒��g2
                    glRotatef(210, 0.0, 0.0, 1.0);
                    glScalef(0.6, 0.2, 0.2);
                    glutSolidCube(0.8);
                }glPopMatrix();
                glPushMatrix(); {
                    glTranslatef(0.3 * cos(11 * M_PI / 6), 0.3 * sin(11 * M_PI / 6), 0.0); //�n���h���̒��g2
                    glRotatef(330, 0.0, 0.0, 1.0);
                    glScalef(0.6, 0.2, 0.2);
                    glutSolidCube(0.8);
                }glPopMatrix();
                glutSolidTorus(0.2, 0.0, 5, 10);            //�n���h���̒��S
            }glPopMatrix();
        }glPopMatrix();
    }glPopMatrix();
}


void Player::update() {
    power = 0.005;  //�d�͂̍Čv�Z
    //�n���h����]
    if (SystemMain::getIns()->key.getKeyLeftON()) {
        handleAngle += handling;
    }
    else if (SystemMain::getIns()->key.getKeyRightON()) {
        handleAngle -= handling;
    }
    else {              // �n���h�������ĂȂ� (���E������������ł������͌���)
        handleAngle -= (1.0 * handleAngle) * M_PI / 360;
    }
    if (handleAngle > handleAngleMax) {
        handleAngle = handleAngleMax;
    }
    if (handleAngle < -handleAngleMax) {
        handleAngle = -handleAngleMax;
    }
    //�A�N�Z��
    if (SystemMain::getIns()->key.getKeyUpON()) {
        if (fuel > 0) {
            speed += accel;
            power += 0.04;
        }
    }
    if (SystemMain::getIns()->key.getKeyDownON()) {     // �u���[�L
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
        //speed += 0.001;             //�N���[�v����
    }
    if (speed < 0) {//�������Ȃ��Ă����x�͌���
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
    if (speed > speedMax) { //���Ďv������X�s�[�h����
        speed = speedMax;
    }
    if (speed < 0) {
        //speed = 0;
    }
    if (speed == 0) {       //���x��0�̂Ƃ������V�t�g����
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
            //�Փ˂������Ŕ���
            double tmpX1, tmpX2, tmpX3, tmpX4, tmpZ1, tmpZ2, tmpZ3, tmpZ4;
            int tmpGridX1, tmpGridX2, tmpGridX3, tmpGridX4, tmpGridZ1, tmpGridZ2, tmpGridZ3, tmpGridZ4;
            bool tmpCrushA = false, tmpCrushB = false;  //�Փ˔���
            tmpX1 = x + speed * cos(angleY) + (carLengthX / 2) * sin(angleY);       // �Փ˃`�F�b�N�p��X���W1
            tmpX2 = x + speed * cos(angleY) - (carLengthX / 2) * sin(angleY);       // �Փ˃`�F�b�N�p��X���W2
            tmpX3 = x + speed * cos(angleY) + (carLengthX2 / 2) * sin(angleY) - carLengthZ * sin(angleY + M_PI / 2);       // �Փ˃`�F�b�N�p��X���W2
            tmpX4 = x + speed * cos(angleY) - (carLengthX2 / 2) * sin(angleY) - carLengthZ * sin(angleY + M_PI / 2);        // �Փ˃`�F�b�N�p��X���W2
            tmpZ1 = z + speed * -sin(angleY) + (carLengthX / 2) * cos(angleY);                                  // �Փ˃`�F�b�N�p��Z���W1
            tmpZ2 = z + speed * -sin(angleY) - (carLengthX / 2) * cos(angleY);                                       // �Փ˃`�F�b�N�p��Z���W2
            tmpZ3 = z + speed * -sin(angleY) + (carLengthX2 / 2) * cos(angleY) - carLengthZ * cos(angleY + M_PI / 2);                                       // �Փ˃`�F�b�N�p��Z���W2
            tmpZ4 = z + speed * -sin(angleY) - (carLengthX2 / 2) * cos(angleY) - carLengthZ * cos(angleY + M_PI / 2);                                       // �Փ˃`�F�b�N�p��Z���W2
            tmpGridX1 = SystemMain::getIns()->game.field.getFieldX(tmpX1);
            tmpGridX2 = SystemMain::getIns()->game.field.getFieldX(tmpX2);
            tmpGridX3 = SystemMain::getIns()->game.field.getFieldX(tmpX3);
            tmpGridX4 = SystemMain::getIns()->game.field.getFieldX(tmpX4);
            tmpGridZ1 = SystemMain::getIns()->game.field.getFieldX(tmpZ1);
            tmpGridZ2 = SystemMain::getIns()->game.field.getFieldX(tmpZ2);
            tmpGridZ3 = SystemMain::getIns()->game.field.getFieldX(tmpZ3);
            tmpGridZ4 = SystemMain::getIns()->game.field.getFieldX(tmpZ4);
            tmpCrushA = (SystemMain::getIns()->game.field.checkFieldValue(tmpGridX1, tmpGridZ1) == 0);
            tmpCrushA = tmpCrushA || (SystemMain::getIns()->game.field.checkFieldValue(tmpGridX2, tmpGridZ2) == 0);
            tmpCrushB =  (SystemMain::getIns()->game.field.checkFieldValue(tmpGridX3, tmpGridZ3) == 0);
            tmpCrushB = tmpCrushB || (SystemMain::getIns()->game.field.checkFieldValue(tmpGridX4, tmpGridZ4) == 0);
            if (tmpCrushA) {
                //�Փ�
                money -= 25000 * abs(speed);           // �C����
                Sound::getIns()->playSE7();
                double e = 0.2; //�����W��
                speed = -speed * e - 0.1;      //�Z�����Ŕ������񂾂���
            }
            if (tmpCrushB) {
                //�Փ�
                money -= 25000 * abs(speed);           // �C����
                Sound::getIns()->playSE7();
                double e = 0.2; //�����W��
                speed = speed * e + 0.1;      //�Z�����Ŕ������񂾂���
            }
            x += speed * cos(angleY);
            z += speed * -sin(angleY);
            collisionX1 = x + speed * cos(angleY) + (carLengthX / 2) * sin(angleY);       // �Փ˃`�F�b�N�p��X���W1
            collisionX2 = x + speed * cos(angleY) - (carLengthX / 2) * sin(angleY);       // �Փ˃`�F�b�N�p��X���W2
            collisionX3 = x + speed * cos(angleY) + (carLengthX2 / 2) * sin(angleY) - carLengthZ * sin(angleY + M_PI / 2);       // �Փ˃`�F�b�N�p��X���W2
            collisionX4 = x + speed * cos(angleY) - (carLengthX2 / 2) * sin(angleY) - carLengthZ * sin(angleY + M_PI / 2);       // �Փ˃`�F�b�N�p��X���W2
            collisionZ1 = z + speed * -sin(angleY) + (carLengthX / 2) * cos(angleY);                                      // �Փ˃`�F�b�N�p��Z���W1
            collisionZ2 = z + speed * -sin(angleY) - (carLengthX / 2) * cos(angleY);                                       // �Փ˃`�F�b�N�p��Z���W2
            collisionZ3 = z + speed * -sin(angleY) + (carLengthX2 / 2) * cos(angleY) - carLengthZ * cos(angleY + M_PI / 2);                                       // �Փ˃`�F�b�N�p��Z���W2
            collisionZ4 = z + speed * -sin(angleY) - (carLengthX2 / 2) * cos(angleY) - carLengthZ * cos(angleY + M_PI / 2);                                       // �Փ˃`�F�b�N�p��Z���W2
        } 
        else if (shift == 1){
            angleY -= speed * handleAngle;
            //�Փ˂������Ŕ���
            double tmpX1, tmpX2, tmpX3, tmpX4, tmpZ1, tmpZ2, tmpZ3, tmpZ4;
            int tmpGridX1, tmpGridX2, tmpGridX3, tmpGridX4, tmpGridZ1, tmpGridZ2, tmpGridZ3, tmpGridZ4;
            bool tmpCrushA = false, tmpCrushB = false;  //�Փ˔���
            tmpX1 = x + speed * cos(angleY) + (carLengthX / 2) * sin(angleY);       // �Փ˃`�F�b�N�p��X���W1
            tmpX2 = x + speed * cos(angleY) - (carLengthX / 2) * sin(angleY);       // �Փ˃`�F�b�N�p��X���W2
            tmpX3 = x + speed * cos(angleY) + (carLengthX2 / 2) * sin(angleY) - carLengthZ * sin(angleY + M_PI / 2);       // �Փ˃`�F�b�N�p��X���W2
            tmpX4 = x + speed * cos(angleY) - (carLengthX2 / 2) * sin(angleY) - carLengthZ * sin(angleY + M_PI / 2);        // �Փ˃`�F�b�N�p��X���W2
            tmpZ1 = z + speed * -sin(angleY) + (carLengthX / 2) * cos(angleY);                                  // �Փ˃`�F�b�N�p��Z���W1
            tmpZ2 = z + speed * -sin(angleY) - (carLengthX / 2) * cos(angleY);                                       // �Փ˃`�F�b�N�p��Z���W2
            tmpZ3 = z + speed * -sin(angleY) + (carLengthX2 / 2) * cos(angleY) - carLengthZ * cos(angleY + M_PI / 2);                                       // �Փ˃`�F�b�N�p��Z���W2
            tmpZ4 = z + speed * -sin(angleY) - (carLengthX2 / 2) * cos(angleY) - carLengthZ * cos(angleY + M_PI / 2);                                       // �Փ˃`�F�b�N�p��Z���W2
            tmpGridX1 = SystemMain::getIns()->game.field.getFieldX(tmpX1);
            tmpGridX2 = SystemMain::getIns()->game.field.getFieldX(tmpX2);
            tmpGridX3 = SystemMain::getIns()->game.field.getFieldX(tmpX3);
            tmpGridX4 = SystemMain::getIns()->game.field.getFieldX(tmpX4);
            tmpGridZ1 = SystemMain::getIns()->game.field.getFieldX(tmpZ1);
            tmpGridZ2 = SystemMain::getIns()->game.field.getFieldX(tmpZ2);
            tmpGridZ3 = SystemMain::getIns()->game.field.getFieldX(tmpZ3);
            tmpGridZ4 = SystemMain::getIns()->game.field.getFieldX(tmpZ4);
            tmpCrushB = (SystemMain::getIns()->game.field.checkFieldValue(tmpGridX1, tmpGridZ1) == 0);
            tmpCrushB = tmpCrushB || (SystemMain::getIns()->game.field.checkFieldValue(tmpGridX2, tmpGridZ2) == 0);
            tmpCrushA = (SystemMain::getIns()->game.field.checkFieldValue(tmpGridX3, tmpGridZ3) == 0);
            tmpCrushA = tmpCrushA || (SystemMain::getIns()->game.field.checkFieldValue(tmpGridX4, tmpGridZ4) == 0);
            if (tmpCrushA) {
                //�Փ�
                money -= 25000 * abs(speed);           // �C����
                Sound::getIns()->playSE7();
                double e = 0.2; //�����W��
                speed = -speed * e - 0.1;      //�Z�����Ŕ������񂾂���
            }
            else if (tmpCrushB) {
                //�Փ�
                money -= 25000 * abs(speed);           // �C����
                Sound::getIns()->playSE7();
                double e = 0.2; //�����W��
                speed = speed * e + 0.1;      //�Z�����Ŕ������񂾂���
            }
            x -= speed * cos(angleY);
            z -= speed * -sin(angleY);
            collisionX1 = x + speed * cos(angleY) + (carLengthX / 2) * sin(angleY);       // �Փ˃`�F�b�N�p��X���W1
            collisionX2 = x + speed * cos(angleY) - (carLengthX / 2) * sin(angleY);       // �Փ˃`�F�b�N�p��X���W2
            collisionX3 = x + speed * cos(angleY) + (carLengthX2 / 2) * sin(angleY) - carLengthZ * sin(angleY + M_PI / 2);       // �Փ˃`�F�b�N�p��X���W2
            collisionX4 = x + speed * cos(angleY) - (carLengthX2 / 2) * sin(angleY) - carLengthZ * sin(angleY + M_PI / 2);       // �Փ˃`�F�b�N�p��X���W2
            collisionZ1 = z + speed * -sin(angleY) + (carLengthX / 2) * cos(angleY);                                      // �Փ˃`�F�b�N�p��Z���W1
            collisionZ2 = z + speed * -sin(angleY) - (carLengthX / 2) * cos(angleY);                                       // �Փ˃`�F�b�N�p��Z���W2
            collisionZ3 = z + speed * -sin(angleY) + (carLengthX2 / 2) * cos(angleY) - carLengthZ * cos(angleY + M_PI / 2);                                       // �Փ˃`�F�b�N�p��Z���W2
            collisionZ4 = z + speed * -sin(angleY) - (carLengthX2 / 2) * cos(angleY) - carLengthZ * cos(angleY + M_PI / 2);                                       // �Փ˃`�F�b�N�p��Z���W2
        }
    }

    if (money < 0) {
        money = 0;
    }

    if (SystemMain::getIns()->key.getKeyXON() > 0) { // ���C�g�؂�ւ�
        if (!lightChanged) {
            lightSwitch = !lightSwitch;
            lightChanged = true;        //�A���Ő؂�ւ��Ȃ��悤�ɂ���
            Sound::getIns()->playSE2();
        }
    }
    else {
        lightChanged = false;
    }
    if (lightSwitch) {
        power += 0.01;
    }
    fuel -= power; // �G���W���؂�Ȃ��ƔR������ ���ƃ��C�g�Ƃ�
    if (fuel < 0 ) {
        if (money > 10000) {
            money -= 10000;
            fuel = 50;
        }
        else {
            fuel = 0;
        }
    }

    //y�����̍X�V
    if (SystemMain::getIns()->game.field.checkFieldValue(FieldX, FieldZ) == 0) {
        //����Ȃ�(�^�ォ�猩��)
        if (!inTheWall) {
            double e = 0.2; //�����W��
            speed = -speed * e;      //�Z�����Ŕ������񂾂���
            inTheWall = true;
        }
    }
    else {
        inTheWall = false;
        //���ꂠ��
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
            // -0.5�܂łȂ痎���Ȃ�
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

    //�ԑ̗̂h��
    bodyAngle = 0.4 * abs(speed) * handleAngle * (180 / M_PI);
    //bodyAngle = -2.4 * abs(speed) * handleAngle * (180 / M_PI); //�o�C�N�p

    //�O���b�h���W���X�V
    FieldX = SystemMain::getIns()->game.field.getFieldX(x);
    FieldZ = SystemMain::getIns()->game.field.getFieldZ(z);

    //�J�����ʒu�̍X�V
    SystemMain::getIns()->game.camera.setX(x - 12 * cos(angleY));
    SystemMain::getIns()->game.camera.setY(y + 3.5);
    SystemMain::getIns()->game.camera.setZ(z + 12 * sin(angleY));
    //SystemMain::getIns()->game.camera.setX(x - 22 * cos(angleY));
    //SystemMain::getIns()->game.camera.setY(y + 8.5);
    //SystemMain::getIns()->game.camera.setZ(z + 22 * sin(angleY));
    SystemMain::getIns()->game.camera.setTargetX(x - 10 * cos(angleY + M_PI));
    SystemMain::getIns()->game.camera.setTargetY(1.0);
    SystemMain::getIns()->game.camera.setTargetZ(z + 10 * sin(angleY + M_PI));

    // �w�b�h���C�g�ʒu�̍X�V
    headLight.setHeadLightPosX(x);
    headLight.setHeadLightPosY(y);
    headLight.setHeadLightPosZ(z);
    headLight.setAngle(angleY);
    headLight.setLightValid(isFuelRemaining() && lightSwitch);
    headLight.update();

    //�V�t�g���o�[�̍X�V
    shiftLever.update();

    //�A�N�Z���E�u���[�L�̍X�V
    pedalAccel.update();
    pedalBrake.update();

    //�J�[�i�r�̍X�V
    carNavi.setPlayerX(FieldX);
    carNavi.setPlayerZ(FieldZ);
    carNavi.setPlayerPosX(SystemMain::getIns()->game.field.getFieldRemainderX(x));
    carNavi.setPlayerPosZ(SystemMain::getIns()->game.field.getFieldRemainderZ(z));

    //�X�s�[�h���[�^�[�̍X�V
    speedMeter.setSpeed(speed);
    speedMeter.update();

    //�R���̍X�V
    fuelMeter.setFuel(fuel);

    // 7�Z�O�̍X�V
    //�^�C�}�[
    timer = glutGet(GLUT_ELAPSED_TIME);
    int second, minute, conma;
    conma = (timer - timerStart) / 10;
    second = (timer - timerStart) / 1000;
    minute = second / 60;
    second = second % 60;
    minute = minute % 60;
    segment.setLampTimeState(5, conma % 10);
    segment.setLampTimeState(4, (conma / 10) % 10);
    segment.setLampTimeState(3, second % 10);
    segment.setLampTimeState(2, (second / 10) % 10);
    segment.setLampTimeState(1, minute % 10);
    segment.setLampTimeState(0, (minute / 10) % 10);

    //�t���[�����[�g�̌v�Z
    //static int frameCount;
    //static double frameTimer = glutGet(GLUT_ELAPSED_TIME);
    //int i;
    //frameCount++;
    //if ((timer - frameTimer) > 1000) {
    //    frameTimer = glutGet(GLUT_ELAPSED_TIME);
    //    frameCount = 0;
    //}
    //for (i = 0; i < 8; i++) {
    //    segment.setLampState(7 - i, (int)((frameCount / (timer - frameTimer)) * pow(10, 7 - i)) % 10);
    //}
    int i;

    for (i = 0; i < 8; i++) {
        segment.setLampState(i, (int)(money * pow(10, - (7 - i))) % 10);
    }
    if (lapNumber >= 0) {
        segment.setLampCharAState(5, lapNumber % 10);
    }

    /*
    �������牺�̓T�E���h�֘A�̏��� ���Ȃ薳���
    �Đ��̂��тɓ��삪��~����
    */

    bool disableSound = false;
    if (!disableSound) {
        static int brank = 6831;
        static int brankSE1 = 2631;
        static int brankSE4 = 3631;
        static int brankSE5 = 21631;
        static bool ValidSE1 = false; //����
        static bool ValidSE3 = false; //�A�C�h��
        static bool ValidSE4 = false; //������
        static bool ValidSE5 = false; //���s��
        static int tmpSound = 0;
        static int currentSound = -1;
        static double timeForBGM;
        static double timerForSound;
        static bool isBGMlooped = false;

        segment.setLampBState(0, currentSound);
        segment.setLampBState(1, tmpSound);

        if ((int)((timer - timerStart) / 1000) % 60 == 0) {
            if (!isBGMlooped) {
                Sound::getIns()->playMainBGM();
                isBGMlooped = true;
            }
        }
        else {
            isBGMlooped = false;
        }

        if (currentSound != tmpSound) {
            //�O�̉����~�߂�
            //Sound::getIns()->pauseSE(tmpSound);
            tmpSound = currentSound;
            soundChange = true;
            timerForSound = glutGet(GLUT_ELAPSED_TIME);
        }
        else {
            soundChange = false;
        }

        if ((currentSound == 1 || currentSound == 2 || currentSound == 4) && SystemMain::getIns()->key.getKeyDownON() && speed > 0) { //���s���̃u���[�L
            currentSound = 4;
            Sound::getIns()->pauseSE4();
            Sound::getIns()->pauseSE5();
            if ((timer - timerForSound) - brankSE1 * (int)((timer - timerForSound) / brankSE1) < 1000) {  // ���̃��[�v�𖳗�������ł��
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
                if ((timer - timerForSound) - brankSE5 * (int)((timer - timerForSound) / brankSE5) < 1000) {  // ���̃��[�v�𖳗�������ł��
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
}