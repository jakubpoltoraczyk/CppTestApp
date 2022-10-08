#pragma once

#include "../external/datadirectorymanager/datadirectorymanager.h"
#include "quizmenupagemodel.h"

#include <memory>

/** Class which represents controller for quiz menu component */
class QuizMenuController : public QObject {
  Q_OBJECT
  Q_PROPERTY(QuizMenuPageModels pageModels MEMBER pageModels CONSTANT)
public:
  /**
   * @brief Create a default instance of QuizMenuController class
   * @param newDataDirectoryManager Used to manage application data directory
   * @param parent Pointer to parent widget
   */
  QuizMenuController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                     QObject* parent = nullptr);

signals:
  /** Emitted when user decided to close quiz menu */
  void quizMenuClosed();

  /**
   * @brief Emitted when user selected the new quiz
   * @param quizName Name of the selected quiz
   */
  void quizSelected(const QString& quizName);

public slots:
  /** Called when close button has been released */
  void onCloseButtonReleased();

  /**
   * @brief Called when start test button has been released
   * @param quizName Name of the selected quiz
   */
  void onStartTestButtonReleased(const QString& quizName);

private:
  std::shared_ptr<DataDirectoryManager> dataDirectoryManager;
  QuizMenuPageModels pageModels;
};
