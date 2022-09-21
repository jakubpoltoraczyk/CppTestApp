#pragma once

#include "quizmenupagemodel.h"

#include <QObject>
#include <QVector>

class QuizMenuController : public QObject {
  Q_OBJECT
  Q_PROPERTY(QuizMenuPageModels pageModels MEMBER pageModels CONSTANT)
public:
  QuizMenuController(QObject* parent = nullptr);

private:
  QuizMenuPageModels pageModels;
};
