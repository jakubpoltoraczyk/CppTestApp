#pragma once

#include <QObject>
#include <QVector>

/** Contains dataset of quiz menu page */
class QuizMenuPageModel {
  Q_GADGET
public:
  /** Contains available difficulty levels */
  enum class DifficultyLevel { UNDEFINED, EASY, MEDIUM, HARD };
  Q_ENUM(DifficultyLevel)

  DifficultyLevel difficultyLevel; ///< Level of quiz difficulty
  bool areOpenQuestions;           ///< Contains information if open questions are available
  bool areClosedQuestions;         ///< Contains information if closed questions are available
};
Q_DECLARE_METATYPE(QuizMenuPageModel)

using QuizMenuPageModels = QVector<QuizMenuPageModel>;
Q_DECLARE_METATYPE(QuizMenuPageModels)
