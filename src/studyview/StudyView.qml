import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: studyView
    anchors.fill: parent

    /** Called when component creation has been finished */
    Component.onCompleted: {
        closeButton.released.connect(studyViewController.onCloseButtonReleased)
    }

    SwipeView {
        id: studySwipeView
        anchors.fill: parent
        currentIndex: 0

        Repeater {
            id: studyViewPages
            model: studyViewController.currentModel.lessons.length

            StudyViewPage {
                title: studyViewController.currentModel.title
                image: studyViewController.currentModel.images[index]
                lesson: studyViewController.currentModel.lessons[index]
            }
        }
    }

    CustomPageIndicator {
        id: pageIndicator
        swipeView: studySwipeView
    }

    CloseButton {
        id: closeButton
    }
}
