import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: closeButton
    width: icon.width
    height: icon.height
    anchors {
        top: parent.top
        topMargin: GUIConfig.closeButton.topMargin
        right: parent.right
        rightMargin: GUIConfig.closeButton.rightMargin
    }
    background: Rectangle {
        color: GUIConfig.colors.transparent
    }

    Image {
        id: icon
        source: GUIConfig.closeButton.iconSource
    }
}
