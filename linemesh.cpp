#include <Qt3DRender/QGeometryRenderer>

#include "linemeshgeometry.h"
#include "linemesh.h"

LineMesh::LineMesh(Qt3DCore::QNode *parent)
    : Qt3DRender::QGeometryRenderer(parent)
{
    setInstanceCount(1);
    setIndexOffset(0);
    setFirstInstance(0);
    setPrimitiveType(Qt3DRender::QGeometryRenderer::LineStrip);
    auto geometry = new LineMeshGeometry(this);
    setVertexCount(geometry->vertexCount());
    setGeometry(geometry);
}

LineMesh::~LineMesh()
{
    //Qt3DCore::QNode::cleanup();
}
