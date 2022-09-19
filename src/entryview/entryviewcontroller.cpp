#include "entryviewcontroller.h"

#include <QDebug>

namespace {

const QString PAGE_SELECTED = QStringLiteral("%1 page has been selected");

}

void EntryViewController::onStartButtonReleased(EntryViewController::PageType pageType) {
  qInfo() << PAGE_SELECTED.arg(static_cast<int>(pageType));
  emit pageSelected(pageType);
}
