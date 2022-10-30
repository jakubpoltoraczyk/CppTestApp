#include "testingviewcontroller.h"

#include "../external/utils/utils.h"

#include <QDebug>

namespace {

namespace Json {
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
      pageModels(deserializePageModels(dataDirectoryManager->getTestingConfigurationFiles())) {}

void TestingViewController::onCloseButtonReleased() {
  qDebug() << __PRETTY_FUNCTION__;
  emit testingViewClosed();
}

void TestingViewController::onTestStarted(int obsoletePickerValue, int modernPickerValue) {
  qDebug() << "Obsolete:" << obsoletePickerValue << ", modern:" << modernPickerValue;
}
