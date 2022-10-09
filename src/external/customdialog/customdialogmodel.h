#pragma once

#include <QObject>

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
