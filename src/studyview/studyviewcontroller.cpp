#include "studyviewcontroller.h"

#include "../external/utils/utils.h"

#include <QDebug>

namespace {

namespace Json {
constexpr char TITLE[] = "title";
constexpr char IMAGE[] = "images";
constexpr char SUMMARY[] = "lessons";
} // namespace Json

StudyViewPageModels deserializeStudyViewPageModels(const QStringList& questionFilePaths) {
  StudyViewPageModels pageModels;
  pageModels.reserve(questionFilePaths.size());

  for (const auto& filePath : questionFilePaths) {
    auto jsonObject = Utils::determineJsonObject(filePath);
    StudyViewPageModel pageModel;

    pageModel.title = jsonObject[Json::TITLE].toString();
    pageModel.images = jsonObject[Json::IMAGE].toVariant().toStringList();
    pageModel.lessons = jsonObject[Json::SUMMARY].toVariant().toStringList();

    pageModels.push_back(std::move(pageModel));
  }

  return pageModels;
}

} // namespace

StudyViewController::StudyViewController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                                         std::shared_ptr<CustomDialogController> newCustomDialogController,
                                         QObject* parent)
    : QObject(parent), dataDirectoryManager(newDataDirectoryManager),
      customDialogController(newCustomDialogController),
      pageModels(deserializeStudyViewPageModels(dataDirectoryManager->getStudyContentFilePaths())) {}

void StudyViewController::onCloseButtonReleased() {
  qDebug() << __PRETTY_FUNCTION__;
  emit studyViewClosed();
}

void StudyViewController::updateLesson(StudyMenuPageModel::Topic topic) {
  switch (topic) {
  case StudyMenuPageModel::Topic::SMART_POINTERS:
    currentModel = pageModels[0];
    break;
  case StudyMenuPageModel::Topic::MOVE_SEMANTICS:
    currentModel = pageModels[1];
    break;
  case StudyMenuPageModel::Topic::STL_CONTAINERS:
    currentModel = pageModels[2];
    break;
  default:
    qDebug() << QStringLiteral("Study topic %1 has not been recognized")
                    .arg(QVariant::fromValue(topic).toString());
  }
}
