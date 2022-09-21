pragma Singleton

import QtQuick 2.15

import EntryViewController 1.0
import QuizMenuPageModel 1.0

Item {
    id: guiConfig

    /** Contains available component colors */
    readonly property alias colors: colors

    /** Contains available component gradients */
    readonly property alias gradients: gradients

    /** Contains configuration shared between different components */
    readonly property alias shared: shared

    /** Contains available fonts used in application */
    readonly property alias fonts: fonts

    /** Contains configuration related to entry view component */
    readonly property alias entryView: entryView

    /** Contains configuration related to quiz menu component */
    readonly property alias quizMenu: quizMenu

    QtObject {
        id: colors

        /** Light blue color used in application */
        readonly property color lightBlue: "#7f9be3"

        /** Blue color used in application */
        readonly property color blue: "#5068a6"

        /** Dark blue color used in application */
        readonly property color darkBlue: "#243561"

        /** Light cyan color used in application */
        readonly property color lightCyan: "#88fcfa"

        /** Cyan color used in application */
        readonly property color cyan: "#53dbd9"

        /** Dark cyan color used in application */
        readonly property color darkCyan: "#1c8a88"

        /** Green color used in application */
        readonly property color green: "#3bbf74"
    }

    QtObject {
        id: gradients

        /** Contains blue gradient component */
        readonly property var blueGradient: Gradient {
            GradientStop { position: 0.0; color: colors.darkBlue }
            GradientStop { position: 0.33; color: colors.blue }
            GradientStop { position: 1.0; color: colors.lightBlue }
        }

        /** Contains cyan gradient component */
        readonly property var cyanGradient: Gradient {
            GradientStop { position: 0.0; color: colors.darkCyan }
            GradientStop { position: 0.33; color: colors.cyan }
            GradientStop { position: 1.0; color: colors.lightCyan }
        }
    }

    QtObject {
        id: shared

        /** Width of application window */
        readonly property int applicationWidth: 800

        /** Height of application window */
        readonly property int applicationHeight: 600

        /** Bottom margin of any page indicator component used in application */
        readonly property int pageIndicatorBottomMargin: 50
    }

    QtObject {
        id: fonts

        /** Small-size font used in application */
        readonly property font smallFont: Qt.font({
            family: "Courier",
            pointSize: 12,
            bold: true
        })

        /** Medium-size font used in application */
        readonly property font mediumFont: Qt.font({
            family: "Courier",
            pointSize: 14,
            bold: true
        })
    }

    QtObject {
        id: entryView

        /** Width of start button object */
        readonly property int startButtonWidth: 200

        /** Height of start button object */
        readonly property int startButtonHeight: 60

        /** Bottom margin of start button object */
        readonly property int startButtonBottomMargin: 100

        /** Text placed on the start button object */
        readonly property string startButtonText: "Start"

        /** List of available pages in entry view */
        readonly property var pages: [
            EntryViewController.PageType.STUDY,
            EntryViewController.PageType.QUIZ
        ]

        /** Map consists of page type and related icon source */
        readonly property var iconSources: (new Map([
            [EntryViewController.PageType.UNDEFINED, ""],
            [EntryViewController.PageType.STUDY, "qrc:/resources/entryviewicon/studyicon.png"],
            [EntryViewController.PageType.QUIZ, "qrc:/resources/entryviewicon/quizicon.png"]
        ]))
    }

    QtObject {
        id: quizMenu

        /** Map consists of quiz difficulty level and related gradient */
        readonly property var gradients: (new Map([
            [QuizMenuPageModel.DifficultyLevel.EASY, gradients.cyanGradient],
            [QuizMenuPageModel.DifficultyLevel.MEDIUM, gradients.cyanGradient],
            [QuizMenuPageModel.DifficultyLevel.HARD, gradients.cyanGradient]
        ]))
    }
}
