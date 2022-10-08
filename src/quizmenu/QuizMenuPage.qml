import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import QuizMenuPageModel 1.0

import "../external"

Item {
    id: quizMenuPage

    /** Contains quiz name */
    property string quizName: ""

    /** Contains quiz difficulty level */
    property int difficultyLevel: QuizMenuPageModel.DifficultyLevel.UNDEFINED

    /** Contains information if closed questions are available */
    property bool areClosedQuestions: true

    /** Contains information if open questions are available */
    property bool areOpenQuestions: true

    /** Contains information about quiz duration */
    property int quizDuration: 0

    /** Emitted when start test button has been released */
    signal startTestButtonReleased(string quizName)

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

        RowImageLabel {
            id: difficultyImageLabel
            labelText: GUIConfig.quizMenu.difficultyInfoText.arg(
                           GUIConfig.quizMenu.difficultyNames.get(difficultyLevel))
            imageSource: GUIConfig.quizMenu.difficultyIconSource
        }

        RowImageLabel {
            id: closedQuestionsImageLabel
            labelText: GUIConfig.quizMenu.closedQuestionsInfoText
            imageSource: GUIConfig.quizMenu.closedQuestionsIconSource
            visible: areClosedQuestions
        }

        RowImageLabel {
            id: openQuestionsImageLabel
            labelText: GUIConfig.quizMenu.openQuestionsInfoText
            imageSource: GUIConfig.quizMenu.openQuestionsIconSource
            visible: areOpenQuestions
        }

        RowImageLabel {
            id: quizDurationImageLabel
            labelText: GUIConfig.quizMenu.quizDurationText.arg(quizDuration / 60)
            imageSource: GUIConfig.quizMenu.quizDurationIconSource
        }
    }

    ConfirmButton {
        id: confirmButton
        text: GUIConfig.quizMenu.startButtonText

        /** Called when button has been released */
        buttonArea.onReleased: {
            startTestButtonReleased(quizName)
        }
    }
}
