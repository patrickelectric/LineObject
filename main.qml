import QtQuick 2.0
import QtQuick.Scene3D 2.0

Item {
    width: 1000
    height: 1000
    Rectangle {
        id: scene
        anchors.fill: parent
        Scene3D {
            id: scene3d
            anchors.fill: parent
            focus: true
            aspects: ["input", "logic"]
            cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

            AnimatedEntity {
                id: entity
                onFpsChanged: print(fps)
            }
        }
    }
}
