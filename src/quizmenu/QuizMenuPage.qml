import QtQuick 2.0
import QtQuick.Controls 2.15

import QuizMenuPageModel 1.0

import "../external"

Item {
    id: quizMenuPage

    /** Contains quiz difficulty level */
    property int difficultyLevel: QuizMenuPageModel.DifficultyLevel.UNDEFINED

    Rectangle {
        id: pageBackground
        anchors.fill: parent
        gradient: GUIConfig.quizMenu.gradients.get(difficultyLevel)
    }

    Image {
        id: image
        source: GUIConfig.quizMenu.iconLevelSources.get(difficultyLevel)
        anchors {
            horizontalCenter: pageBackground.horizontalCenter
            top: pageBackground.top
            topMargin: GUIConfig.quizMenu.levelIconTopMargin
        }
    }

    ConfirmButton {
        id: confirmButton
        text: GUIConfig.quizMenu.startButtonText
    }
}
