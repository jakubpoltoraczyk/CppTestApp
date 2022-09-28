#include "datadirectorymanager.h"

#include <QDebug>
#include <QDir>

namespace {

namespace Paths {
const QString QUIZ_DIRECTORY = QStringLiteral("%1/quiz");
const QString STUDY_DIRECTORY = QStringLiteral("%1/study");
const QString QUIZ_CONFIGURATION_FILE = QStringLiteral("%1/quiz/%2/config.json");
const QString STUDY_TOPIC_CONFIGURATION_FILE = QStringLiteral("%1/study/%2/config.json");
} // namespace Paths

QString determineDataDirectoryPath() {
  QString path = __FILE__;
  path.replace(QStringLiteral("/src/external/datadirectorymanager/datadirectorymanager.cpp"),
               QStringLiteral("/data"));
  return path;
}

} // namespace

DataDirectoryManager::DataDirectoryManager() : dataDirectoryPath(determineDataDirectoryPath()) {}

QStringList DataDirectoryManager::getQuizConfigurationFilePaths() const {
  QStringList quizConfigurationFilePaths;
  QDir quizDirectory(Paths::QUIZ_DIRECTORY.arg(dataDirectoryPath));

  for (const auto& quiz : quizDirectory.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
    quizConfigurationFilePaths.push_back(Paths::QUIZ_CONFIGURATION_FILE.arg(dataDirectoryPath, quiz));
  }

  return quizConfigurationFilePaths;
}

QStringList DataDirectoryManager::getStudyTopicConfigurationFilePaths() const {
  QStringList studyTopicConfigurationFilePaths;
  QDir studyDirectory(Paths::STUDY_DIRECTORY.arg(dataDirectoryPath));

  for (const auto& studyTopic : studyDirectory.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
    studyTopicConfigurationFilePaths.push_back(
        Paths::STUDY_TOPIC_CONFIGURATION_FILE.arg(dataDirectoryPath, studyTopic));
  }

  return studyTopicConfigurationFilePaths;
}
