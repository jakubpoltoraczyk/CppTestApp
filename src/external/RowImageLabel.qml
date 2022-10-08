import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

RowLayout {
    id: rowImageLabel
    spacing: GUIConfig.imageLabel.spacing

    /** Source of icon image to display */
    property string imageSource: ""

    /** Text of label to display */
    property string labelText: ""

    Image {
        id: image
        source: imageSource
    }

    Label {
        id: label
        text: labelText
        font: GUIConfig.fonts.smallFont
    }
}
