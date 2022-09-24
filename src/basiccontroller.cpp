#include "basiccontroller.h"

#include "external/utils/utils.h"

#include <QDebug>

namespace {

const QString ENTRY_PAGE_SELECTED = QStringLiteral("%1 entry view page has been selected");
const QString VIEW_CHANGED = QStringLiteral("View has been changed from %1 to %2");

const std::unordered_map<BasicController::EntryPage, BasicController::View> ENTRY_PAGE_TO_VIEW{
    {BasicController::EntryPage::STUDY, BasicController::View::STUDY_VIEW},
    {BasicController::EntryPage::QUIZ, BasicController::View::QUIZ_MENU}};

} // namespace

BasicController::BasicController(QObject* parent)
    : QObject(parent), dataDirectoryManager(std::make_shared<DataDirectoryManager>()),
      currentView(View::ENTRY_VIEW), quizMenuController(dataDirectoryManager) {}

std::vector<std::pair<QString, QObject*>> BasicController::getObjectsToRegister() {
  return {{QStringLiteral("basicController"), this},
          {QStringLiteral("quizMenuController"), &quizMenuController}};
}

void BasicController::onEntryPageSelected(EntryPage entryPage) {
  qDebug() << ENTRY_PAGE_SELECTED.arg(Utils::qenumToString(entryPage));
  auto newView = ENTRY_PAGE_TO_VIEW.at(entryPage);
  changeView(newView);
}

void BasicController::changeView(View newView) {
  switch (newView) {
  case View::ENTRY_VIEW:
  case View::STUDY_VIEW:
    return;

  case View::QUIZ_MENU:
    quizMenuVisibility = true;
    emit quizMenuVisibilityChanged();
    break;
  }

  qDebug() << VIEW_CHANGED.arg(Utils::qenumToString(currentView), Utils::qenumToString(newView));
  currentView = newView;
}
