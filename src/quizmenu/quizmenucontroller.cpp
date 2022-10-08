#include "quizmenucontroller.h"

#include "../external/utils/utils.h"

namespace {

namespace Json {
constexpr char QUIZ_NAME[] = "quizName";
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
      auto jsonObject = Utils::determineJsonObject(filePath);
      QuizMenuPageModel pageModel;

      pageModel.quizName = jsonObject[Json::QUIZ_NAME].toString();
      pageModel.difficultyLevel =
          static_cast<QuizMenuPageModel::DifficultyLevel>(jsonObject[Json::DIFFICULTY_LEVEL].toInt());
      pageModel.areOpenQuestions = jsonObject[Json::OPEN_QUESTIONS].toBool();
      pageModel.areClosedQuestions = jsonObject[Json::CLOSED_QUESTIONS].toBool();
      pageModel.quizDuration = jsonObject[Json::QUIZ_DURATION].toInt();

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

void QuizMenuController::onCloseButtonReleased() {
  qDebug() << __PRETTY_FUNCTION__;
  emit quizMenuClosed();
}

void QuizMenuController::onStartTestButtonReleased(const QString& quizName) {
  qDebug() << __PRETTY_FUNCTION__;
  emit quizSelected(quizName);
}
