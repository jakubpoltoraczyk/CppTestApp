#include "basiccontroller.h"

std::vector<std::pair<QString, QObject *>> BasicController::getObjectsToRegister() {
  return {{QStringLiteral("basicController"), this}};
}
