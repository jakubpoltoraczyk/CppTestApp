#include "studymenucontroller.h"

#include "../external/utils/utils.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace {

namespace Json {
constexpr char TITLE[] = "title";
constexpr char TOPIC[] = "topic";
} // namespace Json

StudyMenuPageModels deserializePageModels(const QStringList& studyTopicConfigurationFilePaths) {
  StudyMenuPageModels pageModels;
  pageModels.reserve(studyTopicConfigurationFilePaths.size());

  for (const auto& filePath : studyTopicConfigurationFilePaths) {
    auto fileContent = Utils::readFileContent(filePath);
    auto jsonDocument = QJsonDocument::fromJson(fileContent);
    auto jsonObject = jsonDocument.object();

    auto title = jsonObject[Json::TITLE].toString();
    auto topic = static_cast<StudyMenuPageModel::Topic>(jsonObject[Json::TOPIC].toInt());

    StudyMenuPageModel pageModel{.title = title, .topic = topic};
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
