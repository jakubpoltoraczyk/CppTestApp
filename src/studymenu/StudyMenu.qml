import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: studyMenu
    anchors.fill: parent

    /** Called when component creation has been finished */
    Component.onCompleted: {
        closeButton.released.connect(studyMenuController.onCloseButtonReleased)
        console.log(Qt.fontFamilies())
    }

    SwipeView {
        id: studyMenuSwipeView
        anchors.fill: parent
        currentIndex: 0

        Repeater {
            id: studyMenuPages
            model: studyMenuController.pageModels.length

            StudyMenuPage {
                title: studyMenuController.pageModels[index].title
            }
        }
    }

    CustomPageIndicator {
        id: pageIndicator
        swipeView: studyMenuSwipeView
    }

    CloseButton {
        id: closeButton
    }
}