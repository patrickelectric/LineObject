#include <QVector>
#include <QVector3D>
#include <QtMath>

#include "linemeshgeometry.h"

LineMeshGeometry::LineMeshGeometry(Qt3DCore::QNode *parent)
    : Qt3DRender::QGeometry(parent),
    _positionAttribute(new Qt3DRender::QAttribute(this)),
    _vertexBuffer(new Qt3DRender::QBuffer(Qt3DRender::QBuffer::VertexBuffer, this))
{
    _vertices.resize(1e3);
    const int s = 20;
    for (auto& v : _vertices) {
        v.setX(s/2 - rand() % s);
        v.setY(s/2 - rand() % s);
        v.setZ(s/2 - rand() % s);
    }
    QByteArray vertexBufferData;
    vertexBufferData.resize(_vertices.size() * 3 * sizeof(float));
    float *rawVertexArray = reinterpret_cast<float *>(vertexBufferData.data());
    int idx = 0;
    for (const auto& v : _vertices) {
        rawVertexArray[idx++] = v.x();
        rawVertexArray[idx++] = v.y();
        rawVertexArray[idx++] = v.z();
    }

    _vertexBuffer->setData(vertexBufferData);

    _positionAttribute->setAttributeType(Qt3DRender::QAttribute::VertexAttribute);
    _positionAttribute->setBuffer(_vertexBuffer);
    _positionAttribute->setDataType(Qt3DRender::QAttribute::Float);
    _positionAttribute->setDataSize(3);
    _positionAttribute->setName(Qt3DRender::QAttribute::defaultPositionAttributeName());

    addAttribute(_positionAttribute);
}

int LineMeshGeometry::vertexCount()
{
    return _vertices.size();
}

LineMeshGeometry::~LineMeshGeometry()
{
}
