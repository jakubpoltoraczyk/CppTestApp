import QtQuick 2.15
import QtQuick.Controls 2.15

PageIndicator {
    id: pageIndicator
    count: swipeView.count
    currentIndex: swipeView.currentIndex
    anchors {
        horizontalCenter: swipeView.horizontalCenter
        bottom: swipeView.bottom
        bottomMargin: GUIConfig.customPageIndicator.bottomMargin
    }

    /** Swipe view component used to determine proper placement of page indicator */
    property var swipeView: undefined
}
