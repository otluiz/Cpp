#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QApplication>
#include <QPushButton>
/*
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
*/

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QPushButton button ("Hello world!!");
  button.show();

  return app.exec();
}
