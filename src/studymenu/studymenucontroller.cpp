#include "studymenucontroller.h"

#include "../external/utils/utils.h"

namespace {

namespace Json {
constexpr char TITLE[] = "title";
constexpr char TOPIC[] = "topic";
} // namespace Json

StudyMenuPageModels deserializePageModels(const QStringList& studyTopicConfigurationFilePaths) {
  StudyMenuPageModels pageModels;
  pageModels.reserve(studyTopicConfigurationFilePaths.size());

  for (const auto& filePath : studyTopicConfigurationFilePaths) {
    auto jsonObject = Utils::determineJsonObject(filePath);
    StudyMenuPageModel pageModel;

    pageModel.title = jsonObject[Json::TITLE].toString();
    pageModel.topic = static_cast<StudyMenuPageModel::Topic>(jsonObject[Json::TOPIC].toInt());

    pageModels.push_back(std::move(pageModel));
  }

  return pageModels;
}

} // namespace

StudyMenuController::StudyMenuController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                                         QObject* parent)
    : QObject(parent), dataDirectoryManager(newDataDirectoryManager),
      pageModels(deserializePageModels(dataDirectoryManager->getStudyTopicConfigurationFilePaths())) {}

void StudyMenuController::onCloseButtonReleased() {
  qDebug() << __PRETTY_FUNCTION__;
  emit studyMenuClosed();
}

void StudyMenuController::onStartTopicButtonReleased(int topic) {
  qDebug() << __PRETTY_FUNCTION__;
  emit topicSelected(static_cast<StudyMenuPageModel::Topic>(topic));
}
