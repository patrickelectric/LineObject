import QtQuick 2.0
import QtQuick.Scene3D 2.0

Item {
    width: 400
    height: 300

    property variant margin: 10
    Rectangle {
        id: scene
        anchors.fill: parent
        // I was not able to se this variable inside Scene3D
        anchors.margins: margin
        Scene3D {
            id: scene3d
            x: scene.x
            y: scene.y
            // This hardcoded values need to be solved
            width: scene.width/2 - margin
            height: scene.height/2 - margin
            // Here is the trick:
            //   Disable focus in all scenes
            //   MouseArea will enable and disable
            //   One cameracontroller run then all !
            focus: false
            aspects: ["input", "logic"]
            cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

            AnimatedEntity {
                id: entity
                onFpsChanged: textFPS.fpsReceived(fps, 0)
            }
        }

        Scene3D {
            id: scene3d2
            x: parent.x + width
            y: parent.y
            width: scene.width/2 - margin
            height: scene.height/2 - margin
            focus: false
            multisample: scene3d.multisample
            aspects: ["input", "logic"]
            cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

            AnimatedEntity {
                id: entity2
                onFpsChanged: textFPS.fpsReceived(fps, 1)
            }
        }

        Scene3D {
            id: scene3d3
            x: parent.x
            y: parent.y + height
            width: scene.width/2 - margin
            height: scene.height/2 - margin
            focus: false
            multisample: scene3d.multisample
            aspects: ["input", "logic"]
            cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

            AnimatedEntity {
                id: entity3
                onFpsChanged: textFPS.fpsReceived(fps, 2)
            }
        }

        Scene3D {
            id: scene3d4
            x: parent.x + width
            y: parent.y  + height
            width: scene.width/2 - margin
            height: scene.height/2 - margin
            focus: false
            multisample: scene3d.multisample
            aspects: ["input", "logic"]
            cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

            AnimatedEntity {
                id: entity4
                onFpsChanged: textFPS.fpsReceived(fps, 3)
            }
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            focus: false
            // This is important, without this you can't click in Scene3D
            z: -1
            onPositionChanged: {
                // Turn off all focus
                scene3d.focus = false
                scene3d2.focus = false
                scene3d3.focus = false
                scene3d4.focus = false
                // Enable only the one where the mouse is
                if(mouse.x < (scene3d.x + scene3d.width) && mouse.y < (scene3d.y + scene3d.height))
                    scene3d.focus = true
                if(mouse.x > (scene3d.x + scene3d.width) && mouse.y < (scene3d.y + scene3d.height))
                    scene3d2.focus = true
                if(mouse.x < (scene3d.x + scene3d.width) && mouse.y > (scene3d.y + scene3d.height))
                    scene3d3.focus = true
                if(mouse.x > (scene3d.x + scene3d.width) && mouse.y > (scene3d.y + scene3d.height))
                    scene3d4.focus = true
                // Preent some debug messages if necessary
                /*
                print(mouse.x, mouse.y)
                print((scene.height/2 - 50), (scene.width/2 - 50))
                print(scene3d.focus, scene3d2.focus, scene3d3.focus, scene3d4.focus)
                */
            }
        }
    }

    property var lastFps: [60, 60, 60, 60]

    Text {
        id: textFPS
        text: ""
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
        signal fpsReceived(var fps, var id)
        onFpsReceived: {
        // Update a specific fps and show it
            lastFps[id] = (Math.abs(fps-lastFps[id]) > 1) ? Math.round(fps) : lastFps[id]
            var text = ("%1 fps, %2 fps, %3 fps, %4 fps")
            for (var i=0; i<4; i++)
                text = text.arg(lastFps[id])
            textFPS.text = text
            print(lastFps[0] == lastFps[1] == lastFps[2] == lastFps[3])
            print(lastFps[0], lastFps[1], lastFps[2], lastFps[3])
        }
    }

    Text {
        // Enable or disable multisample
        text: "Multisample: " + scene3d.multisample
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter

        MouseArea {
            anchors.fill: parent
            onClicked: {
                scene3d.multisample = !scene3d.multisample
            }
        }
    }
}
