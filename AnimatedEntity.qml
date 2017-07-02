import QtQuick 2.7
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import Qt3D.Logic 2.0
import GridMesh 1.0
import LineMesh 1.0
import LineMeshPart 1.0

Entity {
    id: sceneRoot

    signal fpsChanged(var fps)

    Camera {
        id: camera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        aspectRatio: 16/9
        nearPlane : 0.01
        farPlane : 1000.0
        position: Qt.vector3d( 10.0, -10.0, 25.0 )
        upVector: Qt.vector3d( 0.0, 0.75, 0.75 )
        viewCenter: Qt.vector3d( 10.0, 10.0, 0.0 )
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
        }
    }

    GridMesh {
        id: gridMesh
        enabled: true
    }

    LineMesh {
        id: lineMesh
        enabled: true
        // We do that to "fake" a real start
        // Only start to draw the red lines when the other object is done
        onFinished: {
            lineMeshPart.start()
        }
    }

    LineMeshPart {
        id: lineMeshPart
        enabled: true
    }

    PhongMaterial {
        id: material
        ambient: "darkBlue"
    }

    PhongMaterial {
        id: lineMaterial
        ambient: "darkGreen"
    }

    PhongMaterial {
        id: linePartMaterial
        ambient: "red"
    }

    Entity {
        id: gridEntity
        components: [ gridMesh, material ]
    }

    Entity {
        id: lineEntityPart
        components: [ lineMeshPart, linePartMaterial ]
    }

    Entity {
        id: lineEntity
        components: [ lineMesh, lineMaterial ]
    }
}
