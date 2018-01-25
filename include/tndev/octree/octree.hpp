#pragma once

#include <functional>
#include <glm/glm.hpp>
#include <memory>
#include <vector>

#include <tndev/octree/cell.hpp>

namespace tndev {
namespace octree {

template <typename T> struct octree {

  octree(const glm::vec3 &pos, float size)
      : root(std::make_unique<cell<T>>(pos, size, 0, nullptr)) {}

  void push_back(const T &obj) { root->push_back(obj); }

  std::unique_ptr<cell<T>> root;

  // std::vector / any container with push_back that holds all elements
};
} // namespace octree
} // namespace tndev