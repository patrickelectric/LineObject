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
        // rand() is only positive
        v.setX(5 + rand() % s/2);
        v.setY(5 + rand() % s/2);
        v.setZ(rand() % s/2);
    }

    auto geometry = new LineMeshGeometry(vertices, this);
    setVertexCount(geometry->vertexCount());
    setGeometry(geometry);
}

LineMesh::~LineMesh()
{
    //Qt3DCore::QNode::cleanup();
}
