#pragma once

#include <QObject>
#include <QVector>

/** Contains dataset of study menu page */
class StudyMenuPageModel {
  Q_GADGET
  Q_PROPERTY(QString title MEMBER title CONSTANT)
  Q_PROPERTY(Topic topic MEMBER topic CONSTANT)
public:
  /** Contains available topic types of study menu page */
  enum class Topic { UNDEFINED, SMART_POINTERS, MOVE_SEMANTICS, STL_CONTAINERS };
  Q_ENUM(Topic)

  QString title; ///< Contains title of selected study menu page
  Topic topic;   ///< Contains topic type of selected study menu page
};
Q_DECLARE_METATYPE(StudyMenuPageModel)

using StudyMenuPageModels = QVector<StudyMenuPageModel>;
Q_DECLARE_METATYPE(StudyMenuPageModels)
