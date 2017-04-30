import QtQuick 2.7
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import Qt3D.Logic 2.0
import GridMesh 1.0

Entity {
    id: sceneRoot

    signal fpsChanged(var fps)

    Camera {
        id: camera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        nearPlane : 0.1
        farPlane : 1000.0
        position: Qt.vector3d( 0.0, 0.0, 10.0 )
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
    }

    FirstPersonCameraController { camera: camera }

    components: [
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                camera: camera
                clearColor: "transparent"
            }
        },
        InputSettings { }
    ]

    FrameAction {
        id: frameAction

        onTriggered: {
            sceneRoot.fpsChanged(1/dt)
        }
    }

    GridMesh {
        id: gridMesh
        enabled: true
    }

    PhongMaterial {
        id: material
        ambient: "darkBlue"
    }

    Transform {
        id: lineTransform
    }

    Entity {
        id: lineEntity
        components: [ gridMesh, material, lineTransform ]
    }
}
