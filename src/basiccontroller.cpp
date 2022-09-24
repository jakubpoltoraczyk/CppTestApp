#include "basiccontroller.h"

#include <QDebug>

BasicController::BasicController(QObject* parent)
    : QObject(parent), dataDirectoryManager(std::make_shared<DataDirectoryManager>()),
      quizMenuController(dataDirectoryManager) {
  connect(&entryViewController, &EntryViewController::pageSelected, this,
          &BasicController::onEntryViewPageSelected);
}

std::vector<std::pair<QString, QObject*>> BasicController::getObjectsToRegister() {
  return {{QStringLiteral("basicController"), this},
          {QStringLiteral("entryViewController"), &entryViewController},
          {QStringLiteral("quizMenuController"), &quizMenuController}};
}

void BasicController::onEntryViewPageSelected(EntryViewController::PageType pageType) {
  entryViewVisibility = false;
  emit entryViewVisibilityChanged();

  switch (pageType) {
  case EntryViewController::PageType::QUIZ:
    quizMenuVisibility = true;
    emit quizMenuVisibilityChanged();
    break;

  case EntryViewController::PageType::STUDY:
    break;

  case EntryViewController::PageType::UNDEFINED:
    break;
  }
}
