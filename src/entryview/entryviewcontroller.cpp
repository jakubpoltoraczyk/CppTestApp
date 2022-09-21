#include "entryviewcontroller.h"

#include <QDebug>

namespace {

const QString PAGE_SELECTED = QStringLiteral("%1 page has been selected");

} // namespace

void EntryViewController::onStartButtonReleased(EntryViewController::PageType pageType) {
  auto enumValue = QVariant::fromValue(pageType).toString();
  qInfo() << PAGE_SELECTED.arg(enumValue);
  emit pageSelected(pageType);
}
