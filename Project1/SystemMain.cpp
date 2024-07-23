#include <glut.h>
#include "SystemMain.h"
#include "Define.h"
#include "Texture.h"

SystemMain::SystemMain() {
    SceneNum = 0;
}

void SystemMain::lightInit(void) {
    glEnable(GL_LIGHTING);  //�����̐ݒ��L���ɂ���
    glEnable(GL_LIGHT0);    //0�Ԗڂ̌�����L���ɂ���(8�܂Őݒ�\)
    //glDisable(GL_LIGHT0);
    glEnable(GL_NORMALIZE); //�@���x�N�g���̎������K����L��

    glShadeModel(GL_SMOOTH); //�X���[�Y�V�F�[�f�B���O�ɐݒ�

}

void SystemMain::textureInit(void) {

    Texture::getIns()->initTexture();
    Texture::getIns()->setTexture(1);
}

void SystemMain::display() {
    SystemMain::getIns()->draw();
}

void SystemMain::reshape(int w, int h) {
    SystemMain::getIns()->reshapeFunc(w, h);
}

void SystemMain::timerFunc(int t)             // �w�莞�Ԍ�ɌĂяo�����֐��iTimer�R�[���o�b�N�֐��j
{
    SystemMain::getIns()->update();
}

void SystemMain::keyboard(unsigned char key, int x, int y)             // �w�莞�Ԍ�ɌĂяo�����֐��iTimer�R�[���o�b�N�֐��j
{
    SystemMain::getIns()->keyboardCall(key, x, y);
}

void SystemMain::keyboardUp(unsigned char key, int x, int y)             // �w�莞�Ԍ�ɌĂяo�����֐��iTimer�R�[���o�b�N�֐��j
{
    SystemMain::getIns()->keyboardUpCall(key, x, y);
}

void SystemMain::specialKey(int key, int x, int y)             // �w�莞�Ԍ�ɌĂяo�����֐��iTimer�R�[���o�b�N�֐��j
{
    SystemMain::getIns()->keyCall(key, x, y);
}

void SystemMain::specialKeyUp(int key, int x, int y)             // �w�莞�Ԍ�ɌĂяo�����֐��iTimer�R�[���o�b�N�֐��j
{
    SystemMain::getIns()->keyCallUp(key, x, y);
}

void SystemMain::draw() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // ��ʃN���A
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    switch (SceneNum) {
    case 0:
        title.draw();
        break;
    case 1:
        game.draw();
        break;
    }

    glutSwapBuffers(); // �o�b�t�@�̐؂�ւ�
}

void SystemMain::update() {

    // �V�[���̐؂�ւ��������ł���Ă��܂�
    switch (SceneNum) {
    case 0:
        title.update();
        break;
    case 1:
        game.update();
        break;
    }
    
    //�`��˗�
    glutPostRedisplay();
    //���^�C�}�[�o�^
    glutTimerFunc(30, SystemMain::getIns()->timerFunc, 0);
}

void SystemMain::reshapeFunc(int w, int h) // �E�C���h�E�T�C�Y�ύX���ɌĂяo�����֐��iReshape�R�[���o�b�N�֐��j
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)w / h, 10.0, 100.0); // �������e
    winH = h;
    winW = w;

    glutReshapeWindow(Define::WIN_W, Define::WIN_H); //������T�C�Y���Œ肷��
}

void SystemMain::view2D() {
    glMatrixMode(GL_PROJECTION);// �ˉe�ϊ��s��ݒ�
    glLoadIdentity();// �P�ʍs���ݒ�
    glOrtho(0, Define::WIN_W, Define::WIN_H, 0, -1, 1);// ���ˉe�ϊ��ݒ�
    glMatrixMode(GL_MODELVIEW);// ���f���r���[�ϊ��s��ݒ�
    glLoadIdentity();// �P�ʍs���ݒ�
    glDisable(GL_LIGHTING); // ���C�e�B���O�𖳌���
    glDisable(GL_DEPTH_TEST); // �B�ʏ����𖳌�
}

void SystemMain::view3D() {
    glEnable(GL_LIGHTING); // ���C�e�B���O��L����
    glMatrixMode(GL_PROJECTION);// �ˉe�ϊ��s��ݒ�
    glLoadIdentity();
    gluPerspective(30.0, (double)winW / winH, 8.5, 1000.0); // �������e
    glMatrixMode(GL_MODELVIEW);// ���f���r���[�ϊ��s��ݒ�
    glLoadIdentity();// �P�ʍs���ݒ�
    glEnable(GL_DEPTH_TEST); // �B�ʏ�����L��
}

void SystemMain::view3DForUI() {
    glEnable(GL_LIGHTING); // ���C�e�B���O��L����
    glMatrixMode(GL_PROJECTION);// �ˉe�ϊ��s��ݒ�
    glLoadIdentity();
    gluPerspective(30.0, (double)winW / winH, 1.0, 1000.0); // �������e
    glMatrixMode(GL_MODELVIEW);// ���f���r���[�ϊ��s��ݒ�
    glLoadIdentity();// �P�ʍs���ݒ�
    glEnable(GL_DEPTH_TEST); // �B�ʏ�����L��
}


void SystemMain::keyboardCall(unsigned char key, int x, int y) {
    this->key.keyboard(key, x, y);
}

void SystemMain::keyboardUpCall(unsigned char key, int x, int y) {
    this->key.keyboardUp(key, x, y);
}

void SystemMain::keyCall(int key, int x, int y) {
    this->key.specialKey(key, x, y);
}

void SystemMain::keyCallUp(int key, int x, int y) {
    this->key.specialKeyUp(key, x, y);
}

void SystemMain::changeScene(int Num) {
    SceneNum = Num;
}