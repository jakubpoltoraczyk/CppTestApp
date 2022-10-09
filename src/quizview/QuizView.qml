import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: quizMenu
    anchors.fill: parent
    color: GUIConfig.colors.white

    /** Called when component has been just created */
    Component.onCompleted: {
        stopTestButton.released.connect(quizViewController.onStopTestButtonReleased)
    }

    QuizTimer {
        id: quizTimer
        initialTime: quizViewController.getQuizDuration()
    }

    ConfirmButton {
        id: acceptAnswerButton
        text: GUIConfig.quizView.acceptAnswerButtonText
    }

    CloseButton {
        id: stopTestButton
        iconSourceIndex: 1
    }
}
