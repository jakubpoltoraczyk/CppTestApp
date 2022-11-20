#include "testingviewcontroller.h"

#include "../external/utils/utils.h"

#include <QDebug>

namespace {

constexpr int REPEAT_TO_MAKE_AVERAGE = 10;
constexpr int DOUBLE_NUMBER_PRECISION = 3;
constexpr char DOUBLE_NUMBER_FORMAT = 'g';
const QString UNHANDLED_TEST = QStringLiteral("Unhandled test with the ID '%1'");
const QString TEST_FUNCTIONS_UNRECOGNIZED =
    QStringLiteral("Test functions for the test with the ID '%1' are not available");
const QString TEST_FUNCTIONS_STARTED =
    QStringLiteral("Test functions for the test with the ID '%1' will be started");

namespace CustomDialogMessage {
const QString TEST_FUNCTION_DURATION =
    QStringLiteral("Duration of the first function: %1 msec\nDuration of the second function: %2 msec");
const QString TEST_FUNCTION_MEMORY_USAGE =
    QStringLiteral("Memory used by the first function: %1[B]\nMemory used by the second function: %2[B]");
} // namespace CustomDialogMessage

namespace TestID {
constexpr char TEST_01[] = "test01";
constexpr char TEST_02[] = "test02";
constexpr char TEST_03[] = "test03";
constexpr char TEST_04[] = "test04";
} // namespace TestID

namespace Json {
constexpr char ID[] = "id";
constexpr char TITLE[] = "title";
constexpr char FIRST_IMAGE_SOURCE[] = "firstImageSource";
constexpr char SECOND_IMAGE_SOURCE[] = "secondImageSource";
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
    pageModel.firstImageSource = jsonObject[Json::FIRST_IMAGE_SOURCE].toString();
    pageModel.secondImageSource = jsonObject[Json::SECOND_IMAGE_SOURCE].toString();
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

void TestingViewController::onTestStarted(const QString& testID, int firstPickerValue,
                                          int secondPickerValue) {
  if (testFunctions.find(testID.toStdString()) == testFunctions.end()) {
    qDebug() << TEST_FUNCTIONS_UNRECOGNIZED.arg(testID);
    return;
  }

  qDebug() << TEST_FUNCTIONS_STARTED.arg(testID);
  const auto& functions = testFunctions.at(testID.toStdString());
  const auto& firstFunction = functions.first;
  const auto& secondFunction = functions.second;

  auto firstDuration =
      getAveragedTestFunctionDurationMilliseconds(firstFunction, firstPickerValue, REPEAT_TO_MAKE_AVERAGE);
  auto firstDurationText = QString::number(firstDuration, DOUBLE_NUMBER_FORMAT, DOUBLE_NUMBER_PRECISION);
  auto secondDuration =
      getAveragedTestFunctionDurationMilliseconds(secondFunction, secondPickerValue, REPEAT_TO_MAKE_AVERAGE);
  auto secondDurationText = QString::number(secondDuration, DOUBLE_NUMBER_FORMAT, DOUBLE_NUMBER_PRECISION);

  customDialogController->showDialog(
      CustomDialogMessage::TEST_FUNCTION_DURATION.arg(firstDurationText, secondDurationText), true, false);
  Utils::connectOnDialogClosed(
      customDialogController, [this, &firstFunction, &secondFunction, firstPickerValue,
                               secondPickerValue](CustomDialogController::ExitStatus) {
        displayAdditionalInformation(firstFunction, secondFunction, firstPickerValue, secondPickerValue);
      });
}

void TestingViewController::initializeTestFunctions() {
  using namespace TestUtils;
  for (const auto& pageModel : pageModels) {
    const auto& testID = pageModel.testID;
    if (testID == TestID::TEST_01) {
      testFunctions[testID.toStdString()] = std::make_pair(Test01::firstVersion, Test01::secondVersion);
    } else if (testID == TestID::TEST_02) {
      testFunctions[testID.toStdString()] = std::make_pair(Test02::firstVersion, Test02::secondVersion);
    } else if (testID == TestID::TEST_03) {
      testFunctions[testID.toStdString()] = std::make_pair(Test03::firstVersion, Test03::secondVersion);
    } else if (testID == TestID::TEST_04) {
      testFunctions[testID.toStdString()] = std::make_pair(Test04::firstVersion, Test04::secondVersion);
    } else {
      qDebug() << UNHANDLED_TEST.arg(testID);
    }
  }
}

double TestingViewController::getTestFunctionDurationMilliseconds(
    const std::function<TestUtils::TestAnalysis(int)>& testFunction, int sizeParameter) {
  auto startTime = std::chrono::high_resolution_clock::now();
  testFunction(sizeParameter);
  auto endTime = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duration = endTime - startTime;
  return duration.count();
}

double TestingViewController::getAveragedTestFunctionDurationMilliseconds(
    const std::function<TestUtils::TestAnalysis(int)>& testFunction, int sizeParameter,
    int averagePrecision) {
  double duration{};
  for (int i = 0; i < averagePrecision; ++i) {
    duration += getTestFunctionDurationMilliseconds(testFunction, sizeParameter);
  }
  return duration / averagePrecision;
}

void TestingViewController::displayAdditionalInformation(
    const std::function<TestUtils::TestAnalysis(int)>& firstFunction,
    const std::function<TestUtils::TestAnalysis(int)>& secondFunction, int firstPickerValue,
    int secondPickerValue) {
  auto firstMemoryUsage = firstFunction(firstPickerValue).maxMemoryUsage;
  auto secondMemoryUsage = secondFunction(secondPickerValue).maxMemoryUsage;

  if (!firstMemoryUsage.has_value() || !secondMemoryUsage.has_value()) {
    return;
  }

  customDialogController->showDialog(
      CustomDialogMessage::TEST_FUNCTION_MEMORY_USAGE.arg(QString::number(firstMemoryUsage.value()),
                                                          QString::number(secondMemoryUsage.value())),
      true, false);
}
