#pragma once

#include "external/datadirectorymanager/datadirectorymanager.h"
#include "quizmenu/quizmenucontroller.h"

#include <QObject>

#include <memory>
#include <vector>

/** Class which represents application basic controller */
class BasicController : public QObject {
  Q_OBJECT
  Q_PROPERTY(bool entryViewVisibility MEMBER entryViewVisibility NOTIFY entryViewVisibilityChanged)
  Q_PROPERTY(bool quizMenuVisibility MEMBER quizMenuVisibility NOTIFY quizMenuVisibilityChanged)
public:
  /** Contains available entry page types */
  enum class EntryPage { UNDEFINED = -1, STUDY, QUIZ };
  Q_ENUM(EntryPage)

  /** Contains available view types used in the application */
  enum class View { ENTRY_VIEW, STUDY_VIEW, QUIZ_MENU };
  Q_ENUM(View)

  /**
   * @brief Create an instance of BasicController class
   * @param parent Pointer to parent widget
   */
  BasicController(QObject* parent = nullptr);

  /**
   * @brief Provide objects to register in QML part of application
   * @return Container of pairs (object's name and pointer to its instance) to register
   */
  std::vector<std::pair<QString, QObject*>> getObjectsToRegister();

signals:
  /** Emitted when entry view visibility has been changed */
  void entryViewVisibilityChanged();

  /** Emitted when quiz menu visibility has been changed */
  void quizMenuVisibilityChanged();

public slots:
  /**
   * @brief Called when entry page has been selected
   * @param entryPage Type of page which has been selected
   */
  void onEntryPageSelected(EntryPage entryPage);

  /** Called when user decided to exit entry view */
  void onEntryViewExited();

  /** Called when user decided to exit quiz menu */
  void onQuizMenuExited();

private:
  /**
   * @brief Change current view using new selected view type
   * @param newView Type of the new view
   */
  void changeView(View newView);

  /** Close each view expect main entry view */
  void closeEachView();

  bool entryViewVisibility = true;
  bool quizMenuVisibility = false;

  std::shared_ptr<DataDirectoryManager> dataDirectoryManager;
  View currentView;

  QuizMenuController quizMenuController;
};
