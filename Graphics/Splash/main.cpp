#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *telaSplash = new QSplashScreen;
    telaSplash->setPixmap(QPixmap("/home/otluix/Workspace/C++/Graphics/Splash/splash600x500.png"));
    telaSplash->show();

    MainWindow w;

    QTimer::singleShot(6000,telaSplash,SLOT(close()));
    QTimer::singleShot(2000,&w,SLOT(show()));

    //w.show();

    return a.exec();
}
