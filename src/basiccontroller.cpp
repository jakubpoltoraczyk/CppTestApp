#include "basiccontroller.h"

#include "external/utils/utils.h"

#include <QCoreApplication>
#include <QDebug>

namespace {

constexpr char APPLICATION_CLOSED[] = "Application has been successfully closed";
const QString ENTRY_PAGE_SELECTED = QStringLiteral("%1 entry view page has been selected");
const QString VIEW_CHANGED = QStringLiteral("View has been changed from %1 to %2");

const std::unordered_map<BasicController::EntryPage, BasicController::View> ENTRY_PAGE_TO_VIEW{
    {BasicController::EntryPage::STUDY, BasicController::View::STUDY_VIEW},
    {BasicController::EntryPage::TESTING, BasicController::View::TESTING_VIEW},
    {BasicController::EntryPage::QUIZ, BasicController::View::QUIZ_MENU},
    {BasicController::EntryPage::COMPILER, BasicController::View::COMPILER}};

} // namespace

BasicController::BasicController(QObject* parent)
    : QObject(parent), dataDirectoryManager(std::make_shared<DataDirectoryManager>()),
      currentView(View::ENTRY_VIEW), quizMenuController(dataDirectoryManager) {
  connect(&quizMenuController, &QuizMenuController::quizMenuClosed, this, &BasicController::onQuizMenuClosed);
}

std::vector<std::pair<QString, QObject*>> BasicController::getObjectsToRegister() {
  return {{QStringLiteral("basicController"), this},
          {QStringLiteral("quizMenuController"), &quizMenuController}};
}

void BasicController::onEntryPageSelected(EntryPage entryPage) {
  qDebug() << ENTRY_PAGE_SELECTED.arg(Utils::qenumToString(entryPage));
  auto newView = ENTRY_PAGE_TO_VIEW.at(entryPage);
  changeView(newView);
}

void BasicController::onEntryViewClosed() {
  qDebug() << APPLICATION_CLOSED;
  QCoreApplication::quit();
}

void BasicController::onQuizMenuClosed() { changeView(View::ENTRY_VIEW); }

void BasicController::changeView(View newView) {
  switch (newView) {
  case View::ENTRY_VIEW:
    closeEachView();
    break;

  case View::QUIZ_MENU:
    quizMenuVisibility = true;
    emit quizMenuVisibilityChanged();
    break;

  case View::STUDY_VIEW:
  case View::TESTING_VIEW:
  case View::COMPILER:
    ///< @todo Implement logic here
    return;
  }

  qDebug() << VIEW_CHANGED.arg(Utils::qenumToString(currentView), Utils::qenumToString(newView));
  currentView = newView;
}

void BasicController::closeEachView() {
  quizMenuVisibility = false;
  emit quizMenuVisibilityChanged();
}
