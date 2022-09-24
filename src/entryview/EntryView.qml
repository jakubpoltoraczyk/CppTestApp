import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: entryView
    anchors.fill: parent

    /** Emitted when user decided to exit entry view */
    signal entryViewExited()

    /** Called when component creation has been finished */
    Component.onCompleted: {
        entryViewExited.connect(basicController.onEntryViewExited)
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

    ExitButton {
        id: exitButton

        /** Called when exit button has been just released */
        onReleased: {
            entryViewExited()
        }
    }
}
