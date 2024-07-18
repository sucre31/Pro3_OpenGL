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
    SystemMain::getIns()->view2D();                   // 順番に注意 背景用
    backGround.draw();

    GLfloat globalAmbient[] = { 0.0, 0.0, 0.0, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    glViewport(0, SystemMain::getIns()->winH / 4, SystemMain::getIns()->winW, SystemMain::getIns()->winH); //ビューポートを調整
    SystemMain::getIns()->view3D();
    camera.setLookAt();  // カメラ位置からプレイヤーを見る
    GLfloat lightPosition[4] = { 0.0, 5.0, 0.0, 1.0 }; //光源の位置
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0f };    //環境光
    GLfloat  light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };      //拡散光
    GLfloat  light_specular[] = { 0.81f, 0.81f, 0.81f, 1.0f };     //鏡面光
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0001);   //光の減衰
    field.draw();
    player.draw();

    glViewport(0, SystemMain::getIns()->winH * (3 / 4), SystemMain::getIns()->winW, SystemMain::getIns()->winH); //ビューポートを調整
    SystemMain::getIns()->view2D();                   // インタフェース用背景
    info.draw();

    SystemMain::getIns()->view3DForUI();
    GLfloat lightPosition2[4] = { 50.0, 100.0, 100.0, 0.0 }; //光源の位置
    GLfloat light_ambient2[] = { 0.9f, 0.9f, 0.9f, 1.0f };    //環境光
    GLfloat  light_diffuse2[] = { 0.2f, 0.2f, 0.2f, 1.0f };      //拡散光
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition2);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
    gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    player.drawInfo();

    SystemMain::getIns()->view2D();
    player.drawInfo2D();
}

void SceneGame::update() {
    //各インスタンスのupdateを実行
    player.update();
    field.update();

    if (SystemMain::getIns()->key.getKeyEscON()) {
        SystemMain::getIns()->changeScene(0); //エスケープキーが押されたらタイトルに戻る(ポーズ画面出して遷移させたい)
    }
}