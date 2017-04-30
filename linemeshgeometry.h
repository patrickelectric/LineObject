#include <Qt3DRender/QGeometry>
#include <Qt3DRender/QAttribute>
#include <Qt3DRender/QBuffer>

class LineMeshGeometry : public Qt3DRender::QGeometry
{
    Q_OBJECT
public:
    LineMeshGeometry(QVector<QVector3D> vertices, Qt3DCore::QNode *parent = Q_NULLPTR);
    ~LineMeshGeometry();

    int vertexCount();

private:
    Qt3DRender::QAttribute *_positionAttribute;
    Qt3DRender::QBuffer *_vertexBuffer;
    QVector<QVector3D> _vertices;
};
