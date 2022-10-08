#pragma once

#include <QObject>
#include <QStringList>
#include <QVector>

/** Contains data related to quiz question */
class QuizQuestionModel {
  Q_GADGET
  Q_PROPERTY(QuestionType type MEMBER type CONSTANT)
  Q_PROPERTY(QString image MEMBER image CONSTANT)
  Q_PROPERTY(QString question MEMBER question CONSTANT)
  Q_PROPERTY(QStringList answers MEMBER answers CONSTANT)
  Q_PROPERTY(int correctAnswer MEMBER correctAnswer CONSTANT)
public:
  /** Contains available quiz question types */
  enum class QuestionType { CLOSED, OPEN };
  Q_ENUM(QuestionType)

  QuestionType type;   ///< Contains type of question
  QString image;       ///< Contains source of image to display
  QString question;    ///< Contains question to ask
  QStringList answers; ///< If question type is closed it contains available answers with correct one,
                       ///< otherwise for open question each answer is correct
  int correctAnswer;   ///< If question type is closed it contains correct answer index, otherwise for open
                       ///< question contains always -1 value
};
Q_DECLARE_METATYPE(QuizQuestionModel)

using QuizQuestionModels = QVector<QuizQuestionModel>;
Q_DECLARE_METATYPE(QuizQuestionModels)
