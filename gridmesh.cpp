#include <Qt3DRender/QGeometryRenderer>
#include <QVector4D>
#include <QVector3D>
#include <QVector2D>

#include "linemeshgeometry.h"
#include "gridmesh.h"

GridMesh::GridMesh(Qt3DCore::QNode *parent)
    : Qt3DRender::QGeometryRenderer(parent)
{
    setInstanceCount(1);
    setIndexOffset(0);
    setFirstInstance(0);
    setPrimitiveType(Qt3DRender::QGeometryRenderer::Lines);

    QVector2D s(20, 20);
    QList<QVector4D> vertices;
    for (uint i = 0; i <= s.x(); i+=s.x()/20) {
        for (uint j = 0; j <= s.y(); j+=s.y()/20) {
            vertices.append(QVector4D(i, 0, 0, 0));
            vertices.append(QVector4D(i, j, 0, 0));

            vertices.append(QVector4D(0, j, 0, 0));
            vertices.append(QVector4D(i, j, 0, 0));
        }
    }

    auto geometry = new LineMeshGeometry(vertices, this);
    setVertexCount(geometry->vertexCount());
    setGeometry(geometry);
}

GridMesh::~GridMesh()
{
    //Qt3DCore::QNode::cleanup();
}
