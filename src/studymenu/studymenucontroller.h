#pragma once

#include "../external/datadirectorymanager/datadirectorymanager.h"
#include "studymenupagemodel.h"

#include <QObject>

#include <memory>

/** Class which represents controller for study menu component */
class StudyMenuController : public QObject {
  Q_OBJECT
  Q_PROPERTY(StudyMenuPageModels pageModels MEMBER pageModels CONSTANT)
public:
  /**
   * @brief Create a default instance of StudyMenuController class
   * @param newDataDirectoryManager Used to manage application data directory
   * @param parent Pointer to parent widget
   */
  StudyMenuController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                      QObject* parent = nullptr);

signals:
  /** Emitted when user decided to close study menu */
  void studyMenuClosed();

  /** Emitted when user decided to select topic */
  void topicSelected(StudyMenuPageModel::Topic topic);

public slots:
  /** Called when close button has been released */
  void onCloseButtonReleased();

  /** Called when user decided to start selected topic */
  void onStartTopicButtonReleased(int topic);

private:
  std::shared_ptr<DataDirectoryManager> dataDirectoryManager;
  StudyMenuPageModels pageModels;
};
