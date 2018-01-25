#include <vector>

namespace tndev {
namespace octree {

template <typename T>
inline std::vector<cell<T> *>
find_adjacent_same_level_cells(const octree<T> &octree, cell<T> *refCell) {
  std::vector<cell<T> *> cells;

  return cells;
}

template <typename T>
inline std::vector<cell<T> *>
find_adjacent_same_level_cells(const octree<T> &octree, glm::vec3 refPoint) {
  std::vector<cell<T> *> cells;

  return cells;
}

template <typename T>
inline bool is_point_in_cell(cell<T> *cell, const glm::vec3 &point) {
  auto min = glm::vec3();
  auto max = glm::vec3();
  for (size_t i = 0; i < 3; i++) {
    min[i] = std::min(cell->pos[i], cell->pos2[i]);
    max[i] = std::max(cell->pos[i], cell->pos2[i]);
  }

  if (glm::all(glm::greaterThanEqual(point, min)) &&
      glm::all(glm::lessThanEqual(point, max))) {
    return true;
  } else {
    return false;
  }
}

template <typename T>
inline std::pair<size_t, glm::ivec3> get_cell_idx(cell<T> *cell,
                                                  const glm::vec3 &point) {
  auto min = cell->pos;
  auto max = cell->pos2;
  // determin cell to insert

  auto tmp = (point - min) / cell->size * 2.f;
  size_t x = std::max(std::min(static_cast<int>(std::floor(tmp.x)), 1), 0);
  size_t y = std::max(std::min(static_cast<int>(std::floor(tmp.y)), 1), 0);
  size_t z = std::max(std::min(static_cast<int>(std::floor(tmp.z)), 1), 0);

  size_t idx = (x + 2 * y + 4 * z);

  return std::make_pair(idx, glm::ivec3(x, y, z));
}

template <typename T>
inline cell<T> *find_cell(const octree<T> &octree, const glm::vec3 &point) {
  auto curr = octree.root.get();

  if (!is_point_in_cell(curr, point)) {
    return nullptr;
  }

  while (curr->cells.size() > 0) {

    auto found = std::find_if(
        curr->cells.begin(), curr->cells.end(), [&point](auto &cell) {
          return cell != nullptr && is_point_in_cell(cell.get(), point);
        });

    if (found != curr->cells.end()) {
      curr = (*found).get();
    } else {
      break;
    }
  }

  return curr;
}

} // namespace octree
} // namespace tndev