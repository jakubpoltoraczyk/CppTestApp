pragma Singleton

import QtQuick 2.15

Item {
    id: guiConfig

    /** Contains available component colors */
    readonly property alias colors: colors

    /** Contains configuration related to application window component */
    readonly property alias applicationWindow: applicationWindow

    /** Contains configuration related to entry view component */
    readonly property alias entryView: entryView

    /** Contains available fonts used in application */
    readonly property alias fonts: fonts

    QtObject {
        id: colors

        /** Grey color used in application */
        readonly property color grey: "#c3c1c7"

        /** Light blue color used in application */
        readonly property color lightBlue: "#243561"

        /** Blue color used in application */
        readonly property color blue: "#5068a6"

        /** Dark blue color used in application */
        readonly property color darkBlue: "#7f9be3"

        /** Green color used in application */
        readonly property color green: "#3bbf74"

        /** Dark green color used in application */
        readonly property color darkGreen: "#198041"

        /** Red color used in application */
        readonly property color red: "#bd5048"
    }

    QtObject {
        id: applicationWindow

        /** Height of application window */
        readonly property int height: 600

        /** Width of application window */
        readonly property int width: 800
    }

    QtObject {
        id: entryView

        /** Width of start button object */
        readonly property int startButtonWidth: 200

        /** Height of start button object */
        readonly property int startButtonHeight: 60

        /** Bottom margin of start button object */
        readonly property int startButtonBottomMargin: 100

        /** Bottom margin of page indicator object */
        readonly property int pageIndicatorBottomMargin: 50

        /** Icon sources used in entry view component */
        readonly property var iconSources: [
            "qrc:/resources/studyicon.png",
            "qrc:/resources/quizicon.png"
        ]

        /** Text placed on the start button object */
        readonly property string startButtonText: "Start"
    }

    QtObject {
        id: fonts

        /** Medium-size font used in application */
        readonly property font mediumFont: Qt.font({
            family: "Courier",
            pointSize: 14,
            bold: true
        })
    }
}
