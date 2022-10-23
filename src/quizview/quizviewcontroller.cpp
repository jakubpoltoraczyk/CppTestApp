#include "quizviewcontroller.h"

#include "../external/utils/utils.h"

namespace {

const QString QUESTIONS_UPDATED = QStringLiteral("Questions for the quiz '%1' have been updated");
const QString QUIZ_RESULT_MESSAGE = QStringLiteral("You've scored %1 out of %2 points");

namespace Json {
constexpr char QUIZ_DURATION[] = "quizDuration";
constexpr char TYPE[] = "type";
constexpr char IMAGE[] = "image";
constexpr char QUESTION[] = "question";
constexpr char ANSWERS[] = "answers";
constexpr char CORRECT_ANSWER[] = "correctAnswer";
} // namespace Json

QuizQuestionModels deserializeQuizQuestionModels(const QStringList& questionFilePaths) {
  QuizQuestionModels questionModels;
  questionModels.reserve(questionFilePaths.size());

  for (const auto& filePath : questionFilePaths) {
    auto jsonObject = Utils::determineJsonObject(filePath);
    QuizQuestionModel questionModel;

    questionModel.type = static_cast<QuizQuestionModel::QuestionType>(jsonObject[Json::TYPE].toInt());
    questionModel.image = jsonObject[Json::IMAGE].toString();
    questionModel.question = jsonObject[Json::QUESTION].toString();
    questionModel.answers = jsonObject[Json::ANSWERS].toVariant().toStringList();
    questionModel.correctAnswer = jsonObject[Json::CORRECT_ANSWER].toInt();

    questionModels.push_back(std::move(questionModel));
  }

  return questionModels;
}

int deserializeQuizDuration(const QString& configFilePath) {
  auto jsonObject = Utils::determineJsonObject(configFilePath);
  return jsonObject[Json::QUIZ_DURATION].toInt();
}

} // namespace

int QuizViewController::getQuizDuration() {
  auto quizConfigurationFilePaths = dataDirectoryManager->getQuizConfigurationFilePaths();
  auto currentQuizConfig = quizConfigurationFilePaths.filter(quizName);
  return deserializeQuizDuration(currentQuizConfig.first());
}

QuizViewController::QuizViewController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                                       std::shared_ptr<CustomDialogController> newCustomDialogController,
                                       QObject* parent)
    : QObject(parent), dataDirectoryManager(newDataDirectoryManager),
      customDialogController(newCustomDialogController) {}

void QuizViewController::updateQuestions(const QString& newQuizName) {
  quizName = newQuizName;
  auto questionFilePaths = dataDirectoryManager->getQuizQuestionFilePaths(quizName);
  questionModels = deserializeQuizQuestionModels(questionFilePaths);
  qDebug() << QUESTIONS_UPDATED.arg(quizName);
}

void QuizViewController::onStopTestButtonReleased() {
  qDebug() << __PRETTY_FUNCTION__;
  customDialogController->showDialog(DialogCode::QUIZ_STOP);
  Utils::connectOnDialogClosed(customDialogController, [this](CustomDialogController::ExitStatus exitStatus) {
    if (exitStatus == CustomDialogController::ExitStatus::REJECTED) {
      return;
    }
    emit quizViewClosed();
  });
}

void QuizViewController::onAnswerSelected(int answerIndex) {
  if (auto model = questionModels.at(currentQuestion); answerIndex == model.correctAnswer) {
    ++correctAnswers;
    customDialogController->showDialog(DialogCode::QUIZ_ANSWER_CORRECT);
  } else {
    customDialogController->showDialog(DialogCode::QUIZ_ANSWER_WRONG);
  }

  if (++currentQuestion == questionModels.size()) {
    showResultDialog();
    return;
  }

  emit currentQuestionChanged();
}

void QuizViewController::onAnswerEntered(const QString& answerContent) {
  if (auto model = questionModels.at(currentQuestion); model.answers.contains(answerContent)) {
    ++correctAnswers;
    customDialogController->showDialog(DialogCode::QUIZ_ANSWER_CORRECT);
  } else {
    customDialogController->showDialog(DialogCode::QUIZ_ANSWER_WRONG);
  }

  if (++currentQuestion == questionModels.size()) {
    showResultDialog();
    return;
  }

  emit currentQuestionChanged();
}

void QuizViewController::onTimeout() {
  qDebug() << __PRETTY_FUNCTION__;
  showResultDialog();
}

void QuizViewController::showResultDialog() {
  emit completeQuestionProgresBar();
  customDialogController->showDialog(QUIZ_RESULT_MESSAGE.arg(correctAnswers).arg(questionModels.size()), true,
                                     false);
  Utils::connectOnDialogClosed(customDialogController,
                               [this](CustomDialogController::ExitStatus) { emit quizViewClosed(); });
}
