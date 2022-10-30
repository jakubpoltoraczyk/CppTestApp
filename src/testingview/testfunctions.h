#pragma once

#include <memory>
#include <vector>

namespace TestUtils {

/** Class which represents basic object used for testing purposes */
class TestObject {
public:
  TestObject() : vec1(1000), vec2(1000) {}

private:
  std::vector<int> vec1;
  std::vector<std::string> vec2;
};

/** Test functions for the test with the ID 'test01' */
namespace Test01 {
void firstVersion(int size) {
  std::vector<TestObject*> ptrs(size);

  // Memory allocation
  for (auto& ptr : ptrs) {
    ptr = new TestObject;
  }

  // Memory deallocation
  for (auto& ptr : ptrs) {
    delete ptr;
  }
}

void secondVersion(int size) {
  std::vector<std::unique_ptr<TestObject>> ptrs(size);

  // Memory allocation
  for (auto& ptr : ptrs) {
    ptr = std::make_unique<TestObject>();
  }

  // No need to manually deallocate memory
}
} // namespace Test01

/** Test functions for the test with the ID 'test02' */
namespace Test02 {
void firstVersion(int size) {
  std::vector<std::unique_ptr<TestObject>> ptrs(size);

  // Memory allocation
  for (auto& ptr : ptrs) {
    ptr = std::make_unique<TestObject>();
  }
}

void secondVersion(int size) {
  std::vector<std::shared_ptr<TestObject>> ptrs(size);

  // Memory allocation
  for (auto& ptr : ptrs) {
    ptr = std::make_shared<TestObject>();
  }
}
} // namespace Test02

namespace Test03 {
void firstVersion(int size) {
  std::vector<TestObject> objects;
  objects.reserve(size);

  for (int i = 0; i < size; ++i) {
    TestObject object;
    objects.emplace_back(object);
  }
}

void secondVersion(int size) {
  std::vector<TestObject> objects;
  objects.reserve(size);

  for (int i = 0; i < size; ++i) {
    TestObject object;
    objects.emplace_back(std::move(object));
  }
}
} // namespace Test03

} // namespace TestUtils
