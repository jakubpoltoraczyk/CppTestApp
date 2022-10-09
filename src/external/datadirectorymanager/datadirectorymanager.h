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
   * @brief Provide a list of specified quiz question file paths
   * @param quiz Name of quiz which questions are wanted
   * @return List of quiz question file paths
   */
  QStringList getQuizQuestionFilePaths(const QString& quiz) const;

  /**
   * @brief Provide a list of study topic configuration file paths
   * @return List of study topic configuration file paths
   */
  QStringList getStudyTopicConfigurationFilePaths() const;

  /**
   * @brief Provide path to dialog with selected code
   * @param code Code of the dialog which path will be returned
   * @return Path to selected dialog
   */
  QString getDialogFilePath(int code) const;

private:
  QString dataDirectoryPath;
};
