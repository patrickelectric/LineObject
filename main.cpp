#include <QApplication>
#include <QtQuick/QQuickView>

#include "mainwindow.h"
#include "linemesh.h"
#include "gridmesh.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<GridMesh>("GridMesh", 1, 0, "GridMesh");
    qmlRegisterType<LineMesh>("LineMesh", 1, 0, "LineMesh");

    MainWindow view;
    //view.setResizeMode(QQuickView::SizeRootObjectToView);
    //view.setSource(QUrl("qrc:///main.qml"));
    view.show();

    return app.exec();
}
