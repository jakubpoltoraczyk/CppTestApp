import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: quizMenu
    anchors.fill: parent

    /** Called when component creation has been finished */
    Component.onCompleted: {
        closeButton.released.connect(quizMenuController.onCloseButtonReleased)
    }

    SwipeView {
        id: quizMenuSwipeView
        anchors.fill: parent
        currentIndex: 0

        Repeater {
            id: quizMenuPages
            model: quizMenuController.pageModels.length

            QuizMenuPage {
                quizName: quizMenuController.pageModels[index].quizName
                difficultyLevel: quizMenuController.pageModels[index].difficultyLevel
                areClosedQuestions: quizMenuController.pageModels[index].areClosedQuestions
                areOpenQuestions: quizMenuController.pageModels[index].areOpenQuestions
                quizDuration: quizMenuController.pageModels[index].quizDuration

                /** Called when component has been just created */
                Component.onCompleted: {
                    startTestButtonReleased.connect(quizMenuController.onStartTestButtonReleased)
                }
            }
        }
    }

    CustomPageIndicator {
        id: pageIndicator
        swipeView: quizMenuSwipeView
    }

    CloseButton {
        id: closeButton
    }
}
