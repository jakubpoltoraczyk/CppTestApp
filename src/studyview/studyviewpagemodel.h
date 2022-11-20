#pragma once

#include <QObject>
#include <QVector>

/** Contains dataset of testing view page */
class StudyViewPageModel {
  Q_GADGET
  Q_PROPERTY(QString title MEMBER title CONSTANT)
  Q_PROPERTY(QStringList images MEMBER images CONSTANT)
  Q_PROPERTY(QStringList lessons MEMBER lessons CONSTANT)

public:
  QString title;       ///< Contains title to display
  QStringList images;   ///< Contains list of the image sources to display
  QStringList lessons; ///< Contains list of the lesson texts to display
};
Q_DECLARE_METATYPE(StudyViewPageModel)

using StudyViewPageModels = QVector<StudyViewPageModel>;
Q_DECLARE_METATYPE(StudyViewPageModels)
