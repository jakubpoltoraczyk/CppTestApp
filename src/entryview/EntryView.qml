import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: entryView
    anchors.fill: parent

    /** Called when component creation has been finished */
    Component.onCompleted: {
        closeButton.released.connect(basicController.onEntryViewClosed)
    }

    SwipeView {
        id: entrySwipeView
        anchors.fill: parent
        currentIndex: 0

        Repeater {
            id: entryViewPages
            model: GUIConfig.entryView.pages.length

            EntryViewPage {
                pageType: GUIConfig.entryView.pages[index]
            }
        }
    }

    CustomPageIndicator {
        id: pageIndicator
        swipeView: entrySwipeView
    }

    CloseButton {
        id: closeButton
    }
}
