#include "datamanager.h"

namespace {

constexpr char DATA_MANAGER_FILE_SUFFIX[] = "/src/external/datamanager/datamanager.cpp";
constexpr char DATA_DIRECTORY_SUFFIX[] = "/data";

QString determineDataDirectoryPath() {
  QString path = __FILE__;
  path.replace(DATA_MANAGER_FILE_SUFFIX, DATA_DIRECTORY_SUFFIX);
  return path;
}

} // namespace

DataManager::DataManager() : dataDirectory(determineDataDirectoryPath()) {}
