#include "customdialogcontroller.h"

#include <QDebug>

#include <thread>

CustomDialogController::CustomDialogController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                                               QObject* parent)
    : QObject(parent), dataDirectoryManager(newDataDirectoryManager) {}

void CustomDialogController::showDialog() { changeVisibility(true); }

void CustomDialogController::onAccepted() {
  if (!isVisible) {
    return;
  }

  qDebug() << __PRETTY_FUNCTION__;
  changeVisibility(false);
  emit dialogClosed(ExitStatus::ACCEPTED);
}

void CustomDialogController::onRejected() {
  if (!isVisible) {
    return;
  }

  qDebug() << __PRETTY_FUNCTION__;
  changeVisibility(false);
  emit dialogClosed(ExitStatus::REJECTED);
}

void CustomDialogController::changeVisibility(bool newVisibility) {
  isVisible = newVisibility;
  emit visibilityChanged();
}
