#pragma once

#include <memory>
#include <vector>

namespace TestUtils {

/** Struct which represents test analysis data */
struct TestAnalysis {
  std::optional<int> maxMemoryUsage; ///< Maximum memory usage within the testing function
};

/** Struct which represents basic object used for testing purposes */
struct TestObject {
  std::vector<int> vec1 = std::vector<int>(1000);
  std::vector<std::string> vec2 = std::vector<std::string>(1000);
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

} // namespace TestUtils
