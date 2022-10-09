import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QuizQuestionModel 1.0

import "../external"

Rectangle {
    id: quizMenu
    anchors.fill: parent
    gradient: GUIConfig.gradients.creamGradient

    QtObject {
        id: internal

        /** Index of the current question */
        property int currentQuestion: quizViewController.currentQuestion

        /** Type of the current question */
        property int currentType: quizViewController.questionModels[currentQuestion].type
    }

    /** Emitted when user selected the answer (only for the open question) */
    signal answerSelected(int answerIndex)

    /** Emitted when user entered the answer (only for the closed question) */
    signal answerEntered(string answerContent)

    /** Called when component has been just created */
    Component.onCompleted: {
        stopTestButton.released.connect(quizViewController.onStopTestButtonReleased)
        answerSelected.connect(quizViewController.onAnswerSelected)
        answerEntered.connect(quizViewController.onAnswerEntered)
    }

    QuizTimer {
        id: quizTimer
        initialTime: quizViewController.getQuizDuration()
    }

    CloseButton {
        id: stopTestButton
        iconSourceIndex: 1
    }

    Label {
        id: questionLabel
        text: quizViewController.questionModels[internal.currentQuestion].question
        font: GUIConfig.fonts.mediumFont
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: GUIConfig.quizView.questionLabelTopMargin
        }
    }

    ConfirmButton {
        id: acceptAnswerButton
        text: GUIConfig.quizView.acceptAnswerButtonText

        /** Called when answer button has been just released */
        buttonArea.onReleased: {
            answersRepeater.itemAt(0).checked = true
            if (internal.currentType === QuizQuestionModel.QuestionType.CLOSED) {
                answerSelected(answersLayout.selectedAnswerIndex)
            } else {
                answerEntered(answerTextField.text)
            }
        }
    }

    ColumnLayout {
        id: answersLayout
        spacing: GUIConfig.quizView.answersLayoutSpacing
        visible: internal.currentType === QuizQuestionModel.QuestionType.CLOSED
        anchors {
            horizontalCenter: questionLabel.horizontalCenter
            top: questionLabel.top
            topMargin: GUIConfig.quizView.answersLayoutTopMargin
        }

        /** Contains currently selected user answer */
        property int selectedAnswerIndex: 0

        Repeater {
            id: answersRepeater
            model: quizViewController.questionModels[internal.currentQuestion].answers.length

            RadioButton {
                text: quizViewController.questionModels[internal.currentQuestion].answers[index]
                font: GUIConfig.fonts.smallFont
                checked: index === 0

                /** Called when radio button has been just released */
                onReleased: {
                    answersLayout.selectedAnswerIndex = index
                }
            }
        }
    }

    TextField {
        id: answerTextField
        width: GUIConfig.quizView.answerTextFieldWidth
        height: GUIConfig.quizView.answerTextFieldHeight
        font: GUIConfig.fonts.smallFont
        placeholderText: GUIConfig.quizView.answerTextFieldPlaceholder
        visible: internal.currentType === QuizQuestionModel.QuestionType.OPEN
        background: Rectangle {
            border.color: GUIConfig.colors.grey
        }
        anchors {
            horizontalCenter: questionLabel.horizontalCenter
            top: questionLabel.top
            topMargin: GUIConfig.quizView.answerTextFieldTopMargin
        }
    }
}
