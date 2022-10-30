import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Item {
    id: testingViewPage

    /** Contains the test ID value */
    property string testID: ""

    /** Contains the testing view title */
    property string title: ""

    /** Source of the image for the first code version */
    property string firstImageSource: ""

    /** Source of the image for the second code version */
    property string secondImageSource: ""

    /** Contains the picker component values to display */
    property var pickerValues: []

    /** Emitted when user just decided to start the selected test */
    signal testStarted(string testID, int firstPickerValue, int secondPickerValue)

    /** Called when component has been just created */
    Component.onCompleted: {
        testStarted.connect(testingViewController.onTestStarted)
    }

    QtObject {
        id: internal

        /** Contains the current value of the picker component for the first code version */
        property int firstPickerValue: pickerValues[0]

        /** Contains the current value of the picker component for the second code version */
        property int secondPickerValue: pickerValues[0]
    }

    Rectangle {
        id: pageBackground
        anchors.fill: parent
        gradient: GUIConfig.gradients.creamGradient
    }

    Label {
        id: titleLabel
        text: title
        font: GUIConfig.fonts.decoratedFont
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: GUIConfig.testingView.titleLabelTopMargin
        }
    }

    Row {
        id: componentRow
        spacing: GUIConfig.testingView.imagesSpacing
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: GUIConfig.testingView.imagesTopMargin
        }

        Repeater {
            id: imageRepeater
            model: GUIConfig.testingView.imagesToDisplay

            Column {
                id: imageRepeaterColumn
                spacing: GUIConfig.testingView.columnSpacing

                Image {
                    id: image
                    source: index === 0 ? firstImageSource : secondImageSource
                }

                Label {
                    id: pickerLabel
                    text: GUIConfig.testingView.pickerLabelText
                    font: GUIConfig.fonts.smallFont
                    anchors {
                        horizontalCenter: image.horizontalCenter
                    }
                }

                ComboBox {
                    id: pickerComboBox
                    model: pickerValues
                    anchors {
                        horizontalCenter: image.horizontalCenter
                    }
                    background: Rectangle {
                        implicitWidth: GUIConfig.testingView.pickerComboBoxWidth
                        implicitHeight: GUIConfig.testingView.pickerComboBoxHeight
                        border.width: GUIConfig.testingView.pickerComboBoxBorderWidth
                        border.color: GUIConfig.colors.grey
                    }

                    /** Contains information if the component is related to the first code version */
                    property bool isFirstVersion: index === 0

                    /** Called when component has just been activated by user */
                    onActivated: {
                        if (isFirstVersion) {
                           internal.firstPickerValue = pickerValues[index]
                        } else {
                            internal.secondPickerValue = pickerValues[index]
                        }
                    }
                }
            }
        }
    }

    ConfirmButton {
        id: startTestButton
        text: GUIConfig.testingView.startButtonText

        /** Called when start test button has been just released */
        buttonArea.onReleased: {
            testStarted(testID, internal.firstPickerValue, internal.secondPickerValue)
        }
    }
}
