#pragma once

#include <QObject>
#include <Qt3DCore/QNode>
#include <Qt3DRender/QGeometryRenderer>
#include <QVector4D>
#include <QList>

class LineMesh : public Qt3DRender::QGeometryRenderer
{
    Q_OBJECT
public:
    explicit LineMesh(Qt3DCore::QNode* parent = Q_NULLPTR);
    ~LineMesh();

private:
    QList<QVector4D> _vertices;
	void posUpdate(QList<QVector4D> pos);
};
