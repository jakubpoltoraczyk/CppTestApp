#include "studymenucontroller.h"

StudyMenuController::StudyMenuController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                                         QObject* parent)
    : QObject(parent), dataDirectoryManager(newDataDirectoryManager) {}


