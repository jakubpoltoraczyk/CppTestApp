#include "datadirectorymanager.h"

#include <QDebug>
#include <QDir>

namespace {

namespace Paths {
const QString QUIZ_DIRECTORY = QStringLiteral("%1/quiz/");
const QString QUIZ_CONFIGURATION_FILE = QStringLiteral("%1/quiz/%2/config.json");
const QString STUDY_DIRECTORY = QStringLiteral("%1/study/");
const QString STUDY_TOPIC_CONFIGURATION_FILE = QStringLiteral("%1/study/%2/config.json");
const QString DIALOG_FILE = QStringLiteral("%1/dialog/dialog%2.json");
const QString TESTING_DIRECTORY = QStringLiteral("%1/testing/");
const QString TESTING_CONFIGURATION_FILE = QStringLiteral("%1/testing/%2/config.json");
} // namespace Paths

namespace Filters {
constexpr auto DEFAULT_DIR_FILTER = QDir::Dirs | QDir::NoDotAndDotDot;
constexpr auto DEFAULT_FILE_FILTER = QDir::Files;
const QStringList QUESTION_FILTER{"question*.json"};
} // namespace Filters

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

  for (const auto& quiz : quizDirectory.entryList(Filters::DEFAULT_DIR_FILTER)) {
    quizConfigurationFilePaths.push_back(Paths::QUIZ_CONFIGURATION_FILE.arg(dataDirectoryPath, quiz));
  }

  return quizConfigurationFilePaths;
}

QStringList DataDirectoryManager::getQuizQuestionFilePaths(const QString& quiz) const {
  QStringList quizQuestionFilePaths;
  QString quizPath = Paths::QUIZ_DIRECTORY.arg(dataDirectoryPath).append(quiz);
  QDir quizDirectory(quizPath);

  for (const auto& questionFile :
       quizDirectory.entryList(Filters::QUESTION_FILTER, Filters::DEFAULT_FILE_FILTER)) {
    quizQuestionFilePaths.push_back(quizPath + "/" + questionFile);
  }

  return quizQuestionFilePaths;
}

QStringList DataDirectoryManager::getStudyTopicConfigurationFilePaths() const {
  QStringList studyTopicConfigurationFilePaths;
  QDir studyDirectory(Paths::STUDY_DIRECTORY.arg(dataDirectoryPath));

  for (const auto& studyTopic : studyDirectory.entryList(Filters::DEFAULT_DIR_FILTER)) {
    studyTopicConfigurationFilePaths.push_back(
        Paths::STUDY_TOPIC_CONFIGURATION_FILE.arg(dataDirectoryPath, studyTopic));
  }

  return studyTopicConfigurationFilePaths;
}

QString DataDirectoryManager::getDialogFilePath(int code) const {
  return Paths::DIALOG_FILE.arg(dataDirectoryPath).arg(code);
}

QStringList DataDirectoryManager::getTestingConfigurationFiles() const {
  QStringList testingConfigurationFiles;
  QDir testingDirectory(Paths::TESTING_DIRECTORY.arg(dataDirectoryPath));

  for (const auto& test : testingDirectory.entryList(Filters::DEFAULT_DIR_FILTER)) {
    testingConfigurationFiles.push_back(Paths::TESTING_CONFIGURATION_FILE.arg(dataDirectoryPath, test));
  }

  return testingConfigurationFiles;
}
