import QtQuick 2.15
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.15

import "../"

Dialog {
    id: customDialog
    width: GUIConfig.customDialog.width
    height: GUIConfig.customDialog.height
    modal: true
    closePolicy: Popup.NoAutoClose
    standardButtons: StandardButton.Ok | StandardButton.Cancel
    anchors.centerIn: parent

    contentItem: Rectangle {
        id: dialogContent
        color: GUIConfig.customDialog.backgroundColor
        border {
            color: GUIConfig.customDialog.borderColor
            width: GUIConfig.customDialog.borderWidth
        }
        anchors {
            fill: parent
        }

        ColumnImageLabel {
            id: contentImageLabel
            labelText: "Are you really want to close the application?"
            imageSource: GUIConfig.customDialog.informationImageSource
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: GUIConfig.customDialog.contentImageLabelTopMargin
            }
        }
    }

    footer: DialogButtonBox {
        id: dialogFooter
        background: Rectangle {
            color: GUIConfig.customDialog.backgroundColor
            border {
                color: GUIConfig.customDialog.borderColor
                width: GUIConfig.customDialog.borderWidth
            }
        }
    }


    /** Called when component creation has been just finished */
    Component.onCompleted: {
        accepted.connect(customDialogController.onAccepted)
        rejected.connect(customDialogController.onRejected)
    }
}
