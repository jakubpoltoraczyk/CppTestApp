#pragma once

#include <QFile>
#include <QVariant>

/** Contains general application utils */
namespace Utils {

/**
 * @brief Read content of selected file
 * @throw Throw std::logic_error when it's not possible to open selected file
 * @param filePath Path to specified file to read
 * @return Content of selected file
 */
QByteArray readFileContent(const QString& filePath);

/**
 * @brief Convert enum to its string representation
 * @details Enum must be known to Qt's meta-object system (using e.g. Q_ENUM macro)
 * @param qenum Enum which will be converted
 * @return String representation of enum
 */
template <typename QEnum> QString qenumToString(QEnum qenum) { return QVariant::fromValue(qenum).toString(); }

} // namespace Utils
