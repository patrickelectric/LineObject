#pragma once

#include <QObject>
#include <Qt3DCore/QNode>
#include <Qt3DRender/QGeometryRenderer>
#include <QVector4D>
#include <QList>

class LineMeshGeometry;

class LineMeshPart : public Qt3DRender::QGeometryRenderer
{
    Q_OBJECT
public:
    explicit LineMeshPart(Qt3DCore::QNode *parent = Q_NULLPTR);
    ~LineMeshPart();
    Q_INVOKABLE void start();

private:
    QList<QVector4D> _vertices;
    LineMeshGeometry *_lineMeshGeo;
    void posUpdate(QList<QVector4D> pos);
};
