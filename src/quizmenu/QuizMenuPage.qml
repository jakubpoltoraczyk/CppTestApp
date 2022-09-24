import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import QuizMenuPageModel 1.0

import "../external"

Item {
    id: quizMenuPage

    /** Contains quiz difficulty level */
    property int difficultyLevel: QuizMenuPageModel.DifficultyLevel.UNDEFINED

    /** Contains information if closed questions are available */
    property bool areClosedQuestions: true

    /** Contains information if open questions are available */
    property bool areOpenQuestions: true

    Rectangle {
        id: pageBackground
        anchors.fill: parent
        gradient: GUIConfig.quizMenu.gradients.get(difficultyLevel)
    }

    Image {
        id: levelImage
        source: GUIConfig.quizMenu.iconLevelSources.get(difficultyLevel)
        anchors {
            horizontalCenter: pageBackground.horizontalCenter
            top: pageBackground.top
            topMargin: GUIConfig.quizMenu.levelImageTopMargin
        }
    }

    ColumnLayout {
        id: quizMenuInformationLayout
        spacing: GUIConfig.quizMenu.informationLayoutSpacing
        anchors {
            horizontalCenter: levelImage.horizontalCenter
            top: levelImage.bottom
            topMargin: GUIConfig.quizMenu.informationLayoutTopMargin
        }

        ImageLabel {
            id: closedQuestionsImageLabel
            labelText: GUIConfig.quizMenu.closedQuestionsInfoText
            imageSource: GUIConfig.quizMenu.closedQuestionsIconSource
            visible: areClosedQuestions
        }

        ImageLabel {
            id: openQuestionsImageLabel
            labelText: GUIConfig.quizMenu.openQuestionsInfoText
            imageSource: GUIConfig.quizMenu.openQuestionsIconSource
            visible: areOpenQuestions
        }
    }

    ConfirmButton {
        id: confirmButton
        text: GUIConfig.quizMenu.startButtonText
    }
}
