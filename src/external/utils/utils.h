#pragma once

#include <QFile>

/** Contains general application utils */
namespace Utils {

/**
 * @brief Read content of selected file
 * @throw Throw std::logic_error when it's not possible to open selected file
 * @param filePath Path to specified file to read
 * @return Content of selected file
 */
QByteArray readFileContent(const QString& filePath);

} // namespace Utils
