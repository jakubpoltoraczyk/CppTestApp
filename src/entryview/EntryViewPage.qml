import QtQuick 2.0
import QtQuick.Controls 2.15

import "../external"

Item {
    id: entryViewPage

    /** Source of icon to display */
    property url iconSource: ""

    /** Emitted when start button has been released */
    signal startButtonReleased()

    Rectangle {
        id: pageBackground
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: GUIConfig.colors.lightBlue }
            GradientStop { position: 0.33; color: GUIConfig.colors.blue }
            GradientStop { position: 1.0; color: GUIConfig.colors.darkBlue }
        }
    }

    Image {
        id: image
        source: iconSource
        anchors {
            centerIn: pageBackground
        }
    }

    RoundButton {
        id: startButton
        width: GUIConfig.entryView.startButtonWidth
        height: GUIConfig.entryView.startButtonHeight
        palette.button: GUIConfig.colors.grey
        font: GUIConfig.fonts.mediumFont
        text: GUIConfig.entryView.startButtonText
        anchors {
            horizontalCenter: pageBackground.horizontalCenter
            bottom: pageBackground.bottom
            bottomMargin: GUIConfig.entryView.startButtonBottomMargin
        }

        MouseArea {
            id: mouseArea
            hoverEnabled: true
            anchors.fill: parent

            /** Called when mouse has been entered mouse area */
            onEntered: {
                startButton.palette.button = GUIConfig.colors.green
            }

            /** Called when mouse has been exited mouse area */
            onExited: {
                startButton.palette.button = GUIConfig.colors.grey
            }

            onReleased: {
                startButtonReleased()
            }
        }
    }
}
