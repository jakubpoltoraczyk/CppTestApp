import QtQuick 2.0
import QtQuick.Controls 2.15

import QuizMenuPageModel 1.0

import "../external"

Item {
    id: quizMenuPage

    /** Contains quiz difficulty level */
    property int difficultyLevel: QuizMenuPageModel.DifficultyLevel.EASY

    Rectangle {
        id: pageBackground
        anchors.fill: parent
        gradient: GUIConfig.quizMenu.gradients.get(difficultyLevel)
    }
}
