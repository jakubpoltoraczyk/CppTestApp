#include "quizviewcontroller.h"

#include "../external/utils/utils.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>

namespace {

const QString QUESTIONS_UPDATED = QStringLiteral("Questions for the quiz '%1' have been updated");

namespace Json {
constexpr char TYPE[] = "type";
constexpr char IMAGE[] = "image";
constexpr char QUESTION[] = "question";
constexpr char ANSWERS[] = "answers";
constexpr char CORRECT_ANSWER[] = "correctAnswer";
} // namespace Json

QuizQuestionModels deserializeQuizQuestionModels(const QStringList& questionFilePaths) {
  QuizQuestionModels viewModels;
  viewModels.reserve(questionFilePaths.size());

  for (const auto& filePath : questionFilePaths) {
    auto fileContent = Utils::readFileContent(filePath);
    auto jsonDocument = QJsonDocument::fromJson(fileContent);
    auto jsonObject = jsonDocument.object();

    auto type = static_cast<QuizQuestionModel::QuestionType>(jsonObject[Json::TYPE].toInt());
    auto image = jsonObject[Json::IMAGE].toString();
    auto question = jsonObject[Json::QUESTION].toString();
    auto answers = jsonObject[Json::ANSWERS].toVariant().toStringList();
    auto correctAnswer = jsonObject[Json::CORRECT_ANSWER].toInt();

    QuizQuestionModel quizViewModel{.type = type,
                                    .image = image,
                                    .question = question,
                                    .answers = answers,
                                    .correctAnswer = correctAnswer};
    viewModels.push_back(std::move(quizViewModel));
  }

  return viewModels;
}

} // namespace

QuizViewController::QuizViewController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                                       QObject* parent)
    : QObject(parent), dataDirectoryManager(newDataDirectoryManager) {}

void QuizViewController::updateQuestions(const QString& quiz) {
  auto questionFilePaths = dataDirectoryManager->getQuizQuestionFilePaths(quiz);
  questionModels = deserializeQuizQuestionModels(questionFilePaths);
  qDebug() << QUESTIONS_UPDATED.arg(quiz);
}
