#include <QList>
#include <QVector3D>
#include <QVector4D>
#include <QtMath>

#include "linemeshgeometry.h"

LineMeshGeometry::LineMeshGeometry(QList<QVector4D> vertices, Qt3DCore::QNode *parent)
    : Qt3DRender::QGeometry(parent),
    _positionAttribute(new Qt3DRender::QAttribute(this)),
    _vertexBuffer(new Qt3DRender::QBuffer(Qt3DRender::QBuffer::VertexBuffer, this))
{
    QByteArray vertexBufferData;
    vertexBufferData.resize(vertices.size() * 3 * sizeof(float));
    float *rawVertexArray = reinterpret_cast<float *>(vertexBufferData.data());
    int idx = 0;
    for (const auto& v : vertices) {
        rawVertexArray[idx++] = v.x();
        rawVertexArray[idx++] = v.y();
        rawVertexArray[idx++] = v.z();
        _vertices.append(v.toVector3D());
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
