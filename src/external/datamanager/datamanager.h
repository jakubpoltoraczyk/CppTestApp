#pragma once

#include <QDir>

class DataManager {
public:
  DataManager();

private:
  QDir dataDirectory;
};
