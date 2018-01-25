#pragma once

#include <algorithm>
#include <memory>
#include <vector>

namespace tndev {
namespace octree {

template<typename T>
struct octree;

template<typename T>
struct cell;

template <typename T> glm::vec3 get_position(const T &obj);
template <typename T> glm::vec3 get_size(const T &obj);


template <typename T>
inline std::vector<cell<T> *> find_adjacent_same_level_cells(const octree<T> &octree,
                                                      cell<T> * refCell);

template <typename T>
inline std::vector<cell<T> *> find_adjacent_same_level_cells(const octree<T> &octree,
                                                      glm::vec3 refPoint);

template <typename T>
inline bool is_point_in_cell(cell<T> *cell, const glm::vec3 &point);

template <typename T>
inline std::pair<size_t, glm::ivec3> get_cell_idx(cell<T> *cell,
                                           const glm::vec3 &point);

template <typename T>
inline cell<T> *find_cell(const octree<T> &octree, const glm::vec3 &point);

} // namespace octree
} // namespace tndev

#include <tndev/octree/octree.hpp>
#include <tndev/octree/helper.inl>