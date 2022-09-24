import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: quizMenu
    anchors.fill: parent

    /** Emitted when user decided to exit quiz menu */
    signal quizMenuExited()

    /** Called when component creation has been finished */
    Component.onCompleted: {
        quizMenuExited.connect(basicController.onQuizMenuExited)
    }

    SwipeView {
        id: quizMenuSwipeView
        anchors.fill: parent
        currentIndex: 0

        Repeater {
            id: quizMenuPages
            model: quizMenuController.pageModels.length

            QuizMenuPage {
                difficultyLevel: quizMenuController.pageModels[index].difficultyLevel
                areClosedQuestions: quizMenuController.pageModels[index].areClosedQuestions
                areOpenQuestions: quizMenuController.pageModels[index].areOpenQuestions
                quizDuration: quizMenuController.pageModels[index].quizDuration
            }
        }
    }

    CustomPageIndicator {
        id: pageIndicator
        swipeView: quizMenuSwipeView
    }

    ExitButton {
        id: exitButton

        /** Called when exit button has been released */
        onReleased: {
            quizMenuExited()
        }
    }
}
