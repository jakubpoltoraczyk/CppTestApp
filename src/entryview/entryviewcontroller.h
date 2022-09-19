#pragma once

#include <QObject>

/** Class which represents entry view controller */
class EntryViewController : public QObject {
  Q_OBJECT
public:
  /** List of available entry view page types */
  enum class PageType { UNDEFINED = -1, STUDY, QUIZ };
  Q_ENUM(PageType)

  using QObject::QObject;

signals:
  /**
   * @brief Emitted when page has been selected
   * @param pageType Type of selected page
   */
  void pageSelected(EntryViewController::PageType pageType);

public slots:
  /**
   * @brief Called when start button has been released
   * @param pageType Type of page which contains released button
   */
  void onStartButtonReleased(EntryViewController::PageType pageType);
};
