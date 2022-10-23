import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "src/external"
import "src/external/customdialog"
import "src/entryview"
import "src/quizmenu"

ApplicationWindow {
    id: applicationWindow
    width: basicController.applicationEnlargedStatus ? GUIConfig.applicationWindow.enlargedWidth :
                                                       GUIConfig.applicationWindow.defaultWidth
    height: basicController.applicationEnlargedStatus ? GUIConfig.applicationWindow.enlargedHeight :
                                                        GUIConfig.applicationWindow.defaultHeight
    visible: true

    EntryView {
        id: mainPage
        anchors.fill: parent
        visible: basicController.entryViewVisibility
    }

    CustomDialog {
        id: customDialog
        visible: customDialogController.isVisible
    }

    Loader {
        id: quizMenu
        anchors.fill: parent
        source: basicController.quizMenuVisibility ? "src/quizmenu/QuizMenu.qml" : ""
    }

    Loader {
        id: quizView
        anchors.fill: parent
        source: basicController.quizViewVisibility ? "src/quizview/QuizView.qml" : ""
    }

    Loader {
        id: studyMenu
        anchors.fill: parent
        source: basicController.studyMenuVisibility ? "src/studymenu/StudyMenu.qml" : ""
    }

    Loader {
        id: testingView
        anchors.fill: parent
        source: basicController.testingViewVisibility ? "src/testingview/TestingView.qml" : ""
    }
}
