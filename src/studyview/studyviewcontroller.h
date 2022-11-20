#pragma once

#include "../external/customdialog/customdialogcontroller.h"
#include "../external/datadirectorymanager/datadirectorymanager.h"
#include "../studymenu/studymenupagemodel.h"
#include "studyviewpagemodel.h"

#include <QObject>

class StudyViewController : public QObject {
  Q_OBJECT
  Q_PROPERTY(StudyViewPageModel currentModel MEMBER currentModel CONSTANT)
public:
  /**
   * @brief Create a default instance of StudyViewController class
   * @param newDataDirectoryManager Used to manage application data directory
   * @param newCustomDialogController Used to manage application dialogs
   * @param parent Pointer to parent widget
   */
  StudyViewController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                      std::shared_ptr<CustomDialogController> newCustomDialogController,
                      QObject* parent = nullptr);

  /**
   * @brief Update lesson content using selected topic
   * @param topic Topic of the new lesson
   */
  void updateLesson(StudyMenuPageModel::Topic topic);

signals:
  /** Emitted when user decided to close study view */
  void studyViewClosed();

public slots:
  /** Called when close button has been released */
  void onCloseButtonReleased();

private:
  std::shared_ptr<DataDirectoryManager> dataDirectoryManager;
  std::shared_ptr<CustomDialogController> customDialogController;

  StudyViewPageModels pageModels;
  StudyViewPageModel currentModel;
};
