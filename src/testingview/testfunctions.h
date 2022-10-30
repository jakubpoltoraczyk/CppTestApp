#pragma once

#include <memory>
#include <vector>

namespace TestUtils {

/** Struct which represents basic object used for testing purposes */
struct TestObject {
  std::vector<int> vec1 = std::vector<int>(1000);
  std::vector<std::string> vec2 = std::vector<std::string>(1000);
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

/** Test functions for the test with the ID 'test03' */
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

/** Test functions for the test with the ID 'test04' */
namespace Test04 {
void firstVersion(int size) {
  std::vector<TestObject> objects(size);

  std::vector<int> vec;
  vec.reserve(objects.size());

  std::transform(objects.begin(), objects.end(), std::back_inserter(vec),
                 [](const auto& object) { return object.vec1.size() + object.vec2.size(); });
}

void secondVersion(int size) {
  std::vector<TestObject> objects(size);

  std::vector<int> vec;
  vec.reserve(objects.size());

  for (std::size_t i = 0; i < objects.size(); ++i) {
    const auto& object = objects[i];
    vec.emplace_back(object.vec1.size() + object.vec2.size());
  }
}
} // namespace Test04

} // namespace TestUtils
