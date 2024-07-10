#include <complex>
#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Player.h"
#include "SystemMain.h"

Player::Player() : x(0.0), y(0.0), z(0.0),velY(0.0), angleY(-M_PI / 2), speed(0.0), speedMax(1.0), accel(0.01), brake(0.02), handling(0.2 * M_PI / 360), handleAngle(0.0), handleAngleMax(8 * M_PI / 360) {
    lightSwitch = true;
    lightChanged = false;
    fuel = 200;
    fuelMax = 200;
    fuelMeter.setFuel(fuel);
    fuelMeter.setFuelMax(fuelMax);
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
        GLfloat mat0ambi[] = { 0.329412,  0.223529, 0.027451, 1.0 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //�����̔��˗���ݒ�
        GLfloat mat0diff[] = { 0.780392,  0.568627, 0.113725, 1.0 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //�g�U���̔��˗���ݒ�
        GLfloat mat0spec[] = { 0.992157,  0.941176, 0.807843, 1.0 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //���ʌ��̔��˗���ݒ�
        GLfloat mat0shine[] = { 27.89743616 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
        GLfloat materialEmission[] = { 0.0, 0.0, 0.0, 1.0 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialEmission);
        //���@�̕`��
        glTranslatef(x, y, z); //�ʒu�ϐ������ƂɈړ�
        glRotatef(angleY * (180 / M_PI) + 1.5 * handleAngle * (180 / M_PI), 0.0, 1.0, 0.0);  //Y���܂���angleY(���W�A��)��] handleAngle���l��
        glutSolidTeapot(1.0);            //���@�̓e�B�[�|�b�g(��)
    }glPopMatrix();

    headLight.draw();
}

void Player::drawInfo() {
    shiftLever.draw();
    drawHandle();
    pedalAccel.draw();
    pedalBrake.draw();
    drawSpeed();
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

void Player::drawSpeed() {
    glPushMatrix(); {       //�X�s�[�h���[�^�[
        GLfloat mat0ambi[] = { 0.59225,  0.19225, 0.19225, 1.0 };//��
        GLfloat mat0diff[] = { 0.60754,  0.50754, 0.50754, 1.0 };
        GLfloat mat0spec[] = { 0.608273,  0.508273, 0.508273, 1.0 };
        GLfloat mat0shine[] = { 51.2 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //�����̔��˗���ݒ�
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //�g�U���̔��˗���ݒ�
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //���ʌ��̔��˗���ݒ�
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);

        // �`��
        glTranslatef(0.3 * -cos(( 150 * (speed / speedMax) - 225) * (M_PI / 180)), 0.3 * -sin((150 * (speed / speedMax) - 225) * (M_PI / 180)), 0.0);
        glPushMatrix(); {
            glTranslatef(-2.0, -2.1f, 0.0);
            glRotatef(150 * (speed / speedMax) - 135, 0.0, 0.0, 1.0);
            glScalef(0.01, 0.5, 0.01);
            glPushMatrix(); {
                glutSolidCube(1.0);
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
        handleAngle -= (5.0 * handleAngle) * M_PI / 360;
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
        speed -= brake;
    } 
    else {
        //speed += 0.001;             //�N���[�v����
    }
    speed -= 0.004;       //�������Ȃ��Ă����x�͌���
    if (speed > speedMax) { //���Ďv������X�s�[�h����
        speed = speedMax;
    }
    if (speed < 0) {
        speed = 0;
    }
    if (speed == 0) {       //���x��0�̂Ƃ������V�t�g����
        if (SystemMain::getIns()->key.getKeyZON() > 0) {
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
    if (SystemMain::getIns()->key.getKeyXON() > 0) {
        if (!lightChanged) {
            lightSwitch = !lightSwitch;
            lightChanged = true;        //�A���Ő؂�ւ��Ȃ��悤�ɂ���
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
        fuel = 0;
    }

    //y�����̍X�V
    if (SystemMain::getIns()->field.checkFieldValue(FieldX, FieldZ) == 0) {
        //����Ȃ�(�^�ォ�猩��)
        speed = 0;      //�Z�����Ŕ������񂾂���

    }
    else {
        //���ꂠ��
        if (y < -0.5) {
            velY -= 0.1;
            y += velY;
        }
        else if (y > 0) {
            velY -= 0.1;
            y += velY; 
            if (y < 0) {
                y = 0;
            }
        }
        else {
            // -0.5�܂łȂ痎���Ȃ�
            y = 0;
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

    //�O���b�h���W���X�V
    FieldX = SystemMain::getIns()->field.getFieldX(x);
    FieldZ = SystemMain::getIns()->field.getFieldZ(z);

    //�J�����ʒu�̍X�V
    SystemMain::getIns()->camera.setX(x - 1 * cos(angleY));
    SystemMain::getIns()->camera.setY(y + 1.5);
    SystemMain::getIns()->camera.setZ(z + 1 * sin(angleY));
    SystemMain::getIns()->camera.setTargetX(x - 10 * cos(angleY + M_PI));
    SystemMain::getIns()->camera.setTargetY(-1.0);
    SystemMain::getIns()->camera.setTargetZ(z + 10 * sin(angleY + M_PI));

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

    //�R���̍X�V
    fuelMeter.setFuel(fuel);
}