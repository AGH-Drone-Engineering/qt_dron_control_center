#include "mainwindow.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{


    QApplication app(argc, argv);

    QFile file(":/style.qss");  // właśnie z zasobów
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream in(&file);
        QString styleSheet = in.readAll();
        app.setStyleSheet(styleSheet);
    }



    MainWindow w;
    w.showMaximized();
    w.show();
    return app.exec();
}
