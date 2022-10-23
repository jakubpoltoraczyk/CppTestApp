import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Item {
    id: testingViewPage

    Component.onCompleted: {
        startTestButton.buttonArea.released.connect(testingViewController.onStartTestButtonReleased)
    }

    Rectangle {
        id: pageBackground
        anchors.fill: parent
        gradient: GUIConfig.gradients.creamGradient
    }

    Row {
        spacing: 50
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 150
        }

        Repeater {
            id: imageRepeater
            model: 2
            Image {
                source: "qrc:/testing/test01/test01modernversion.png"
            }
        }
    }

    ConfirmButton {
        id: startTestButton
        text: "Start test"
    }
}
