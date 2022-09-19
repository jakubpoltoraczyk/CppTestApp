#pragma once

#include "entryview/entryviewcontroller.h"

#include <QObject>

#include <vector>

class BasicController : public QObject {
  Q_OBJECT
public:
  using QObject::QObject;

  /**
   * @brief Provide objects to register in QML part of application
   * @return Container of pairs (object's name and pointer to its instance) to register
   */
  std::vector<std::pair<QString, QObject*>> getObjectsToRegister();

private:
  EntryViewController entryViewController;
};
