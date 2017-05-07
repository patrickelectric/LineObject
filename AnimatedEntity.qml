import QtQuick 2.7
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import Qt3D.Logic 2.0
import GridMesh 1.0
import LineMesh 1.0

Entity {
    id: sceneRoot

    signal fpsChanged(var fps)
    signal cameraPositionChanged(var position, var upVector, var viewCenter)

    Camera {
        id: camera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        aspectRatio: 16/9
        nearPlane : 0.01
        farPlane : 1000.0
        position: Qt.vector3d( 10, -10, 18.0 )
        upVector: Qt.vector3d( 0.0, 0.65, 0.65 )
        viewCenter: Qt.vector3d( 10, 10, 0 )
    }

    FirstPersonCameraController { camera: camera }

    components: [
        RenderSettings {
            activeFrameGraph: ClearBuffers {
                buffers: ClearBuffers.ColorDepthBuffer
                clearColor: "transparent"

                RenderSurfaceSelector {
                    id: surfaceSelector
                    ClearBuffers {
                        buffers : ClearBuffers.ColorDepthBuffer
                        NoDraw {}
                    }

                    Viewport {
                        id: topLeftViewport
                        CameraSelector {
                            id: cameraSelectorTopLeftViewport
                            camera: camera
                        }
                    }
                }
            }
        },
        InputSettings { }
    ]

    FrameAction {
        id: frameAction

        onTriggered: {
            sceneRoot.fpsChanged(1/dt)
            sceneRoot.cameraPositionChanged(camera.position, camera.upVector, camera.viewCenter)
        }
    }

    GridMesh {
        id: gridMesh
        enabled: true
    }

    LineMesh {
        id: lineMesh
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
        id: gridEntity
        components: [ gridMesh, material, lineTransform ]
    }

    Entity {
        id: lineEntity
        components: [ lineMesh, material, lineTransform ]
    }

}
