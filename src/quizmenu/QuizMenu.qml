import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: quizMenu
    anchors.fill: parent

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
            }
        }
    }

    CustomPageIndicator {
        id: pageIndicator
        swipeView: quizMenuSwipeView
    }
}
