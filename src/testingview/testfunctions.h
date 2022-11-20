#pragma once

#include <array>
#include <optional>
#include <string>

namespace TestUtils {

/** Struct which represents test analysis data */
struct TestAnalysis {
  std::optional<int> maxMemoryUsage; ///< Maximum memory usage within the testing function
};

/** Struct which represents basic object used for testing purposes */
struct TestObject1 {
  std::array<int, 1000> vec1;
  std::array<std::string, 1000> vec2;
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
