#pragma once

#include <glm/glm.hpp>
#include <vector>

#include <tndev/octree/helper.hpp>

namespace tndev {
namespace octree {

template <typename T> struct cell;

template <typename T>
bool is_point_in_cell(cell<T> *cell, const glm::vec3 &point);

template <typename T>
std::pair<size_t, glm::ivec3> get_cell_idx(cell<T> *cell,
                                           const glm::vec3 &point);

template <typename T> struct cell {

  cell(const glm::vec3 &pos, float size, size_t level, cell *parent);

  bool push_back(const T &obj);

  bool push_back(const T &obj,
                 const std::function<bool(const cell<T> &)> &split_cond);

  const glm::vec3 pos;
  const glm::vec3 pos2;
  const glm::vec3 center;
  const float size;
  const size_t level;
  const cell *parent;

  std::vector<T> elements;
  std::vector<std::unique_ptr<cell<T>>> cells;
};
} // namespace octree
} // namespace tndev

#include <tndev/octree/cell.inl>