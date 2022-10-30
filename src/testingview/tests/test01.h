#pragma once

#include <memory>
#include <vector>

namespace Test01 {

void firstVersion(int size) {
  std::vector<int*> ptrs(size);

  // Memory allocation
  for (auto& ptr : ptrs) {
    ptr = new int;
  }

  // Memory deallocation
  for (auto& ptr : ptrs) {
    delete ptr;
  }
}

void secondVersion(int size) {
  std::vector<std::unique_ptr<int>> ptrs(size);

  // Memory allocation
  for (auto& ptr : ptrs) {
    ptr = std::make_unique<int>();
  }

  // No need to manually deallocate memory
}

} // namespace Test01
