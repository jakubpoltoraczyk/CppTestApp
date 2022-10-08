#pragma once

#include "../external/datadirectorymanager/datadirectorymanager.h"
#include "quizviewmodel.h"

#include <QObject>

#include <memory>

class QuizViewController : public QObject {
  Q_OBJECT
public:
  /**
   * @brief Provide value of current quiz duration
   * @return Current quiz duration in seconds
   */
  Q_INVOKABLE int getQuizDuration();

  /**
   * @brief Create a default instance of QuizViewController class
   * @param newDataDirectoryManager Used to manage application data directory
   * @param parent Pointer to parent widget
   */
  QuizViewController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                     QObject* parent = nullptr);

  /**
   * @brief Update questions to adjust them to the new selected quiz
   * @param newQuizName Name of the quiz for which questions will be adjusted
   */
  void updateQuestions(const QString& newQuizName);

private:
  std::shared_ptr<DataDirectoryManager> dataDirectoryManager;
  QuizQuestionModels questionModels;
  QString quizName;
};
