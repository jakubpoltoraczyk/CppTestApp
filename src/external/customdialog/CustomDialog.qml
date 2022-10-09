import QtQuick 2.15
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.15

import "../"

Dialog {
    id: customDialog
    width: GUIConfig.customDialog.width
    height: GUIConfig.customDialog.height
    closePolicy: Popup.NoAutoClose
    modal: true
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
            labelText: customDialogController.dialogModel.content
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
        standardButtons: customDialogController.dialogModel.buttonCode
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
