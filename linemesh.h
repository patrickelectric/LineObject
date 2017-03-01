#pragma once

#include <QObject>
#include <Qt3DCore/QNode>
#include <Qt3DRender/QGeometryRenderer>

class LineMesh : public Qt3DRender::QGeometryRenderer
{
    Q_OBJECT
public:
    explicit LineMesh(Qt3DCore::QNode* parent = Q_NULLPTR);
    ~LineMesh();
};
