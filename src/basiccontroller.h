#pragma once

#include "external/customdialog/customdialogcontroller.h"
#include "external/datadirectorymanager/datadirectorymanager.h"
#include "quizmenu/quizmenucontroller.h"
#include "quizview/quizviewcontroller.h"
#include "studymenu/studymenucontroller.h"
#include "studyview/studyviewcontroller.h"
#include "testingview/testingviewcontroller.h"

#include <QObject>

#include <memory>
#include <vector>

/** Class which represents application basic controller */
class BasicController : public QObject {
  Q_OBJECT
  Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")
  Q_PROPERTY(
      bool applicationEnlargedStatus MEMBER applicationEnlargedStatus NOTIFY applicationEnlargedStatusChanged)
  Q_PROPERTY(bool entryViewVisibility MEMBER entryViewVisibility NOTIFY entryViewVisibilityChanged)
  Q_PROPERTY(bool quizMenuVisibility MEMBER quizMenuVisibility NOTIFY quizMenuVisibilityChanged)
  Q_PROPERTY(bool quizViewVisibility MEMBER quizViewVisibility NOTIFY quizViewVisibilityChanged)
  Q_PROPERTY(bool studyMenuVisibility MEMBER studyMenuVisibility NOTIFY studyMenuVisibilityChanged)
  Q_PROPERTY(bool testingViewVisibility MEMBER testingViewVisibility NOTIFY testingViewVisibilityChanged)
  Q_PROPERTY(bool studyViewVisibility MEMBER studyViewVisibility NOTIFY studyViewVisibilityChanged)
public:
  /** Contains available entry page types */
  enum class EntryPage { UNDEFINED = -1, STUDY, TESTING, QUIZ, COMPILER };
  Q_ENUM(EntryPage)

  /** Contains available view types used in the application */
  enum class View { ENTRY_VIEW, STUDY_MENU, TESTING_VIEW, QUIZ_MENU, COMPILER, QUIZ_VIEW, STUDY_VIEW };
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
  /** Emitted when application enlarged status has been changed */
  void applicationEnlargedStatusChanged();

  /** Emitted when entry view visibility has been changed */
  void entryViewVisibilityChanged();

  /** Emitted when quiz menu visibility has been changed */
  void quizMenuVisibilityChanged();

  /** Emitted when quiz view visibility has been changed */
  void quizViewVisibilityChanged();

  /** Emitted when study menu visibility has been changed */
  void studyMenuVisibilityChanged();

  /** Emitted when testing view visibility has been changed */
  void testingViewVisibilityChanged();

  /** Emitted when study view visibility has been changed */
  void studyViewVisibilityChanged();

public slots:
  /**
   * @brief Called when entry page has been selected
   * @param entryPage Type of page which has been selected
   */
  void onEntryPageSelected(BasicController::EntryPage entryPage);

  /** Called when user decided to close entry view */
  void onEntryViewClosed();

  /** Called when user decided to close quiz menu */
  void onQuizMenuClosed();

  /** Called when user decided to close quiz view */
  void onQuizViewClosed();

  /**
   * @brief Called when the new quiz has been just selected
   * @param quizName Name of the new selected quiz
   */
  void onQuizSelected(const QString& quizName);

  /** Called when user decided to close study menu */
  void onStudyMenuClosed();

  /** Called when user decided to close testing view */
  void onTestingViewClosed();

  /** Called when user decided to close study view */
  void onStudyViewClosed();

  /**
   * @brief Called when study topic has been just selected
   * @param topic Selected topic
   */
  void onStudyTopicSelected(StudyMenuPageModel::Topic topic);

private:
  /**
   * @brief Change current view using new selected view type
   * @param newView Type of the new view
   */
  void changeView(View newView);

  /** Close each view expect main entry view */
  void closeEachView();

  bool applicationEnlargedStatus = false; ///< Contains enlarged status of whole application
  bool entryViewVisibility = true;        ///< Contains visibility status of entry view component
  bool quizMenuVisibility = false;        ///< Contains visibility status of quiz menu component
  bool quizViewVisibility = false;        ///< Contains visibility status of quiz view component
  bool studyMenuVisibility = false;       ///< Contains visibility status of study menu component
  bool testingViewVisibility = false;     ///< Contains visibility status of testing view component
  bool studyViewVisibility = false;       ///< Contains visibility status of study view component

  std::shared_ptr<DataDirectoryManager> dataDirectoryManager;
  std::shared_ptr<CustomDialogController> customDialogController;
  View currentView;
  QuizMenuController quizMenuController;
  QuizViewController quizViewController;
  StudyMenuController studyMenuController;
  TestingViewController testingViewController;
  StudyViewController studyViewController;
};
