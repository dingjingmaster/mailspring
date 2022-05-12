//
// Created by dingjing on 5/12/22.
//

#include <QApplication>
#include "main-window.h"

int main (int argc, char* argv[])
{
    QApplication app (argc, argv);

    MainWindow w;
    w.show ();

    return app.exec();
}