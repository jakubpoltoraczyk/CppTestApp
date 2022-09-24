import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: backButton
    width: icon.width
    height: icon.height
    anchors {
        top: parent.top
        topMargin: GUIConfig.exitButton.topMargin
        right: parent.right
        rightMargin: GUIConfig.exitButton.rightMargin
    }
    background: Rectangle {
        color: GUIConfig.colors.transparent
    }

    Image {
        id: icon
        source: GUIConfig.exitButton.iconSource
    }
}
