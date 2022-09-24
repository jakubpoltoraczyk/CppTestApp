import QtQuick 2.15
import QtQuick.Controls 2.15

RoundButton {
    id: startButton
    width: GUIConfig.confirmButton.width
    height: GUIConfig.confirmButton.height
    palette.button: GUIConfig.colors.grey
    font: GUIConfig.fonts.mediumFont
    text: GUIConfig.confirmButton.defaultText
    anchors {
        horizontalCenter: parent.horizontalCenter
        bottom: parent.bottom
        bottomMargin: GUIConfig.confirmButton.bottomMargin
    }

    /** Alias for button mouse area component */
    property alias buttonArea: mouseArea

    MouseArea {
        id: mouseArea
        hoverEnabled: true
        anchors.fill: parent

        /** Called when mouse pointer entered mouse area */
        onEntered: {
            startButton.palette.button = GUIConfig.colors.green
        }

        /** Called when mouse pointer exited mouse area */
        onExited: {
            startButton.palette.button = GUIConfig.colors.grey
        }

        /** Called when mouse area reported user press action */
        onPressed: {
            startButton.font = GUIConfig.fonts.smallFont
        }

        /** Called when mouse area reported user release action */
        onReleased: {
            startButton.font = GUIConfig.fonts.mediumFont
        }

        /** Called when mouse area reported user cancel action */
        onCanceled: {
            startButton.palette.button = GUIConfig.colors.grey
            startButton.font = GUIConfig.fonts.mediumFont
        }
    }
}
