#include <QGuiApplication>
#include <QtQuick/QQuickView>

#include "linemeshpart.h"
#include "linemesh.h"
#include "gridmesh.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<GridMesh>("GridMesh", 1, 0, "GridMesh");
    qmlRegisterType<LineMesh>("LineMesh", 1, 0, "LineMesh");
    qmlRegisterType<LineMeshPart>("LineMeshPart", 1, 0, "LineMeshPart");

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:///main.qml"));
    view.show();

    return app.exec();
}
