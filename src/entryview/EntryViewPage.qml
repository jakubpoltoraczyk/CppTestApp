import QtQuick 2.0
import QtQuick.Controls 2.15

import "../external"

Item {
    id: entryViewPage

    /** Type of entry view page */
    property int pageType: BasicController.EntryPage.UNDEFINED

    /** Emitted when entry page has been selected */
    signal entryPageSelected(int pageType)

    /** Called when creation of component has been completed */
    Component.onCompleted: {
        entryPageSelected.connect(basicController.onEntryPageSelected)
    }

    Rectangle {
        id: pageBackground
        anchors.fill: parent
        gradient: GUIConfig.gradients.blueGradient
    }

    Label {
        id: textLabel
        font: GUIConfig.fonts.decoratedFont
        text: GUIConfig.entryView.pageTitles.get(pageType)
        anchors {
            horizontalCenter: pageBackground.horizontalCenter
            top: pageBackground.top
            topMargin: GUIConfig.entryView.pageTitleTopMargin
        }
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
                entryPageSelected(pageType)
            }
        }
    }
}
