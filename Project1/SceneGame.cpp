#include "SceneGame.h"
#include "SystemMain.h"

SceneGame::SceneGame() {
    player.setX(field.getFieldGridSize());
    player.setY(0.0);
    player.setZ(field.getFieldGridSize());
    player.setDefX(field.getFieldGridSize());
    player.setDefY(field.getFieldGridSize());
    player.setDefZ(field.getFieldGridSize());
    player.fieldNumber = field.getFieldGridNumber();
    player.setMapSize();
}

void SceneGame::draw() {
    SystemMain::getIns()->view2D();                   // ���Ԃɒ��� �w�i�p
    backGround.draw();

    GLfloat globalAmbient[] = { 0.0, 0.0, 0.0, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    glViewport(0, SystemMain::getIns()->winH / 4, SystemMain::getIns()->winW, SystemMain::getIns()->winH); //�r���[�|�[�g�𒲐�
    SystemMain::getIns()->view3D();
    camera.setLookAt();  // �J�����ʒu����v���C���[������
    GLfloat lightPosition[4] = { 0.0, 5.0, 0.0, 1.0 }; //�����̈ʒu
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0f };    //����
    GLfloat  light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };      //�g�U��
    GLfloat  light_specular[] = { 0.81f, 0.81f, 0.81f, 1.0f };     //���ʌ�
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0001);   //���̌���
    field.draw();
    player.draw();

    glViewport(0, SystemMain::getIns()->winH * (3 / 4), SystemMain::getIns()->winW, SystemMain::getIns()->winH); //�r���[�|�[�g�𒲐�
    SystemMain::getIns()->view2D();                   // �C���^�t�F�[�X�p�w�i
    info.draw();

    SystemMain::getIns()->view3DForUI();
    GLfloat lightPosition2[4] = { 50.0, 100.0, 100.0, 0.0 }; //�����̈ʒu
    GLfloat light_ambient2[] = { 0.9f, 0.9f, 0.9f, 1.0f };    //����
    GLfloat  light_diffuse2[] = { 0.2f, 0.2f, 0.2f, 1.0f };      //�g�U��
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition2);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
    gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    player.drawInfo();

    SystemMain::getIns()->view2D();
    player.drawInfo2D();
}

void SceneGame::update() {
    //�e�C���X�^���X��update�����s
    player.update();
    field.update();

    if (SystemMain::getIns()->key.getKeyEscON()) {
        SystemMain::getIns()->changeScene(0); //�G�X�P�[�v�L�[�������ꂽ��^�C�g���ɖ߂�(�|�[�Y��ʏo���đJ�ڂ�������)
    }
}