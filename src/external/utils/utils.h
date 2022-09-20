#pragma once

#include <QMetaEnum>
#include <QString>

/** Contains general utils used in whole project */
namespace Utils {

/**
 * @brief Provide string representation of selected enum type
 * @details Enum type must be declared with Q_ENUM macro
 * @param enumType Type of enum to convert
 * @return String representation of selected enum type
 */
template <typename EnumType> QString convertEnumToString(EnumType enumType) {
  auto metaEnum = QMetaEnum::fromType<EnumType>();
  return metaEnum.valueToKey(static_cast<int>(enumType));
}

} // namespace Utils
