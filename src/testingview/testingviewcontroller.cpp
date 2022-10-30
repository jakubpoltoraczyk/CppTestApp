#include "testingviewcontroller.h"

#include "../external/utils/utils.h"
#include "tests/test01.h"

#include <QDebug>

namespace {

constexpr char DOUBLE_NUMBER_FORMAT = 'g';
constexpr int DOUBLE_NUMBER_PRECISION = 3;
const QString UNHANDLED_TEST = QStringLiteral("Unhandled test with the ID '%1'");
const QString TEST_FUNCTIONS_UNRECOGNIZED =
    QStringLiteral("Test functions for the test with the ID '%1' are not available");
const QString TEST_FUNCTIONS_STARTED =
    QStringLiteral("Test functions for the test with the ID '%1' will be started");

namespace TestID {
constexpr char TEST_01[] = "test01";
}

namespace Json {
constexpr char ID[] = "id";
constexpr char TITLE[] = "title";
constexpr char OBSOLETE_IMAGE_SOURCE[] = "obsoleteImageSource";
constexpr char MODERN_IMAGE_SOURCE[] = "modernImageSource";
constexpr char PICKER_VALUES[] = "pickerValues";
} // namespace Json

TestingViewPageModels deserializePageModels(const QStringList& testingConfigFiles) {
  TestingViewPageModels pageModels;
  pageModels.reserve(testingConfigFiles.size());

  for (const auto& filePath : testingConfigFiles) {
    auto jsonObject = Utils::determineJsonObject(filePath);
    TestingViewPageModel pageModel;

    pageModel.testID = jsonObject[Json::ID].toString();
    pageModel.title = jsonObject[Json::TITLE].toString();
    pageModel.obsoleteImageSource = jsonObject[Json::OBSOLETE_IMAGE_SOURCE].toString();
    pageModel.modernImageSource = jsonObject[Json::MODERN_IMAGE_SOURCE].toString();
    pageModel.pickerValues = jsonObject[Json::PICKER_VALUES].toVariant().toStringList();

    pageModels.push_back(std::move(pageModel));
  }

  return pageModels;
}

} // namespace

TestingViewController::TestingViewController(
    std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
    std::shared_ptr<CustomDialogController> newCustomDialogController, QObject* parent)
    : QObject(parent), dataDirectoryManager(newDataDirectoryManager),
      customDialogController(newCustomDialogController),
      pageModels(deserializePageModels(dataDirectoryManager->getTestingConfigurationFiles())) {
  initializeTestFunctions();
}

void TestingViewController::onCloseButtonReleased() {
  qDebug() << __PRETTY_FUNCTION__;
  emit testingViewClosed();
}

void TestingViewController::onTestStarted(const QString& testID, int obsoletePickerValue,
                                          int modernPickerValue) {
  if (testFunctions.find(testID.toStdString()) == testFunctions.end()) {
    qDebug() << TEST_FUNCTIONS_UNRECOGNIZED.arg(testID);
    return;
  }

  qDebug() << TEST_FUNCTIONS_STARTED.arg(testID);
  const auto& [obsoleteFunction, modernFunction] = testFunctions.at(testID.toStdString());

  QString obsoleteDuration =
      QString::number(getTestFunctionDurationMilliseconds(obsoleteFunction, obsoletePickerValue),
                      DOUBLE_NUMBER_FORMAT, DOUBLE_NUMBER_PRECISION);
  QString modernDuration =
      QString::number(getTestFunctionDurationMilliseconds(modernFunction, modernPickerValue),
                      DOUBLE_NUMBER_FORMAT, DOUBLE_NUMBER_PRECISION);
  qDebug() << "Obsolete function duration:" << obsoleteDuration;
  qDebug() << "Modern function duration:" << modernDuration;
}

double
TestingViewController::getTestFunctionDurationMilliseconds(const std::function<void(int)>& testFunction,
                                                           int sizeParameter) {
  auto startTime = std::chrono::high_resolution_clock::now();
  testFunction(sizeParameter);
  auto endTime = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duration = endTime - startTime;
  return duration.count();
}

void TestingViewController::initializeTestFunctions() {
  for (const auto& pageModel : pageModels) {
    const auto& testID = pageModel.testID;
    if (testID == TestID::TEST_01) {
      testFunctions[testID.toStdString()] = std::make_pair(Test01::obsoleteVersion, Test01::modernVersion);
    } else {
      qDebug() << UNHANDLED_TEST.arg(testID);
    }
  }
}
