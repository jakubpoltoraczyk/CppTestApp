#pragma once

#include <QObject>

/** Contains available dialog codes used in the whole application */
namespace DialogCode {
constexpr int APPLICATION_CLOSE = 1;
constexpr int QUIZ_ANSWER_CORRECT = 2;
constexpr int QUIZ_ANSWER_WRONG = 3;
constexpr int QUIZ_STOP = 4;
} // namespace DialogCode

/** Contains dataset of custom dialog */
class CustomDialogModel {
  Q_GADGET
  Q_PROPERTY(QString content MEMBER content CONSTANT)
  Q_PROPERTY(int buttonCode MEMBER buttonCode CONSTANT)
public:
  QString content;    ///< Contains information content to display in the dialog
  int buttonCode = 0; ///< Contains button code used to display proper buttons in the dialog

  /** Just needed by Qt property system */
  bool operator==(const CustomDialogModel&) const = default;
};
Q_DECLARE_METATYPE(CustomDialogModel)
