#pragma once

#include <QObject>
#include <Qt3DCore/QNode>
#include <Qt3DRender/QGeometryRenderer>
#include <QVector4D>
#include <QList>

class LineMeshGeometry;

class LineMesh : public Qt3DRender::QGeometryRenderer
{
    Q_OBJECT
public:
    explicit LineMesh(Qt3DCore::QNode *parent = Q_NULLPTR);
    ~LineMesh();
    void posUpdate(QList<QVector4D> pos);

signals:
    void finished();

private:
    QList<QVector4D> _vertices;
    LineMeshGeometry *_lineMeshGeo;
};
