#pragma once

#include "entryview/entryviewcontroller.h"
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
   * @brief Called when entry view page has been selected
   * @param pageType Type of page which has been selected
   */
  void onEntryViewPageSelected(EntryViewController::PageType pageType);

private:
  bool entryViewVisibility = true;
  bool quizMenuVisibility = false;

  std::shared_ptr<DataDirectoryManager> dataDirectoryManager;

  EntryViewController entryViewController;
  QuizMenuController quizMenuController;
};
