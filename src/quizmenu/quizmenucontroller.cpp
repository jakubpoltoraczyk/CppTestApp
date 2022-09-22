#include "quizmenucontroller.h"

#include "../external/datamanager/datamanager.h"

#include <QDebug>
#include <QDir>

namespace {

namespace DeserializationUtils {
QuizMenuPageModels deserializePageModels() {
  DataManager dataManager;

  return {};
}
} // namespace DeserializationUtils

} // namespace

QuizMenuController::QuizMenuController(QObject* parent)
    : QObject(parent), pageModels(DeserializationUtils::deserializePageModels()) {}
