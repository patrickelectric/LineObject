import QtQuick 2.0
import QtQuick.Scene3D 2.0

Item {
    property var lowFps: 60;
    Text {
        id: textFPS
        text: ""
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        signal fpsReceived(var fps)
        onFpsReceived: {
            fps = (fps > 1000) ? 60 : fps
            lowFps = 0.99*lowFps + 0.01*fps
            textFPS.text = ("%1 fps").arg(lowFps)
        }
    }

    Text {
        text: "Multisample: " + scene3d.multisample
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter

        MouseArea {
            anchors.fill: parent
            onClicked: scene3d.multisample = !scene3d.multisample
        }
    }

    Rectangle {
        id: scene
        anchors.fill: parent
        anchors.margins: 50

        transform: Rotation {
            id: sceneRotation
            axis.x: 1
            axis.y: 0
            axis.z: 0
            origin.x: scene.width / 2
            origin.y: scene.height / 2
        }

        Scene3D {
            id: scene3d
            anchors.fill: parent
            anchors.margins: 10
            focus: true
            aspects: ["input", "logic"]
            cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

            AnimatedEntity {
                id: entity
                onFpsChanged: textFPS.fpsReceived(fps)
            }
        }
    }
}
