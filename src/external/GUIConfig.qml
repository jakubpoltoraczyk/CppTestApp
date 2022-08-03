pragma Singleton

import QtQuick 2.15

Item {
    id: guiConfig

    /** Contains available component colors */
    readonly property alias colors: colors

    /** Contains configuration related to application window component */
    readonly property alias applicationWindow: applicationWindow

    QtObject {
        id: colors
        readonly property color lightGrey: "#f5f5f5"
    }

    QtObject {
        id: applicationWindow
        readonly property int height: 800
        readonly property int width: 1000
        readonly property color backgroundColor: colors.lightGrey
    }
}
