#include <QGuiApplication>
#include <QtQuick/QQuickView>

//#include "linemesh.h"
#include "gridmesh.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<GridMesh>("GridMesh", 1, 0, "GridMesh");

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:///main.qml"));
    view.show();

    return app.exec();
}
