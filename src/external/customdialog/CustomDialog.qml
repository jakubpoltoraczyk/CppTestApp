import QtQuick 2.15
import QtQuick.Dialogs 1.3

MessageDialog {
    id: customDialog
    standardButtons: StandardButton.Ok | StandardButton.Cancel

    /** Called when component creation has been just finished */
    Component.onCompleted: {
        accepted.connect(customDialogController.onAccepted)
        rejected.connect(customDialogController.onRejected)
    }
}
