#pragma once

#include "../external/customdialog/customdialogcontroller.h"
#include "../external/datadirectorymanager/datadirectorymanager.h"
#include "testingviewpagemodel.h"

#include <QObject>

#include <memory>

class TestingViewController : public QObject {
  Q_OBJECT
  Q_PROPERTY(TestingViewPageModels pageModels MEMBER pageModels CONSTANT)
public:
  /**
   * @brief Create a default instance of TestingViewController class
   * @param newDataDirectoryManager Used to manage application data directory
   * @param newCustomDialogController Used to manage application dialogs
   * @param parent Pointer to parent widget
   */
  TestingViewController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                        std::shared_ptr<CustomDialogController> newCustomDialogController,
                        QObject* parent = nullptr);

signals:
  /** Emitted when user decided to close testing view */
  void testingViewClosed();

public slots:
  /** Called when close button has been released */
  void onCloseButtonReleased();

  /** Called when user just decided to start the selected test */
  void onTestStarted(int obsoletePickerValue, int modernPickerValue);

private:
  std::shared_ptr<DataDirectoryManager> dataDirectoryManager;
  std::shared_ptr<CustomDialogController> customDialogController;

  TestingViewPageModels pageModels;
};
