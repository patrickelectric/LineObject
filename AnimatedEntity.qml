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

    Camera {
        id: camera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        aspectRatio: 16/9
        nearPlane : 0.01
        farPlane : 1000.0
        position: Qt.vector3d( 0.0, 0.0, 10.0 )
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
    }

    Camera {
        id: camera1
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        aspectRatio: 16/9
        nearPlane : 0.01
        farPlane : 1000.0
        position: Qt.vector3d( 0.0, 0.0, 10.0 )
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
    }

    Camera {
        id: camera2
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        aspectRatio: 16/9
        nearPlane : 0.01
        farPlane : 1000.0
        position: Qt.vector3d( 0.0, 0.0, 10.0 )
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
    }

    Camera {
        id: camera3
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        aspectRatio: 16/9
        nearPlane : 0.01
        farPlane : 1000.0
        position: Qt.vector3d( 0.0, 0.0, 10.0 )
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
    }

    FirstPersonCameraController { camera: camera1 }
    FirstPersonCameraController { camera: camera2 }
    FirstPersonCameraController { camera: camera3 }

    components: [
        RenderSettings {
            activeFrameGraph: RenderSurfaceSelector {
                id: surfaceSelector
                //clearColor: "transparent"

                Viewport {
                    id: mainViewport
                    normalizedRect: Qt.rect(0, 0, 1, 1)

                    ClearBuffers {
                        buffers: ClearBuffers.ColorDepthBuffer
                    }

                    Viewport {
                        id: topLeftViewport
                        normalizedRect: Qt.rect(0, 0, 0.5, 0.5)
                        CameraSelector {
                            id: cameraSelectorTopLeftViewport
                            camera: camera
                        }
                        FirstPersonCameraController { camera: camera }
                    }

                    Viewport {
                        id: topRightViewport
                        //camera: camera
                        normalizedRect: Qt.rect(0.5, 0, 0.5, 0.5)
                        CameraSelector {
                            id: cameraSelectorTopRightViewport
                            camera: camera1
                        }
                    }

                    Viewport {
                        id: bottomLeftViewport
                        //camera: camera
                        normalizedRect: Qt.rect(0, 0.5, 0.5, 0.5)
                        CameraSelector {
                            id: cameraSelectorBottonLeftViewport
                            camera: camera2
                        }
                    }

                    Viewport {
                        id: bottomRightViewport
                        //camera: camera
                        normalizedRect: Qt.rect(0.5, 0.5, 0.5, 0.5)
                        CameraSelector {
                            id: cameraSelectorBottonRightViewport
                            camera: camera3
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
