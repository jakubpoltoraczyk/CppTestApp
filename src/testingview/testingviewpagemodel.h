#pragma once

#include <QObject>
#include <QVector>

/** Contains dataset of testing view page */
class TestingViewPageModel {
  Q_GADGET
  Q_PROPERTY(QString testID MEMBER testID CONSTANT)
  Q_PROPERTY(QString title MEMBER title CONSTANT)
  Q_PROPERTY(QString firstImageSource MEMBER firstImageSource CONSTANT)
  Q_PROPERTY(QString secondImageSource MEMBER secondImageSource CONSTANT)
  Q_PROPERTY(QStringList pickerValues MEMBER pickerValues CONSTANT)
public:
  QString testID;            ///< Contains the test ID
  QString title;             ///< Contains the title of the testing view page
  QString firstImageSource;  ///< Contains the image source of the first code version
  QString secondImageSource; ///< Contains the image source of the second code version
  QStringList pickerValues;  ///< Contains the picker component values to display
};
Q_DECLARE_METATYPE(TestingViewPageModel)

using TestingViewPageModels = QVector<TestingViewPageModel>;
Q_DECLARE_METATYPE(TestingViewPageModels)
