import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import StudyMenuPageModel 1.0

import "../external"

Item {
    id: quizMenuPage

    /** Contains study menu page title text */
    property string title: ""

    /** Contains study menu page topic */
    property int topic: StudyMenuPageModel.Topic.UNDEFINED

    Rectangle {
        id: pageBackground
        anchors.fill: parent
        gradient: GUIConfig.gradients.purpleGradient
    }

    Label {
        id: titleLabel
        text: title
        font: GUIConfig.fonts.decoratedFont
        anchors {
            horizontalCenter: pageBackground.horizontalCenter
            top: pageBackground.top
            topMargin: GUIConfig.studyMenu.titleLabelTopMargin
        }
    }

    ConfirmButton {
        id: confirmButton
        text: GUIConfig.studyMenu.startButtonText
    }
}
