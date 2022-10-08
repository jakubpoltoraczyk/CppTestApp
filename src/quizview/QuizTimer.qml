import QtQuick 2.15
import QtQuick.Controls 2.15

import "../external"

Rectangle {
    id: quizTimer
    color: GUIConfig.colors.transparent
    anchors {
        top: parent.top
        left: parent.left
        topMargin: GUIConfig.quizView.quizTimerTopMargin
        leftMargin: GUIConfig.quizView.quizTimerLeftMargin
    }

    /** Contains quiz timer initial time */
    property int initialTime: 0

    QtObject {
        id: internal

        /** Contains quiz timer remaining time */
        property int remainingTime: initialTime
    }

    Timer {
        id: timer
        interval: 1000
        running: true
        repeat: true

        /** Called when timer interval has just timed out */
        onTriggered: {
            internal.remainingTime -= 1
        }
    }

    ColumnImageLabel {
        id: imageLabel
        imageSource: GUIConfig.quizView.hourGlassImageSource
        labelText: internal.remainingTime
    }
}
