#include "testfunctions.h"

#include <vector>
#include <memory>

namespace {
using namespace TestUtils;
}

TestAnalysis Test01::firstVersion(int size) {
  TestAnalysis analysis;
  std::vector<TestObject1*> ptrs(size);

  // Memory allocation
  for (auto& ptr : ptrs) {
    ptr = new TestObject1;
  }

  analysis.maxMemoryUsage = size * (sizeof(TestObject1*) + sizeof(TestObject1));

  // Memory deallocation
  for (auto& ptr : ptrs) {
    delete ptr;
  }

  return analysis;
}

TestAnalysis Test01::secondVersion(int size) {
  TestAnalysis analysis;
  std::vector<std::unique_ptr<TestObject1>> ptrs(size);

  // Memory allocation
  for (auto& ptr : ptrs) {
    ptr = std::make_unique<TestObject1>();
  }

  analysis.maxMemoryUsage = size * (sizeof(std::unique_ptr<TestObject1>) + sizeof(TestObject1));

  // No need to manually deallocate memory

  return analysis;
}

TestAnalysis Test02::firstVersion(int size) {
  TestAnalysis analysis;
  std::vector<std::unique_ptr<TestObject1>> ptrs(size);

  // Memory allocation
  for (auto& ptr : ptrs) {
    ptr = std::make_unique<TestObject1>();
  }

  analysis.maxMemoryUsage = size * (sizeof(std::unique_ptr<TestObject1>) + sizeof(TestObject1));

  return analysis;
}

TestAnalysis Test02::secondVersion(int size) {
  TestAnalysis analysis;
  std::vector<std::shared_ptr<TestObject1>> ptrs(size);

  // Memory allocation
  for (auto& ptr : ptrs) {
    ptr = std::make_shared<TestObject1>();
  }

  analysis.maxMemoryUsage = size * (sizeof(std::shared_ptr<TestObject1>) + sizeof(TestObject1));

  return analysis;
}

TestAnalysis Test03::firstVersion(int size) {
  std::vector<TestObject1> objects;
  objects.reserve(size);

  for (int i = 0; i < size; ++i) {
    TestObject1 object;
    objects.emplace_back(object);
  }

  return {};
}

TestAnalysis Test03::secondVersion(int size) {
  std::vector<TestObject1> objects;
  objects.reserve(size);

  for (int i = 0; i < size; ++i) {
    TestObject1 object;
    objects.emplace_back(std::move(object));
  }

  return {};
}

TestAnalysis Test04::firstVersion(int size) {
  std::vector<TestObject1> objects(size);

  std::vector<int> vec;
  vec.reserve(objects.size());

  std::transform(objects.begin(), objects.end(), std::back_inserter(vec),
                 [](const auto& object) { return object.vec1.size() + object.vec2.size(); });

  return {};
}

TestAnalysis Test04::secondVersion(int size) {
  std::vector<TestObject1> objects(size);

  std::vector<int> vec;
  vec.reserve(objects.size());

  for (std::size_t i = 0; i < objects.size(); ++i) {
    const auto& object = objects[i];
    vec.emplace_back(object.vec1.size() + object.vec2.size());
  }

  return {};
}
