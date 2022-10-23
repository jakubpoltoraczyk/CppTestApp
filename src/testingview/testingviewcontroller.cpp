#include "testingviewcontroller.h"

#include "resources/test01/test01.h"

#include <QDebug>

#include <chrono>

TestingViewController::TestingViewController(
    std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
    std::shared_ptr<CustomDialogController> newCustomDialogController, QObject* parent)
    : QObject(parent), dataDirectoryManager(newDataDirectoryManager),
      customDialogController(newCustomDialogController) {}

void TestingViewController::onCloseButtonReleased() {
  qDebug() << __PRETTY_FUNCTION__;
  emit testingViewClosed();
}

void TestingViewController::onStartTestButtonReleased() {
  auto start = std::chrono::high_resolution_clock::now();
  Test01::test01ObsoleteVersion(1000);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  qDebug() << duration.count();
}
