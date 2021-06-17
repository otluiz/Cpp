#include <QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton botao ("Hello world");
    botao.show();

    return app.exec();
}
