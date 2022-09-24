#include "quizmenucontroller.h"

#include "../external/utils/utils.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace {

namespace Json {
constexpr char DIFFICULTY_LEVEL[] = "difficultyLevel";
constexpr char OPEN_QUESTIONS[] = "openQuestions";
constexpr char CLOSED_QUESTIONS[] = "closedQuestions";
constexpr char QUIZ_DURATION[] = "quizDuration";
} // namespace Json

QuizMenuPageModels deserializePageModels(const QStringList& quizConfigurationFilePaths) {
  QuizMenuPageModels pageModels;
  pageModels.reserve(quizConfigurationFilePaths.size());

  for (const auto& filePath : quizConfigurationFilePaths) {
    try {
      auto fileContent = Utils::readFileContent(filePath);
      auto jsonDocument = QJsonDocument::fromJson(fileContent);
      auto jsonObject = jsonDocument.object();

      auto difficultyLevel =
          static_cast<QuizMenuPageModel::DifficultyLevel>(jsonObject[Json::DIFFICULTY_LEVEL].toInt());
      auto areOpenQuestions = jsonObject[Json::OPEN_QUESTIONS].toBool();
      auto areClosedQuestions = jsonObject[Json::CLOSED_QUESTIONS].toBool();
      auto quizDuration = jsonObject[Json::QUIZ_DURATION].toInt();

      QuizMenuPageModel pageModel{.difficultyLevel = difficultyLevel,
                                  .areOpenQuestions = areOpenQuestions,
                                  .areClosedQuestions = areClosedQuestions,
                                  .quizDuration = quizDuration};
      pageModels.push_back(std::move(pageModel));
    } catch (const std::logic_error& error) {
      qDebug() << error.what();
    }
  }

  return pageModels;
}

} // namespace

QuizMenuController::QuizMenuController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                                       QObject* parent)
    : QObject(parent), dataDirectoryManager(newDataDirectoryManager),
      pageModels(deserializePageModels(dataDirectoryManager->getQuizConfigurationFilePaths())) {}
