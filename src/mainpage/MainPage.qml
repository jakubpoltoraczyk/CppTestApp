import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    id: mainPage

    header: TabBar {

        Repeater{
            id: tabBarRepeater
            model: ["Smart pointers", "Move semantics", "STL containers", "STL algorithms", "Multithreading", "Other"]

            TabButton {
                text: modelData
            }
        }
    }

    footer: Rectangle {
        height: 100
        color: "blue"
    }
}
