pragma Singleton

import QtQuick 2.15

import BasicController 1.0
import QuizMenuPageModel 1.0

Item {
    id: guiConfig

    /** Contains available component colors */
    readonly property alias colors: colors

    /** Contains available component gradients */
    readonly property alias gradients: gradients

    /** Contains configuration related to main application window component */
    readonly property alias applicationWindow: applicationWindow

    /** Contains available fonts used in application */
    readonly property alias fonts: fonts

    /** Contains configuration related to entry view component */
    readonly property alias entryView: entryView

    /** Contains configuration related to quiz menu component */
    readonly property alias quizMenu: quizMenu

    /** Contains configuration related to custom page indicator component */
    readonly property alias customPageIndicator: customPageIndicator

    /** Contains configuration related to confirm button component */
    readonly property alias confirmButton: confirmButton

    /** Contains configuration related to image label component */
    readonly property alias imageLabel: imageLabel

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

        /** Light red color used in application */
        readonly property color lightRed: "#ff6666"

        /** Red color used in application */
        readonly property color red: "#ff0000"

        /** Dark red color used in application */
        readonly property color darkRed: "#990000"

        /** Light yellow color used in application */
        readonly property color lightYellow: "#ffff99"

        /** Yellow color used in application */
        readonly property color yellow: "#ffff00"

        /** Dark yellow color used in application */
        readonly property color darkYellow: "#999900"
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

        /** Contains red gradient component */
        readonly property var redGradient: Gradient {
            GradientStop { position: 0.0; color: colors.darkRed }
            GradientStop { position: 0.33; color: colors.red }
            GradientStop { position: 1.0; color: colors.lightRed }
        }

        /** Contains yellow gradient component */
        readonly property var yellowGradient: Gradient {
            GradientStop { position: 0.0; color: colors.darkYellow }
            GradientStop { position: 0.33; color: colors.yellow }
            GradientStop { position: 1.0; color: colors.lightYellow }
        }
    }

    QtObject {
        id: applicationWindow

        /** Width of application window */
        readonly property int width: 800

        /** Height of application window */
        readonly property int height: 600
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

        /** Text of start button component */
        readonly property string startButtonText: "Start"

        /** List of available pages in entry view */
        readonly property var pages: [
            BasicController.EntryPage.STUDY,
            BasicController.EntryPage.QUIZ
        ]

        /** Map consists of page type and related icon source */
        readonly property var iconSources: (new Map([
            [BasicController.EntryPage.UNDEFINED, ""],
            [BasicController.EntryPage.STUDY, "qrc:/resources/entryviewicon/studyicon.png"],
            [BasicController.EntryPage.QUIZ, "qrc:/resources/entryviewicon/quizicon.png"]
        ]))
    }

    QtObject {
        id: quizMenu

        /** Text of start button component */
        readonly property string startButtonText: "Start test"

        /** Value of level image top margin */
        readonly property int levelImageTopMargin: 60

        /** Value of information layout top margin */
        readonly property int informationLayoutTopMargin: 30

        /** Spacing between components in the quiz information layout */
        readonly property int informationLayoutSpacing: 12

        /** Information text about difficulty */
        readonly property string difficultyInfoText: "Difficulty level: %1"

        /** Information text about open questions */
        readonly property string openQuestionsInfoText: "Open questions available"

        /** Information text about closed questions */
        readonly property string closedQuestionsInfoText: "Closed questions available"

        /** Information text about quiz duration */
        readonly property string quizDurationText: "Duration of quiz: %1 minutes"

        /** Icon source related to difficulty */
        readonly property string difficultyIconSource: "qrc:/resources/quizmenuicon/difficulty.png"

        /** Icon source related to open questions */
        readonly property string openQuestionsIconSource: "qrc:/resources/quizmenuicon/openquestions.png"

        /** Icon source related to closed questions */
        readonly property string closedQuestionsIconSource: "qrc:/resources/quizmenuicon/closedquestions.png"

        /** Icon source related to quiz duration */
        readonly property string quizDurationIconSource: "qrc:/resources/quizmenuicon/clock.png"

        /** Map consists of quiz difficulty level and related gradient */
        readonly property var gradients: (new Map([
            [QuizMenuPageModel.DifficultyLevel.EASY, gradients.cyanGradient],
            [QuizMenuPageModel.DifficultyLevel.MEDIUM, gradients.yellowGradient],
            [QuizMenuPageModel.DifficultyLevel.HARD, gradients.redGradient]
        ]))

        /** Map consists of page type and related icon source */
        readonly property var iconLevelSources: (new Map([
            [QuizMenuPageModel.DifficultyLevel.UNDEFINED, ""],
            [QuizMenuPageModel.DifficultyLevel.EASY, "qrc:/resources/quizmenuicon/easyowl.png"],
            [QuizMenuPageModel.DifficultyLevel.MEDIUM, "qrc:/resources/quizmenuicon/mediumowl.png"],
            [QuizMenuPageModel.DifficultyLevel.HARD, "qrc:/resources/quizmenuicon/hardowl.png"]
        ]))

        /** Map consists of quiz difficulty level and related difficulty name */
        readonly property var difficultyNames: (new Map([
            [QuizMenuPageModel.DifficultyLevel.EASY, "Easy"],
            [QuizMenuPageModel.DifficultyLevel.MEDIUM, "Medium"],
            [QuizMenuPageModel.DifficultyLevel.HARD, "Hard"]
        ]))
    }

    QtObject {
        id: customPageIndicator

        /** Bottom margin of custom page indicator component */
        readonly property int bottomMargin: 50
    }

    QtObject {
        id: confirmButton

        /** Width of confirm button object */
        readonly property int width: 200

        /** Height of confirm button object */
        readonly property int height: 60

        /** Bottom margin of confirm button object */
        readonly property int bottomMargin: 100

        /** Default text placed on the confirm button object */
        readonly property string defaultText: "Confirm"
    }

    QtObject {
        id: imageLabel

        /** Spacing between image icon and label text */
        readonly property int spacing: 12
    }
}
