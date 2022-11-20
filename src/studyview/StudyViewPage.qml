import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Item {
    id: studyViewPage

    /** Title of the study view page */
    property string title: ""

    /** Source of the image do display */
    property var image: []

    /** Text of the lesson to display */
    property var lesson: []

    Rectangle {
        id: pageBackground
        anchors.fill: parent
        gradient: GUIConfig.gradients.creamGradient
    }

    Label {
        id: titleLabel
        font: GUIConfig.fonts.decoratedFont
        text: title
        anchors {
            horizontalCenter: pageBackground.horizontalCenter
            top: pageBackground.top
            topMargin: 50
        }
    }

    Image {
        id: codeImage
        source: image
        anchors {
            horizontalCenter: pageBackground.horizontalCenter
            top: titleLabel.bottom
            topMargin: 50
        }
    }

    Label {
        id: lessonLabel
        font: GUIConfig.fonts.smallFont
        text: lesson
        anchors {
            horizontalCenter: pageBackground.horizontalCenter
            top: codeImage.bottom
            topMargin: 50
        }
    }
}
