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

    /** Contains index of icon source used to display close button image */
    property int iconSourceIndex: 0

    Image {
        id: icon
        source: GUIConfig.closeButton.iconSources[iconSourceIndex]
    }
}
