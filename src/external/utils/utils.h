#pragma once

#include "../customdialog/customdialogcontroller.h"

#include <QFile>
#include <QJsonObject>
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
 * @brief Determine JSON object from file with selected path
 * @param filePath Path to file which will be used to determine JSON object
 * @return JSON object created from specified file
 */
QJsonObject determineJsonObject(const QString& filePath);

/**
 * @brief Convert enum to its string representation
 * @details Enum must be known to Qt's meta-object system (using e.g. Q_ENUM macro)
 * @param qenum Enum which will be converted
 * @return String representation of enum
 */
template <typename QEnum> QString qenumToString(QEnum qenum) { return QVariant::fromValue(qenum).toString(); }

/**
 * @brief Used to make single shot connection for @see CustomDialogController::dialogClosed signal
 * @details It's just a very basic version of Qt::SingleShotConnection available from Qt 6.0
 * @param customDialogController Contains controller for custom dialog component
 * @param slotOnDialogClosed It will be called as a slot for @see CustomDialogController:dialogClosed signal
 */
void connectOnDialogClosed(std::shared_ptr<CustomDialogController> customDialogController,
                           std::function<void(CustomDialogController::ExitStatus)> slotOnDialogClosed);

} // namespace Utils
