import QtQuick 2.0
import QtQuick.Controls 2.15

import "../external"

import EntryViewController 1.0

Item {
    id: entryViewPage

    /** Type of entry view page */
    property int pageType: EntryViewController.PageType.UNDEFINED

    /** Emitted when start button has been released */
    signal startButtonReleased(int pageType)

    /** Called when creation of component has been completed */
    Component.onCompleted: {
        startButtonReleased.connect(entryViewController.onStartButtonReleased)
    }

    Rectangle {
        id: pageBackground
        anchors.fill: parent
        gradient: GUIConfig.gradients.blueGradient
    }

    Image {
        id: image
        source: GUIConfig.entryView.iconSources.get(pageType)
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
                if (containsMouse) {
                    startButtonReleased(pageType)
                }
            }

            /** Called when mouse area reported user cancel action */
            onCanceled: {
                startButton.palette.button = GUIConfig.colors.grey
                startButton.font = GUIConfig.fonts.mediumFont
            }
        }
    }
}
