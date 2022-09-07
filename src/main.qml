import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "external"
import "entryview"

ApplicationWindow {
    id: applicationWindow
    width: GUIConfig.applicationWindow.width
    height: GUIConfig.applicationWindow.height
    visible: true

    EntryView {
        id: mainPage
        anchors.fill: parent
    }
}
