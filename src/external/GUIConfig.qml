pragma Singleton

import QtQuick 2.15

Item {
    id: guiConfig

    /** Contains available component colors */
    readonly property alias colors: colors

    /** Contains configuration related to application window component */
    readonly property alias applicationWindow: applicationWindow

    readonly property alias entryView: entryView

    QtObject {
        id: colors
        readonly property color grey: "#c3c1c7"
        readonly property color lightBlue: "#243561"
        readonly property color blue: "#5068a6"
        readonly property color darkBlue: "#7f9be3"
        readonly property color green: "#3bbf74"
        readonly property color darkGreen: "#198041"
        readonly property color red: "#bd5048"
    }

    QtObject {
        id: applicationWindow
        readonly property int height: 600
        readonly property int width: 800
    }

    QtObject {
        id: entryView
        readonly property int startButtonWidth: 200
        readonly property int startButtonHeight: 60
        readonly property int startButtonBottomMargin: 100
        readonly property int pageIndicatorBottomMargin: 50
    }
}
