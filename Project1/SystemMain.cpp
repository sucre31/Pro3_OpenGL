#include <glut.h>
#include "SystemMain.h"
#include "Define.h"
#include "Texture.h"

SystemMain::SystemMain() {
    player.setX(field.getFieldGridSize());
    player.setY(0.0);
    player.setZ(field.getFieldGridSize());
    player.setDefX(field.getFieldGridSize());
    player.setDefY(field.getFieldGridSize());
    player.setDefZ(field.getFieldGridSize());
}

void SystemMain::lightInit(void) {
    glEnable(GL_LIGHTING);  //�����̐ݒ��L���ɂ���
    glEnable(GL_LIGHT0);    //0�Ԗڂ̌�����L���ɂ���(8�܂Őݒ�\)
    glEnable(GL_NORMALIZE); //�@���x�N�g���̎������K����L��

    glShadeModel(GL_SMOOTH); //�X���[�Y�V�F�[�f�B���O�ɐݒ�

}

void SystemMain::textureInit(void) {

    //static double genfunc[][4] = {   /* �e�N�X�`�������֐��̃p�����[�^ */
    //    { 1.0, 0.0, 0.0, 0.0 },
    //    { 0.0, 1.0, 0.0, 0.0 },
    //};

    ///* ���_�̃I�u�W�F�N�g��Ԃɂ�������W�l���e�N�X�`�����W�Ɏg�� */
    //glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    //glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

    ///* �e�N�X�`�����W�����֐��̐ݒ� */
    //glTexGendv(GL_S, GL_OBJECT_PLANE, genfunc[0]);
    //glTexGendv(GL_T, GL_OBJECT_PLANE, genfunc[1]);
    glEnable(GL_DEPTH_TEST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // �e�N�X�`���̊g��ݒ�
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // �e�N�X�`���̏k���ݒ�
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
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

    view2D();                   // ���Ԃɒ��� �w�i�p
    //backGround.draw();

    GLfloat globalAmbient[] = { 0.0, 0.0, 0.0, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    glViewport(0, winH / 4, winW, winH ); //�r���[�|�[�g�𒲐�
    view3D();
    gluLookAt(camera.getX(), camera.getY(),camera.getZ(), camera.getTargetX(), camera.getTargetY() + 2, camera.getTargetZ(), 0.0, 1.0, 0.0);  // �J�����ʒu����v���C���[������
    GLfloat lightPosition[4] = { 0.0, 5.0, 0.0, 1.0 }; //�����̈ʒu
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0f };    //����
    GLfloat  light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };      //�g�U��
    GLfloat  light_specular[] = { 0.81f, 0.81f, 0.81f, 1.0f };     //���ʌ�
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0006);   //���̌���
    field.draw();
    player.draw();

    glViewport(0, winH * (3 / 4), winW, winH); //�r���[�|�[�g�𒲐�
    view2D();                   // �C���^�t�F�[�X�p�w�i
    info.draw();

    view3D();
    GLfloat lightPosition2[4] = { 50.0, 100.0, 100.0, 0.0 }; //�����̈ʒu
    GLfloat light_ambient2[] = { 0.9f, 0.9f, 0.9f, 1.0f };    //����
    GLfloat  light_diffuse2[] = { 0.2f, 0.2f, 0.2f, 1.0f };      //�g�U��
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition2);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
    gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    player.drawInfo();

    view2D();
    player.drawInfo2D();

    glutSwapBuffers(); // �o�b�t�@�̐؂�ւ�


}

void SystemMain::update() {
    //�e�C���X�^���X��update�����s
    player.update();
    field.update();
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
    gluPerspective(30.0, (double)w / h, 1.0, 100.0); // �������e
    winH = h;
    winW = w;
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