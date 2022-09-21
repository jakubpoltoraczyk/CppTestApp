import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "src/external"
import "src/entryview"
import "src/quizmenu"

ApplicationWindow {
    id: applicationWindow
    width: GUIConfig.shared.applicationWidth
    height: GUIConfig.shared.applicationHeight
    visible: true

    EntryView {
        id: mainPage
        anchors.fill: parent
        visible: basicController.entryViewVisibility
    }

    Loader {
        id: quizMenu
        anchors.fill: parent
        source: basicController.quizMenuVisibility ? "src/quizmenu/QuizMenu.qml" : ""
    }
}
