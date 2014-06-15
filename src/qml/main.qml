import QtQuick 2.0

import FeatherViewport 1.0

Item {
    id: main
    width: 800
    height: 600

    Viewport {
        id: renderer
        anchors.fill: parent
        anchors.margins: 10

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: false

            onClicked: {}
        }

    }

}
