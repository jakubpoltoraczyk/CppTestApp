#pragma once

#include "../datadirectorymanager/datadirectorymanager.h"

#include <QObject>

#include <memory>

/** Class which represents custom dialog controller */
class CustomDialogController : public QObject {
  Q_OBJECT
  Q_PROPERTY(bool isVisible MEMBER isVisible NOTIFY visibilityChanged)
public:
  /** Contains available custom dialog exit statuses */
  enum class ExitStatus { ACCEPTED, REJECTED };

  /**
   * @brief Create new instance of CustomDialogController class
   * @param newDataDirectoryManager Used to manage data directories and files
   * @param parent Pointer to parent widget
   */
  CustomDialogController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                         QObject* parent = nullptr);

  /** Show custom dialog component */
  void showDialog();

signals:
  /** Called when dialog visiblity should be changed */
  void visibilityChanged();

  /**
   * @brief Emitted when custom dialog has been closed
   * @param exitStatus Exit status of just closed dialog
   */
  void dialogClosed(CustomDialogController::ExitStatus exitStatus);

public slots:
  /** Called when pressed custom dialog accepted button */
  void onAccepted();

  /** Called when user custom dialog rejected button */
  void onRejected();

private:
  /**
   * @brief Change current dialog visibility status
   * @param newVisibility New visibility status
   */
  void changeVisibility(bool newVisibility);

  bool isVisible = false; ///< Contains information about dialog visiblity

  std::shared_ptr<DataDirectoryManager> dataDirectoryManager;
};
