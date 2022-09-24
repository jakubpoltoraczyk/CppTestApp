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

    ConfirmButton {
        id: confirmButton
        text: GUIConfig.entryView.startButtonText

        /** Called when confirm button has been released */
        buttonArea.onReleased: {
            if (buttonArea.containsMouse) {
                startButtonReleased(pageType)
            }
        }
    }
}
