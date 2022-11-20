#include "testfunctions.h"

#include <map>
#include <memory>
#include <numeric>

namespace {

using namespace TestUtils;

int accumulateCopyOperationCalls(int accumulator, const TestObject2& object) {
  return accumulator + object.copyCounter;
}

int accumulateMoveOperationCalls(int accumulator, const TestObject2& object) {
  return accumulator + object.moveCounter;
}

} // namespace

TestObject2::TestObject2(const TestObject2& other) : vec1(other.vec1), vec2(other.vec2) { ++copyCounter; }

TestObject2::TestObject2(TestObject2&& other) : vec1(std::move(other.vec1)), vec2(std::move(other.vec2)) {
  ++moveCounter;
}

TestObject2& TestObject2::operator=(const TestObject2& other) {
  vec1 = other.vec1;
  vec2 = other.vec2;
  ++copyCounter;
  return *this;
}

TestObject2& TestObject2::operator=(TestObject2&& other) {
  vec1 = std::move(other.vec1);
  vec2 = std::move(other.vec2);
  ++moveCounter;
  return *this;
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
  TestAnalysis analysis;
  std::vector<TestObject2> objects;
  objects.reserve(size);

  for (int i = 0; i < size; ++i) {
    TestObject2 object;
    objects.emplace_back(object);
  }

  analysis.copyOperationCalls =
      std::accumulate(objects.begin(), objects.end(), 0, accumulateCopyOperationCalls);
  analysis.moveOperationCalls =
      std::accumulate(objects.begin(), objects.end(), 0, accumulateMoveOperationCalls);

  return analysis;
}

TestAnalysis Test03::secondVersion(int size) {
  TestAnalysis analysis;
  std::vector<TestObject2> objects;
  objects.reserve(size);

  for (int i = 0; i < size; ++i) {
    TestObject2 object;
    objects.emplace_back(std::move(object));
  }

  analysis.copyOperationCalls =
      std::accumulate(objects.begin(), objects.end(), 0, accumulateCopyOperationCalls);
  analysis.moveOperationCalls =
      std::accumulate(objects.begin(), objects.end(), 0, accumulateMoveOperationCalls);

  return analysis;
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

TestAnalysis Test05::firstVersion(int size) {
  TestAnalysis analysis;
  std::vector<TestObject1> objects(size);

  std::fill(objects.begin(), objects.end(), TestObject1());
  analysis.maxMemoryUsage = size * sizeof(TestObject1);

  return analysis;
}

TestAnalysis Test05::secondVersion(int size) {
  TestAnalysis analysis;
  auto objects = new TestObject1[size];

  std::fill(objects, std::next(objects, size), TestObject1());
  analysis.maxMemoryUsage = size * sizeof(TestObject1);

  delete[] objects;
  return analysis;
}

using Object = std::vector<int>;
using Array = std::vector<Object>;
Array jsonObjects;

void processObject(const Object&) {}

Array getRawObjects() { return Array(); }




void foo() {
  Object obj1;
  const Object obj2;
  obj1 = std::move(obj2);
}


