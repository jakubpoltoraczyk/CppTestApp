import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: testingView
    anchors.fill: parent

    /** Called when component creation has been finished */
    Component.onCompleted: {
        closeButton.released.connect(quizMenuController.onCloseButtonReleased)
    }

    SwipeView {
        id: testingSwipeView
        anchors.fill: parent
        currentIndex: 0

        Repeater {
            id: testingViewPages
            model: quizMenuController.pageModels.length

            TestingViewPage {
            }
        }
    }

    CustomPageIndicator {
        id: pageIndicator
        swipeView: testingSwipeView
    }

    CloseButton {
        id: closeButton
    }
}
