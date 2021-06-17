//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include <QApplication>
#include <QLabel>


int main(int argc, char *argv[])
{

   /*
    * QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    * QQmlApplicationEngine engine;
    * engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    * if (engine.rootObjects().isEmpty())
    *    return -1;
    */

    QApplication app(argc, argv);
    QLabel *label = new QLabel("Hello World");
    label->setWindowTitle("MEU APP");
    label->resize(400,400);
    label->show();

    return app.exec();
}
