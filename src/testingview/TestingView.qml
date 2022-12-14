import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../external"

Rectangle {
    id: testingView
    anchors.fill: parent

    /** Called when component creation has been finished */
    Component.onCompleted: {
        closeButton.released.connect(testingViewController.onCloseButtonReleased)
    }

    SwipeView {
        id: testingSwipeView
        anchors.fill: parent
        currentIndex: 0

        Repeater {
            id: testingViewPages
            model: testingViewController.pageModels.length

            TestingViewPage {
                testID: testingViewController.pageModels[index].testID
                title: testingViewController.pageModels[index].title
                firstImageSource: testingViewController.pageModels[index].firstImageSource
                secondImageSource: testingViewController.pageModels[index].secondImageSource
                pickerValues: testingViewController.pageModels[index].pickerValues
            }
        }
    }

    CustomPageIndicator {
        id: pageIndicator
        swipeView: testingSwipeView
    }

    CloseButton {
        id: closeButton
    }
}
