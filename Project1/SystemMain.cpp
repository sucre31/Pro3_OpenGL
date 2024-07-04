#include <glut.h>
#include "SystemMain.h"
#include "Define.h"

void SystemMain::lightInit(void) {
    glEnable(GL_LIGHTING);  //光源の設定を有効にする
    glEnable(GL_LIGHT0);    //0番目の光源を有効にする(8個まで設定可能)
    glEnable(GL_NORMALIZE); //法線ベクトルの自動正規化を有効

    glShadeModel(GL_SMOOTH); //スムーズシェーディングに設定

}

void SystemMain::display() {
    SystemMain::getIns()->draw();
}

void SystemMain::reshape(int w, int h) {
    SystemMain::getIns()->reshapeFunc(w, h);
}

void SystemMain::timerFunc(int t)             // 指定時間後に呼び出される関数（Timerコールバック関数）
{
    SystemMain::getIns()->update();
}

void SystemMain::specialKey(int key, int x, int y)             // 指定時間後に呼び出される関数（Timerコールバック関数）
{
    SystemMain::getIns()->keyCall(key, x, y);
}

void SystemMain::specialKeyUp(int key, int x, int y)             // 指定時間後に呼び出される関数（Timerコールバック関数）
{
    SystemMain::getIns()->keyCallUp(key, x, y);
}

void SystemMain::draw() {
    glClearColor(0.1, 0.1, 0.1, 1.0); // 画面クリア
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    view2D();                   // 順番に注意 背景用
    backGround.draw();

    view3D();
    gluLookAt(camera.getX(), camera.getY(),camera.getZ(), player.getX(), player.getY() + 3, player.getZ(), 0.0, 1.0, 0.0);  // カメラ位置からプレイヤーを見る
    GLfloat lightPosition[4] = { 50.0, 100.0, 100.0, 10.0 }; //光源の位置
    GLfloat light_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };    //環境光
    GLfloat  light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };      //拡散光
    GLfloat  light_specular[] = { 0.1f, 0.1f, 0.1f, 1.0f };     //鏡面光
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    plate.draw();
    fieldData.draw();
    player.draw();

    glutSwapBuffers(); // バッファの切り替え


}

void SystemMain::reshapeFunc(int w, int h) // ウインドウサイズ変更時に呼び出される関数（Reshapeコールバック関数）
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)w / h, 1.0, 100.0); // 透視投影
    winH = h;
    winW = w;
}

void SystemMain::view2D() {
    glMatrixMode(GL_PROJECTION);// 射影変換行列設定
    glLoadIdentity();// 単位行列を設定
    glOrtho(0, Define::WIN_W, Define::WIN_H, 0, -1, 1);// 正射影変換設定
    glMatrixMode(GL_MODELVIEW);// モデルビュー変換行列設定
    glLoadIdentity();// 単位行列を設定
    glDisable(GL_LIGHTING); // ライティングを無効化
    glDisable(GL_DEPTH_TEST); // 隠面消去を無効
}

void SystemMain::view3D() {
    glEnable(GL_LIGHTING); // ライティングを有効化
    glMatrixMode(GL_PROJECTION);// 射影変換行列設定
    glLoadIdentity();
    gluPerspective(30.0, (double)winW / winH, 1.0, 100.0); // 透視投影
    glMatrixMode(GL_MODELVIEW);// モデルビュー変換行列設定
    glLoadIdentity();// 単位行列を設定
    glEnable(GL_DEPTH_TEST); // 隠面消去を有効
}

void SystemMain::update() {
    //各インスタンスのupdateを実行
    player.update();
    //描画依頼
    glutPostRedisplay();
    //次タイマー登録
    glutTimerFunc(30, SystemMain::getIns()->timerFunc, 0);
}

void SystemMain::keyCall(int key, int x, int y) {
    this->key.specialKey(key, x, y);
}

void SystemMain::keyCallUp(int key, int x, int y) {
    this->key.specialKeyUp(key, x, y);
}