#include "customdialogcontroller.h"

#include "../utils/utils.h"

#include <QMessageBox>

namespace {

namespace Json {
constexpr char CONTENT[] = "content";
constexpr char IS_ABORT[] = "isAbort";
constexpr char IS_OK[] = "isOk";
} // namespace Json

CustomDialogModel deserializeDialogModel(const QString& filePath) {
  CustomDialogModel model;

  auto jsonObject = Utils::determineJsonObject(filePath);
  model.content = jsonObject[Json::CONTENT].toString();
  if (jsonObject[Json::IS_OK].toBool()) {
    model.buttonCode |= QMessageBox::Ok;
  }
  if (jsonObject[Json::IS_ABORT].toBool()) {
    model.buttonCode |= QMessageBox::Abort;
  }

  return model;
}

} // namespace

CustomDialogController::CustomDialogController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                                               QObject* parent)
    : QObject(parent), dataDirectoryManager(newDataDirectoryManager) {}

void CustomDialogController::showDialog(int code) {
  dialogModel = deserializeDialogModel(dataDirectoryManager->getDialogFilePath(code));
  emit dialogModelChanged();
  changeVisibility(true);
}

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
