#include <Qt3DRender/QGeometryRenderer>
#include <QVector3D>

#include "linemeshgeometry.h"
#include "linemesh.h"

LineMesh::LineMesh(Qt3DCore::QNode *parent)
    : Qt3DRender::QGeometryRenderer(parent)
{
    setInstanceCount(1);
    setIndexOffset(0);
    setFirstInstance(0);
    setPrimitiveType(Qt3DRender::QGeometryRenderer::LineStrip);

    QVector<QVector3D> vertices;
    vertices.resize(1e3);
    const int s = 20;
    for (auto& v : vertices) {
        v.setX(s/2 - rand() % s);
        v.setY(s/2 - rand() % s);
        v.setZ(s/2 - rand() % s);
    }

    auto geometry = new LineMeshGeometry(vertices, this);
    setVertexCount(geometry->vertexCount());
    setGeometry(geometry);
}

LineMesh::~LineMesh()
{
    //Qt3DCore::QNode::cleanup();
}
