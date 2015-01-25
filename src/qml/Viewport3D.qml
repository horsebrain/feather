import QtQuick 2.3
import FeatherViewport 1.0

Rectangle {
    //anchors.fill: parent
    color: "orange"
    border.color: "black"
    border.width: 1

    Viewport {
        id: renderer
        anchors.fill: parent
        anchors.margins: 2

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: false
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onPressed: {
                if(mouse.button == Qt.RightButton)
                    main_popup.popup();

                renderer.mousePressed(mouse.x,mouse.y)

            }
            onPositionChanged: { renderer.moveCamera(mouse.x,mouse.y) }
            //onReleased: { console.log("released") }
            onWheel: { renderer.zoomCamera(wheel.angleDelta.y); }
        }

    MainPopup { id: main_popup; visible: true }

    }

}
