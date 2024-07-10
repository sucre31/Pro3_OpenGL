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
    glEnable(GL_LIGHTING);  //光源の設定を有効にする
    glEnable(GL_LIGHT0);    //0番目の光源を有効にする(8個まで設定可能)
    glEnable(GL_NORMALIZE); //法線ベクトルの自動正規化を有効

    glShadeModel(GL_SMOOTH); //スムーズシェーディングに設定

}

void SystemMain::textureInit(void) {

    //static double genfunc[][4] = {   /* テクスチャ生成関数のパラメータ */
    //    { 1.0, 0.0, 0.0, 0.0 },
    //    { 0.0, 1.0, 0.0, 0.0 },
    //};

    ///* 頂点のオブジェクト空間における座標値をテクスチャ座標に使う */
    //glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    //glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

    ///* テクスチャ座標生成関数の設定 */
    //glTexGendv(GL_S, GL_OBJECT_PLANE, genfunc[0]);
    //glTexGendv(GL_T, GL_OBJECT_PLANE, genfunc[1]);
    glEnable(GL_DEPTH_TEST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // テクスチャの拡大設定
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // テクスチャの縮小設定
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    Texture::getIns()->setTexture(1);
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

void SystemMain::keyboard(unsigned char key, int x, int y)             // 指定時間後に呼び出される関数（Timerコールバック関数）
{
    SystemMain::getIns()->keyboardCall(key, x, y);
}

void SystemMain::keyboardUp(unsigned char key, int x, int y)             // 指定時間後に呼び出される関数（Timerコールバック関数）
{
    SystemMain::getIns()->keyboardUpCall(key, x, y);
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
    glClearColor(0.0, 0.0, 0.0, 1.0); // 画面クリア
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    view2D();                   // 順番に注意 背景用
    //backGround.draw();

    GLfloat globalAmbient[] = { 0.0, 0.0, 0.0, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    glViewport(0, winH / 4, winW, winH ); //ビューポートを調整
    view3D();
    gluLookAt(camera.getX(), camera.getY(),camera.getZ(), camera.getTargetX(), camera.getTargetY() + 2, camera.getTargetZ(), 0.0, 1.0, 0.0);  // カメラ位置からプレイヤーを見る
    GLfloat lightPosition[4] = { 0.0, 5.0, 0.0, 1.0 }; //光源の位置
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0f };    //環境光
    GLfloat  light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };      //拡散光
    GLfloat  light_specular[] = { 0.81f, 0.81f, 0.81f, 1.0f };     //鏡面光
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0006);   //光の減衰
    field.draw();
    player.draw();

    glViewport(0, winH * (3 / 4), winW, winH); //ビューポートを調整
    view2D();                   // インタフェース用背景
    info.draw();

    view3D();
    GLfloat lightPosition2[4] = { 50.0, 100.0, 100.0, 0.0 }; //光源の位置
    GLfloat light_ambient2[] = { 0.9f, 0.9f, 0.9f, 1.0f };    //環境光
    GLfloat  light_diffuse2[] = { 0.2f, 0.2f, 0.2f, 1.0f };      //拡散光
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition2);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
    gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    player.drawInfo();

    view2D();
    player.drawInfo2D();

    glutSwapBuffers(); // バッファの切り替え


}

void SystemMain::update() {
    //各インスタンスのupdateを実行
    player.update();
    field.update();
    //描画依頼
    glutPostRedisplay();
    //次タイマー登録
    glutTimerFunc(30, SystemMain::getIns()->timerFunc, 0);
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
    gluPerspective(30.0, (double)winW / winH, 1.0, 1000.0); // 透視投影
    glMatrixMode(GL_MODELVIEW);// モデルビュー変換行列設定
    glLoadIdentity();// 単位行列を設定
    glEnable(GL_DEPTH_TEST); // 隠面消去を有効
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