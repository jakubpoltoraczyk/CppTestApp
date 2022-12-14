#pragma once

#include "../external/customdialog/customdialogcontroller.h"
#include "../external/datadirectorymanager/datadirectorymanager.h"
#include "testfunctions.h"
#include "testingviewpagemodel.h"

#include <QObject>

#include <chrono>
#include <memory>
#include <unordered_map>

class TestingViewController : public QObject {
  Q_OBJECT
  Q_PROPERTY(TestingViewPageModels pageModels MEMBER pageModels CONSTANT)
public:
  /**
   * @brief Create a default instance of TestingViewController class
   * @param newDataDirectoryManager Used to manage application data directory
   * @param newCustomDialogController Used to manage application dialogs
   * @param parent Pointer to parent widget
   */
  TestingViewController(std::shared_ptr<DataDirectoryManager> newDataDirectoryManager,
                        std::shared_ptr<CustomDialogController> newCustomDialogController,
                        QObject* parent = nullptr);

signals:
  /** Emitted when user decided to close testing view */
  void testingViewClosed();

public slots:
  /** Called when close button has been released */
  void onCloseButtonReleased();

  /**
   * @brief Called when user just decided to start the currently selected test
   * @param testID ID of the selected test
   * @param firstPickerValue Value of the picker component for the first test version
   * @param secondPickerValue Value of the picker component for the second test version
   */
  void onTestStarted(const QString& testID, int firstPickerValue, int secondPickerValue);

private:
  /** Initialize the @see testFunctions class member */
  void initializeTestFunctions();

  /**
   * @brief Provide duration of the test function in milliseconds
   * @param testFunction Test function to call
   * @param sizeParameter Size parameter which will be passed to the test function as an argument
   * @return Duration of the test function call in milliseconds
   */
  double getTestFunctionDurationMilliseconds(const std::function<TestUtils::TestAnalysis(int)>& testFunction,
                                             int sizeParameter);

  /**
   * @brief Provide averaged duration of the test function in milliseconds
   * @param testFunction Test function to call
   * @param sizeParameter Size parameter which will be passed to the test function as an argument
   * @param averagePrecision Value of the average precision
   * @return Averaged duration of the test function call in milliseconds
   */
  double
  getAveragedTestFunctionDurationMilliseconds(const std::function<TestUtils::TestAnalysis(int)>& testFunction,
                                              int sizeParameter, int averagePrecision);

  /**
   * @brief Display additional information about the testing function using custom dialog component
   * @param firstFunction First test function to call
   * @param secondFunction Second test function to call
   * @param firstPickerValue Value of the picker component for the first test version
   * @param secondPickerValue Value of the picker component for the second test version
   */
  void displayAdditionalInformation(const std::function<TestUtils::TestAnalysis(int)>& firstFunction,
                                    const std::function<TestUtils::TestAnalysis(int)>& secondFunction,
                                    int firstPickerValue, int secondPickerValue);

  std::shared_ptr<DataDirectoryManager> dataDirectoryManager;
  std::shared_ptr<CustomDialogController> customDialogController;

  std::unordered_map<std::string, std::pair<std::function<TestUtils::TestAnalysis(int)>,
                                            std::function<TestUtils::TestAnalysis(int)>>>
      testFunctions;

  TestingViewPageModels pageModels;
};
