import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: entryView
    anchors.fill: parent

    SwipeView {
        id: entrySwipeView
        anchors.fill: parent
        currentIndex: 0

        Repeater {
            id: entryViewPages
            model: 3

            EntryViewPage {
            }
        }
    }

    EntryViewIndicator {
        count: entrySwipeView.count
        currentIndex: entrySwipeView.currentIndex
        anchors {
            horizontalCenter: entrySwipeView.horizontalCenter
            bottom: entrySwipeView.bottom
            bottomMargin: GUIConfig.entryView.pageIndicatorBottomMargin
        }
    }
}
