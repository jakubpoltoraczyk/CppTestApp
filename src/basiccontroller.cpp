#include "basiccontroller.h"

BasicController::BasicController(QObject* parent) : QObject(parent) {
  connect(&entryViewController, &EntryViewController::pageSelected, this,
          &BasicController::onEntryViewPageSelected);
}

std::vector<std::pair<QString, QObject*>> BasicController::getObjectsToRegister() {
  return {{QStringLiteral("basicController"), this},
          {QStringLiteral("entryViewController"), &entryViewController}};
}

void BasicController::onEntryViewPageSelected(EntryViewController::PageType pageType) {
  entryViewVisibility = false;
  emit entryViewVisibilityChanged();
}
