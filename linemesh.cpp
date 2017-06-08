#include <Qt3DRender/QGeometryRenderer>
#include <QVector3D>
#include <QDebug>

#include "linemeshgeometry.h"
#include "linemesh.h"
#include "gcodeto3d.h"

LineMesh::LineMesh(Qt3DCore::QNode *parent)
    : Qt3DRender::QGeometryRenderer(parent)
{
    setInstanceCount(1);
    setIndexOffset(0);
    setFirstInstance(0);
    setPrimitiveType(Qt3DRender::QGeometryRenderer::LineStrip);

    QList<QVector4D> vertices;
    int total = 1e3;
    const int s = 20;
    while (total --> 0) {
        vertices.append(QVector4D(s/4 + rand()%s/2, s/4 + rand()%s/2, rand()%s/2, 0));
    }

    auto gcode = new GcodeTo3D();
    qRegisterMetaType<QList<QVector4D> >("QList<QVector4D>");
    connect(gcode, &GcodeTo3D::posUpdate, this, &LineMesh::posUpdate);
    gcode->read("test2.gcode");
}

void LineMesh::posUpdate(QList<QVector4D> pos) {
    _vertices = pos;
    auto geometry = new LineMeshGeometry(_vertices, this);
    setVertexCount(geometry->vertexCount());
    setGeometry(geometry);
}

LineMesh::~LineMesh()
{
    //Qt3DCore::QNode::cleanup();
}
