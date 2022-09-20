#pragma once

#include "entryview/entryviewcontroller.h"

#include <QObject>

#include <vector>

/** Class which represents application basic controller */
class BasicController : public QObject {
  Q_OBJECT
  Q_PROPERTY(bool entryViewVisibility MEMBER entryViewVisibility CONSTANT NOTIFY entryViewVisibilityChanged)
public:
  /**
   * @brief Create an instance of BasicController class
   * @param parent Pointer to parent widget
   */
  BasicController(QObject* parent = nullptr);

  /**
   * @brief Provide objects to register in QML part of application
   * @return Container of pairs (object's name and pointer to its instance) to register
   */
  std::vector<std::pair<QString, QObject*>> getObjectsToRegister();

signals:
  /** Emitted when entry view visibility has been changed */
  void entryViewVisibilityChanged();

public slots:
  /**
   * @brief Called when entry view page has been selected
   * @param pageType Type of page which has been selected
   */
  void onEntryViewPageSelected(EntryViewController::PageType pageType);

private:
  bool entryViewVisibility;

  EntryViewController entryViewController;
};
