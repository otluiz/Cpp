#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QWidget>
#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include <QSplashScreen>
#include <Qtimer>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QSplashScreen *telaSplash = new QSplashScreen;
  telaSplash->setPixmap(QPixmap("images/splash600x500.png"));
  telaSplash->show();

  MainWindow w;

  QTimer::singleShot(2000, telaSplash, SLOT(close()));
  QTimer::singleShot(2000, %w, SLOT(show()));
			

}
