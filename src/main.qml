import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "external"
import "mainpage"

ApplicationWindow {
    id: applicationWindow
    width: GUIConfig.applicationWindow.width
    height: GUIConfig.applicationWindow.height
    color: GUIConfig.colors.lightGrey
    visible: true

    MainPage {
        id: mainPage
        anchors.fill: parent
    }
}
