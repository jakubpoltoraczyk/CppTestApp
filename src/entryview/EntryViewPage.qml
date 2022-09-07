import QtQuick 2.0
import QtQuick.Controls 2.15

import "../external"

Item {
    id: entryViewPage

    Rectangle {
        id: pageBackground
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: GUIConfig.colors.lightBlue }
            GradientStop { position: 0.33; color: GUIConfig.colors.blue }
            GradientStop { position: 1.0; color: GUIConfig.colors.darkBlue }
        }
    }

    RoundButton {
        id: startButton
        width: GUIConfig.entryView.startButtonWidth
        height: GUIConfig.entryView.startButtonHeight
        palette.button: GUIConfig.colors.grey
        anchors {
            horizontalCenter: pageBackground.horizontalCenter
            bottom: pageBackground.bottom
            bottomMargin: GUIConfig.entryView.startButtonBottomMargin
        }

        MouseArea {
            id: mouseArea
            hoverEnabled: true
            anchors.fill: parent

            onEntered: {
                startButton.palette.button = GUIConfig.colors.green
            }

            onExited: {
                startButton.palette.button = GUIConfig.colors.grey
            }
        }
    }
}
