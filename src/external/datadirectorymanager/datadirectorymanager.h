#pragma once

#include <QStringList>

/** Class which enable to manage application data directory */
class DataDirectoryManager {
public:
  /** Create default instance of DataDirectoryManager class */
  DataDirectoryManager();

  /**
   * @brief Provide a list of quiz configuration file paths
   * @return List of quiz configuration file paths
   */
  QStringList getQuizConfigurationFilePaths() const;

  /**
   * @brief Provide a list of study topic configuration file paths
   * @return List of study topic configuration file paths
   */
  QStringList getStudyTopicConfigurationFilePaths() const;

private:
  QString dataDirectoryPath;
};
