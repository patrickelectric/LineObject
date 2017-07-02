#include <Qt3DRender/QGeometryRenderer>
#include <QVector3D>
#include <QDebug>

#include "linemeshgeometry.h"
#include "linemeshpart.h"
#include "gcodeto3d.h"

LineMeshPart::LineMeshPart(Qt3DCore::QNode *parent)
    : Qt3DRender::QGeometryRenderer(parent),
    _lineMeshGeo(nullptr)
{
    setInstanceCount(1);
    setIndexOffset(0);
    setFirstInstance(0);
    setPrimitiveType(Qt3DRender::QGeometryRenderer::LineStrip);
}

void LineMeshPart::start() {
    auto gcode = new GcodeTo3D();
    qRegisterMetaType<QList<QVector4D> >("QList<QVector4D>");
    connect(gcode, &GcodeTo3D::posUpdated, this, &LineMeshPart::posUpdate);
    gcode->enableWait();
    gcode->read("test2.gcode");
}

void LineMeshPart::posUpdate(QList<QVector4D> pos) {
    _vertices = pos;
    _lineMeshGeo = new LineMeshGeometry(_vertices, this);
    setVertexCount(_lineMeshGeo->vertexCount());
    setGeometry(_lineMeshGeo);
    qDebug() << "MAGIC POTATO !!!!!!!!!!!";
}

LineMeshPart::~LineMeshPart()
{
    //Qt3DCore::QNode::cleanup();
}
