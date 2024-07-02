#include <glut.h>
#include "SystemMain.h"
#include "Define.h"
//#define GL_SILENCE_DEPRECATION //MacOSの場合でエラーを表示させない場合
//#include <GLUT/glut.h> //MacOSの場合
//#include <GL/glut.h> //Linuxの場合

//    GLUT を使用した時にコンソールウインドウを表示しない
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // GLUT初期化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(Define::WIN_W, Define::WIN_H); // ウィンドウサイズの指定
    glutCreateWindow("PUZZLE");   // 表示ウィンドウ作成
    glutReshapeFunc(SystemMain::getIns()->reshape);       // Reshapeコールバック関数の指定
    glutDisplayFunc(SystemMain::getIns()->display);     // Displayコールバック関数の指定
    glutSpecialFunc(SystemMain::getIns()->specialKey);                    // 特殊キーコールバック関数の指定(押したとき)
    glutTimerFunc(30, SystemMain::getIns()->timerFunc, 0);  // 定期的に呼び出される関数の指定

    SystemMain::getIns()->lightInit();   // 光源の初期設定(まとめて関数にしているだけ)

    glutMainLoop();               // メインループへ
    return 0;
}