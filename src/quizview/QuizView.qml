import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: quizMenu
    anchors.fill: parent
    color: GUIConfig.colors.white

    property int remainingTime: quizViewController.getQuizDuration()

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            remainingTime -= 1
            timerLabel.text = remainingTime
        }
    }

    Label {
        id: timerLabel
        text: remainingTime
    }
}
