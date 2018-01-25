#pragma once

namespace tndev {
namespace octree {

template <typename T>
inline cell<T>::cell(const glm::vec3 &pos, float size, size_t level,
                     cell *parent)
    : pos(pos), pos2(pos + size), center(pos + size / 2.f), size(size),
      level(level), parent(parent){};

template <typename T> inline bool cell<T>::push_back(const T &obj) {
  return push_back(
      obj, [](const auto &c) { return c.elements.size() > 10 && c.level < 4; });
}

template <typename T>
inline bool
cell<T>::push_back(const T &obj,
                   const std::function<bool(const cell<T> &)> &split_cond) {

  auto objPos = get_position(obj);
  if (is_point_in_cell(this, objPos)) {

    if (cells.size() > 0) {
      auto idx = get_cell_idx(this, objPos);

      if (cells[idx.first] == nullptr) {
        cells[idx.first] = std::make_unique<cell<T>>(
            pos + glm::vec3(idx.second.x, idx.second.y, idx.second.z) *
                      (size / 2.f),
            (size / 2.f), level + 1, this);
      }

      if (!cells[idx.first]->push_back(obj, split_cond)) {
        throw std::runtime_error("something went totally wrong");
      }

      return true;
    } else {
      if (split_cond(*this)) {
        cells.resize(8);
        std::vector<T> oldElements;
        oldElements.swap(elements);

        for (const auto &elm : oldElements) {
          push_back(elm, split_cond);
        }

        push_back(obj, split_cond);
        return true;
      } else {
        elements.push_back(obj);
        return true;
      }
    }

  } else {
    return false;
  }
}

} // namespace octree
} // namespace tndev