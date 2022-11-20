#pragma once

#include <array>
#include <optional>
#include <string>
#include <vector>

namespace TestUtils {

/** Struct which represents test analysis data */
struct TestAnalysis {
  std::optional<int> maxMemoryUsage;     ///< Maximum memory usage within the testing function
  std::optional<int> copyOperationCalls; ///< Number of copy operation calls
  std::optional<int> moveOperationCalls; ///< Number of move operation calls
};

/** Struct which represents basic object no. 1 used for testing purposes */
struct TestObject1 {
  std::array<int, 1000> vec1;
  std::array<std::string, 1000> vec2;
};

/** Struct which represents basic object no. 2 used for testing purposes */
struct TestObject2 {
  TestObject2() = default;
  TestObject2(const TestObject2& other);
  TestObject2(TestObject2&& other);
  TestObject2& operator=(const TestObject2& other);
  TestObject2& operator=(TestObject2&& other);

  std::vector<int> vec1 = std::vector<int>(1000);
  std::vector<std::string> vec2 = std::vector<std::string>(1000);
  int moveCounter = 0;
  int copyCounter = 0;
};

/** Test functions for the test with the ID 'test01' */
namespace Test01 {
TestAnalysis firstVersion(int size);
TestAnalysis secondVersion(int size);
} // namespace Test01

/** Test functions for the test with the ID 'test02' */
namespace Test02 {
TestAnalysis firstVersion(int size);
TestAnalysis secondVersion(int size);
} // namespace Test02

/** Test functions for the test with the ID 'test03' */
namespace Test03 {
TestAnalysis firstVersion(int size);
TestAnalysis secondVersion(int size);
} // namespace Test03

/** Test functions for the test with the ID 'test04' */
namespace Test04 {
TestAnalysis firstVersion(int size);
TestAnalysis secondVersion(int size);
} // namespace Test04

/** Test functions for the test with the ID 'test05' */
namespace Test05 {
TestAnalysis firstVersion(int size);
TestAnalysis secondVersion(int size);
} // namespace Test05

} // namespace TestUtils
