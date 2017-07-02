#include <Qt3DRender/QGeometryRenderer>
#include <QVector3D>
#include <QDebug>

#include "linemeshgeometry.h"
#include "linemesh.h"
#include "gcodeto3d.h"

LineMesh::LineMesh(Qt3DCore::QNode *parent)
    : Qt3DRender::QGeometryRenderer(parent),
    _lineMeshGeo(nullptr)
{
    setInstanceCount(1);
    setIndexOffset(0);
    setFirstInstance(0);
    setPrimitiveType(Qt3DRender::QGeometryRenderer::LineStrip);

    auto gcode = new GcodeTo3D();
    qRegisterMetaType<QList<QVector4D> >("QList<QVector4D>");
    connect(gcode, &GcodeTo3D::posFinished, this, &LineMesh::posUpdate);
    gcode->read("../test.gcode");
}

void LineMesh::posUpdate(QList<QVector4D> pos) {
    _vertices = pos;
    _lineMeshGeo = new LineMeshGeometry(_vertices, this);
    setVertexCount(_lineMeshGeo->vertexCount());
    setGeometry(_lineMeshGeo);
    emit finished();
}

LineMesh::~LineMesh()
{
}
