#include "utils.h"

namespace {

const QString OPEN_FILE_NOT_POSSIBLE = QStringLiteral("Couldn't open file with path: %1");

} // namespace

QByteArray Utils::readFileContent(const QString& filePath) {
  QFile file(filePath);
  if (!file.open(QIODevice::ReadOnly)) {
    throw std::logic_error(OPEN_FILE_NOT_POSSIBLE.arg(filePath).toStdString());
  }
  auto fileContent = file.readAll();
  file.close();
  return fileContent;
}
