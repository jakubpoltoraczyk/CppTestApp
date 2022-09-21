#include "quizmenucontroller.h"

QuizMenuController::QuizMenuController(QObject* parent) : QObject(parent) {
  pageModels.push_back(QuizMenuPageModel{QuizMenuPageModel::DifficultyLevel::EASY, true, false});
}
