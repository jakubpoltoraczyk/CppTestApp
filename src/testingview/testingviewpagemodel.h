#pragma once

#include <QObject>
#include <QVector>

/** Contains dataset of testing view page */
class TestingViewPageModel {
  Q_GADGET
  Q_PROPERTY(QString testID MEMBER testID CONSTANT)
  Q_PROPERTY(QString title MEMBER title CONSTANT)
  Q_PROPERTY(QString obsoleteImageSource MEMBER obsoleteImageSource CONSTANT)
  Q_PROPERTY(QString modernImageSource MEMBER modernImageSource CONSTANT)
  Q_PROPERTY(QStringList pickerValues MEMBER pickerValues CONSTANT)
public:
  QString testID;              ///< Contains the test ID
  QString title;               ///< Contains the title of the testing view page
  QString obsoleteImageSource; ///< Contains the image source of the obsolete code version
  QString modernImageSource;   ///< Contains the image source of the modern code version
  QStringList pickerValues;    ///< Contains the picker component values to display
};
Q_DECLARE_METATYPE(TestingViewPageModel)

using TestingViewPageModels = QVector<TestingViewPageModel>;
Q_DECLARE_METATYPE(TestingViewPageModels)
