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

    /** Contains configuration related to quiz view component */
    readonly property alias quizView: quizView

    /** Contains configuration related to study menu component */
    readonly property alias studyMenu: studyMenu

    /** Contains configuration related to custom page indicator component */
    readonly property alias customPageIndicator: customPageIndicator

    /** Contains configuration related to confirm button component */
    readonly property alias confirmButton: confirmButton

    /** Contains configuration related to image label component */
    readonly property alias imageLabel: imageLabel

    /** Contains configuration related to close button component */
    readonly property alias closeButton: closeButton

    /** Contains configuration related to custom dialog component */
    readonly property alias customDialog: customDialog

    QtObject {
        id: colors

        /** Transparent color used in application */
        readonly property color transparent: "transparent"

        /** White color used in application */
        readonly property color white: "#ffffff"

        /** Light grey color used in application */
        readonly property color lightGrey: "#eeeeee"

        /** Grey color used in application */
        readonly property color grey: "#cccccc"

        /** Dark grey color used in application */
        readonly property color darkGrey: "#aaaaaa"

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

        /** Light purpler color used in application */
        readonly property color lightPurple: "#e08df0"

        /** Purple color used in application */
        readonly property color purple: "#9739a8"

        /** Dark purple color used in application */
        readonly property color darkPurple: "#6d187d"

        /** Light cream color used in application */
        readonly property color lightCream: "#f5f4ed"

        /** Cream color used in application */
        readonly property color cream: "#d6d5bf"

        /** Dark cream color used in application */
        readonly property color darkCream: "#b8b69a"
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

        /** Contains purple gradient component */
        readonly property var purpleGradient: Gradient {
            GradientStop { position: 0.0; color: colors.darkPurple }
            GradientStop { position: 0.33; color: colors.purple }
            GradientStop { position: 1.0; color: colors.lightPurple }
        }

        /** Contains cream gradient component */
        readonly property var creamGradient: Gradient {
            GradientStop { position: 0.0; color: colors.darkCream }
            GradientStop { position: 0.33; color: colors.cream }
            GradientStop { position: 1.0; color: colors.lightCream }
        }
    }

    QtObject {
        id: applicationWindow

        /** Default width of application window */
        readonly property int defaultWidth: 800

        /** Default height of application window */
        readonly property int defaultHeight: 600

        /** Enlarged width of application window */
        readonly property int enlargedWidth: 1000

        /** Enlarged height of application window */
        readonly property int enlargedHeight: 800
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

        /** Decorated font used in application */
        readonly property font decoratedFont: Qt.font({
            family: "TeX Gyre Cursor",
            pointSize: 24,
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
            BasicController.EntryPage.TESTING,
            BasicController.EntryPage.QUIZ,
            BasicController.EntryPage.COMPILER
        ]

        /** Map consists of page type and related icon source */
        readonly property var iconSources: (new Map([
            [BasicController.EntryPage.UNDEFINED, ""],
            [BasicController.EntryPage.STUDY, "qrc:/resources/entryviewicon/studyicon.png"],
            [BasicController.EntryPage.TESTING, "qrc:/resources/entryviewicon/testingicon.png"],
            [BasicController.EntryPage.QUIZ, "qrc:/resources/entryviewicon/quizicon.png"],
            [BasicController.EntryPage.COMPILER, "qrc:/resources/entryviewicon/compilericon.png"]
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

        /** Map consists of page type and stylerelated icon source */
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
        id: quizView

        /** Top margin value between quiz timer and quiz view top border */
        readonly property int quizTimerTopMargin: 22

        /** Left margin value between quiz timer and quiz view left border */
        readonly property int quizTimerLeftMargin: 16

        /** Top margin value between question label and quiz view top border */
        readonly property int questionLabelTopMargin: 130

        /** Top margin value between answers layout and question label */
        readonly property int answersLayoutTopMargin: 70

        /** Top margin value between answer text input and question label */
        readonly property int answerTextFieldTopMargin: 100

        /** Bottom margin value between question progress bar and quiz view bottom border */
        readonly property int questionProgresBarBottomMargin: 40

        /** Spacing between items in answers layout component */
        readonly property int answersLayoutSpacing: 10

        /** Interval of quiz timer component */
        readonly property int quizTimerInterval: 1000

        /** Width of the answer text input component */
        readonly property int answerTextFieldWidth: 360

        /** Height of the answer text input component */
        readonly property int answerTextFieldHeight: 40

        /** Text displayed on the accept answer button */
        readonly property string acceptAnswerButtonText: "Accept answer"

        /** Placeholder text of the answer text field component */
        readonly property string answerTextFieldPlaceholder: "Enter your answer"

        /** Source of hour glass image */
        readonly property string hourGlassImageSource: "qrc:/resources/hourglass.png"
    }

    QtObject {
        id: studyMenu

        /** Text of start button component */
        readonly property string startButtonText: "Start topic"

        /** Value of title label top margin */
        readonly property int titleLabelTopMargin: 150
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

    QtObject {
        id: closeButton

        /** Top margin value between close button and parent component */
        readonly property int topMargin: 20

        /** Right margin value between close button and parent component */
        readonly property int rightMargin: 20

        /** List of available icon sources to use in the close button component */
        readonly property var iconSources: [
            "qrc:/resources/closebutton/closebutton1.png",
            "qrc:/resources/closebutton/closebutton2.png"
        ]
    }

    QtObject {
        id: customDialog

        /** Width of the custom dialog component */
        readonly property int width: 480

        /** Height of the custom dialog component */
        readonly property int height: 240

        /** Value of the top margin between content image label and top of the dialog */
        readonly property int contentImageLabelTopMargin: 20

        /** Width of the border used in custom dialog component */
        readonly property int borderWidth: 3

        /** Color of the border used in custom dialog component */
        readonly property color borderColor: colors.grey

        /** Color of the background in custom dialog component */
        readonly property color backgroundColor: colors.lightGrey

        /** Source of the information image */
        readonly property string informationImageSource: "qrc:/resources/information.png"
    }
}
