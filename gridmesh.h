#pragma once

#include <QObject>
#include <Qt3DCore/QNode>
#include <Qt3DRender/QGeometryRenderer>

class GridMesh : public Qt3DRender::QGeometryRenderer
{
    Q_OBJECT
public:
    explicit GridMesh(Qt3DCore::QNode* parent = Q_NULLPTR);
    ~GridMesh();
};
